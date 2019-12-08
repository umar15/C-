#include <iostream>
#include "StackClass.h"
using namespace std;

string infixToPrefix(string infix){
	Stack s;
	string reverse = " ";
	string prefixFinal = " ";
	string prefix = " ";
	for(int i=infix.length()-1; i>=0; i--){
		reverse+=infix[i];
	}
	
	char ch;
	for(int j=0; j<reverse.length(); j++){
		ch = reverse[j];
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
			prefix+=ch;
		}
		else if(ch==')'){
			s.push(ch);
		}
		else if(ch=='('){
			while(s.peek()!=')'){
				prefix+=s.peek();
				s.pop();
			}
			s.pop();
		}
		else{
			while(!s.isEmpty() && s.peek()!=')' && s.Prescedence(s.peek())>s.Prescedence(ch)){
				prefix+=s.peek();
				s.pop();
			}
			s.push(ch);
		}
		
	}
	while(!s.isEmpty()){
		prefix+=s.peek();
		s.pop();
	}
	for(int k=prefix.length()-1; k>=0; k--){
		prefixFinal += prefix[k];
	}
	
	return prefixFinal;
}

int SolutionInfixToPretfix(string prefix){
	Stack s;
	int a, b, result;
	string reverse = " ";
	for(int i=prefix.length()-1; i>=0; i--){
		reverse+=prefix[i];
	}
	
	int ch;
	for(int x=0; x<reverse.length(); x++){
		ch = reverse[x];
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
	string st = "(2+14)/2";
	string s = infixToPrefix(st);
	cout<<s<<"\n";
	int x = SolutionInfixToPretfix(s);
	cout<<x;
}
