#include <iostream>
#include "NodeClass.h"
using namespace std;

class SingleSingleGround{
	private:
		Node *head; 
	public:
		SingleSingleGround(){head = NULL;}
		
		void addAtStart(int v){
			Node *a = new Node();
			a->value = v;
			a->next = head;
			head = a;
		}
	
		void Remove(int v){
			Node *P, *D;  //P: Previous and D: Deletion
			P=D=head;
			if (head==NULL){
				cout<<"NO data in the list !"<<endl;
				return;
			}
			while(D!=NULL && D->value != v){
				P=D;
				D = D->next;
			}
			if(D==NULL){
				cout<<"Given value is not in the list"<<endl;
				return;
			}
			else if(D==head){
				head = head->next;
			}
			else{
				P->next = D->next;
				
			}
			delete D;
			
		}
		
		void display(){
			Node *c = head;
			while(c!=NULL){
				cout<<c->value<<" ";
				c = c->next;
			}
		}
		int getHead(){
			return head->value;
		}
};

class StackUsingComposition{
	private:
		SingleSingleGround s;
	public:
		void push(int v){
			s.addAtStart(v);
		}
		int peek(){
			if(s.getHead()!=NULL){
				s.getHead();
			}
			else{
				cout<<"No value in the list!";
			}	
		}
		void pop(){
			if(s.getHead()!=NULL){
				s.Remove(s.getHead());
			}
			else{
				cout<<"No value in the list!";
			}
			
		}
		
};

int main(){
	StackUsingComposition a;
	a.push(100);
	a.push(300);
	a.push(60);
	cout<<a.peek()<<endl;
	a.pop();
	cout<<a.peek()<<endl;
	return 0;
	
}
