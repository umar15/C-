#include <iostream>
#include "NodeClass.h"

using namespace std;
//This linked list is double Ended Singly Linked circular.
class DoubleSingleCircular{
	private:
		Node * head;
		Node * tail;
	public:
		DoubleSingleCircular(){
			head=NULL;
			tail=NULL;
		}
		void addAtStart(int v){
			Node *a = new Node();
			a->value = v;
			if(head==NULL){
				head = a;
				tail = a;
				tail->next = head;
			}
			else{
				Node *last = head;
				while(last->next!=head){
					last=last->next;
				}
				a->next = head;
				tail = last;
				tail->next = a;
				head = a;
			}
			
		}
		void addAtEnd(int v){
			Node * n = new Node();
			n->value = v;
			if(head==NULL){
				head=n;
				tail=n;
				tail->next=head;
			}
			else{
				Node *last = head;
				while(last->next!=head){
					last=last->next;
				}
				last->next = n;
				tail = n;
				tail->next = head;
				
			}
		}
		void Remove(int v){
			Node *P, *D;
			P=D=head;
			if(head==NULL){
				cout<<"No Value !";
				return;
			}
			while(D!=NULL && D->value!=v){
				P=D;
				D=D->next;
			}
			if(D==NULL){
				cout<<"Value not in the list"<<endl;
				return;
			}
			if(D==head){
				head=head->next;
				tail->next = head;
			}
			else{
				P->next = D->next;
				if(P->next==NULL){
					tail = P;
					tail->next=head;
				}	
			}
			delete D;
			
		}
		
		void display(){
			Node *c = head;
			do{
				cout<<c->value<<" ";
				c = c->next;
			}while(c!=head);
			
		}
};

int main(){
	DoubleSingleCircular s;
	s.addAtStart(23);
	s.addAtStart(2);
	s.addAtStart(0);
	s.addAtEnd(2);
	s.addAtStart(3);
	s.addAtEnd(5);
	//s.display();
	s.Remove(5);
	cout<<endl;
	s.display();
	return 0;
}
