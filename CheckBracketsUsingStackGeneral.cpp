#include <iostream>
#include "StackClass.h"

using namespace std;

int main(){
	Stack s;
	string x = "[{x+y+(x-y)}/2]";
	int i;
	for(i=0; i<x.length(); i++){
		char ch = x[i];
		switch(ch){
			case '[':
			case '{':
			case '(':
				s.push(ch);
				cout<<"\n"<<ch<<" is pushed to stack";
				break;
			case ')':{
				if(s.peek()!='('){
					cout<<"\n"<<ch<<" Not matching input.";	
				}
				else{
					s.pop();
					cout<<"\n"<<ch<<" Removed from stack.";						
				}
				break;
			}
			case '}':{
				if(s.peek()!='{'){
					cout<<"\n"<<ch<<" Not matching input.";	
				}
				else{
					s.pop();
					cout<<"\n"<<ch<<" Removed from stack.";						
					}
				break;
			}
			case ']':{
				if(s.peek()!='[' && !s.isEmpty()){
					cout<<"\n"<<ch<<" Not matching input.";	
				}
				else{
					s.pop();
					cout<<"\n"<<ch<<" Removed from stack.";						
					}
				break;
			}
			default:
				cout<<"\n Operator or operand.";
		}
	}
}
