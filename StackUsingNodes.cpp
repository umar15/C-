#include <iostream>
using namespace std;

class sNode{
	public:
		sNode * next;
		int value;
	
};

class StackUsingNodes{
	private:
		sNode *top;
	public:
		StackUsingNodes (){
			top=NULL;
		}
		void push(int v){
			sNode *a = new sNode();
			a->value = v;
			a->next = top;
			top = a;
		}
		
		int peek(){
			if(top!=NULL){
				return top->value;
			}
			else{
				cout<<"No Value.";
			}
		}
		void pop(){
			if(top!=NULL){
				top = top->next;
			}
		}
};

int main(){
	StackUsingNodes a;
	a.push(1);
	a.push(5);
	a.push(990);
	cout<<a.peek()<<endl;
	a.pop();
	cout<<a.peek()<<endl;
	return 0;
}
