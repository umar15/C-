#include <iostream>
using namespace std;


class Stack{
	private:
		int size;
		int Arr[size];
		int top;
		int bottom;
	public:
		Stack(int n){
		top = 0;
		bottom = n-1;
		}
		
		//Methods for stack 1
		void push(int value){
			Arr[top] = value;
			top++;
		}
		void pop(){
			if(top>0){
				top--;
			}			
		}
		int peek(){
			if(top<10){
				return Arr[top-1];
			}
		}
		
		// Methods for stack 2
		void pushS(int value){
			Arr[bottom] = value;
			bottom--;
		}
		int peekS(){
			if(bottom>0){
				return Arr[bottom+1];
			}
		}
		void popS(){
			if(bottom<9){
				bottom++;
			}			
		}
		
		
		bool isEmpty(){
			return top==0;
		}
		int Prescedence(char sign){
			if(sign=='+' || sign=='-') {
				return 0;
			}
			else if(sign=='*' || sign=='/'){
				return 1;
			}
			else if(sign=='^'){
				return 2;
			}
			else{
				return -1;
			}
}
		
};

int main(){
	Stack s;
	s.push(20);
	s.pushS(30);
	s.push(10);
	s.pushS(40);
	s.push(50);
	s.pushS(60);
	s.push(70);
	s.pushS(0);
	cout<<"Stack 1"<<endl;
	cout<<s.peek()<<endl;
	s.pop();
	cout<<s.peek()<<endl;
	
	cout<<endl<<"Stack 2"<<endl;
	cout<<s.peekS()<<endl;
	s.popS();
	cout<<s.peekS()<<endl;
	return -1;
}
