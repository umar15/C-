#include <iostream>
#include "StackClass.h"
using namespace std;

int main(){
	Stack s;
	string x = "{(x+y)}";
	int i;
	for(i=0; i<x.length(); i++){
		char ch = x[i];
		switch(ch){
			case '{':
			case '(':
				s.push(ch);
				cout<<"\n"<<ch<<" is pushed to stack.";
				break;
			
			
			case ')':{
				if(s.peek()!='('){
					cout<<"\nNot matching with "<<ch;
				}
				else{
					s.pop();
					cout<<"\n"<<ch<<" Removed from stack.";
				}	
				break;
			}
			case '}':{
				if(s.peek()!='{' && !s.isEmpty()){
					cout<<"\nNot matching with "<<ch;
				}
				else{
					s.pop();
					cout<<"\n"<<ch<<" Removed from stack.";
				}		
				break;	
			}
			
			default:{
				cout<<"\nOperator or operand.";
			}
			
		}
	}
	return 0;
}
