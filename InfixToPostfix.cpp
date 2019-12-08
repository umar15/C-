#include <iostream>
#include "StackClass.h"

using namespace std;
		
string InfixToPostfix(string infix){

	Stack s;
	string postfix = " ";
	char ch;
	
	for(int i=0; i<infix.length(); i++){
		ch = infix[i];
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
			postfix+=ch;
		}
		else if(ch=='('){
			s.push(ch);
		}
		else if(ch==')'){
			while (s.peek()!='('){
				postfix+=s.peek();
				s.pop();
			}
			s.pop();
		}
		else 
		{
			while ((!s.isEmpty() && s.peek()!='(' && s.Prescedence(s.peek())>=s.Prescedence(ch))){
				postfix+=s.peek();
				s.pop();
			}
			s.push(ch);
		}
	}
	while (!s.isEmpty()){
		postfix+=s.peek();
		s.pop();
	}
	return postfix;
}
int SolutionInfixToPostfix(string postfix){
	Stack s;
	int a, b, result;
	int ch;
	for(int x=0; x<postfix.length(); x++){
		ch = postfix[x];
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
			s.push(int(ch));
		}
		else if(ch=='+'){
			a = s.peek();
			s.pop();
			b = s.peek();
			s.pop();
			result = a+b;
			s.push(result);
		}
		else if(ch=='-'){
			a = s.peek();
			s.pop();
			b = s.peek();
			s.pop();
			result = b-a;
			s.push(result);
		}
		else if(ch=='*'){
			a = s.peek();
			s.pop();
			b = s.peek();
			s.pop();
			result = a*b;
			s.push(result);
		}
		else if(ch=='/'){
			a = s.peek();
			s.pop();
			b = s.peek();
			s.pop();
			result = a/b;
			s.push(result);
		}
		else if(ch=='^'){
			a = s.peek();
			s.pop();
			b = s.peek();
			s.pop();
			result = b^a;
			s.push(result);
		}
		else{
			continue;
		}
		
	}
	return result;
	
}
int main(){
	string st= "(2+2)/2";
	string s =InfixToPostfix(st);
	cout<<s<<"\n";
	int x = SolutionInfixToPostfix(s);
	cout<<x;
}
