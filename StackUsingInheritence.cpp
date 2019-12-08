#include <iostream>
#include "NodeClass.h"
using namespace std;

class SingleSingleGround{
	protected:
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
				delete D;
			}
			
		}
		
		void display(){
			Node *c = head;
			while(c!=NULL){
				cout<<c->value<<" ";
				c = c->next;
			}
		}
		
		int getFirst(){
			return head->value;
		}
};

class StackUsingInheritence: SingleSingleGround{
	public:
		void push(int v){
			addAtStart(v);
		}
		int peek(){
			if(head!=NULL){
				getFirst();
			}
			else{
				cout<<"No value in the list!";
			}	
		}
		void pop(){
			if(head!=NULL){
				Remove(getFirst());
			}
			else{
				cout<<"No value in the list!";
			}	
		}
};

int main(){
	StackUsingInheritence a;
	a.push(0);
	a.push(80);
	a.push(1000);
	cout<<a.peek()<<endl;
	a.pop();
	cout<<a.peek()<<endl;
	return 0;
	
}
