#include <iostream>
#include "NodeClass.h"

using namespace std;
//This linked list is Single Ended Singly Linked Grounded.
class DoubleSingleGrounded{
	private:
		Node * head;
		Node * tail;
	public:
		DoubleSingleGrounded(){
			head=NULL;
			tail=NULL;
		}
		void addAtStart(int v){
			Node *a = new Node();
			a->value = v;
			if(head==NULL){
				head = a;
				tail = a;
			}
			else{
				a->next = head;
				head = a;
				Node *last = head;
				while(last->next!=NULL){
					last=last->next;
				}
				tail = last;
			}
			
		}
		void addAtEnd(int v){
			Node * n = new Node();
			n->value = v;
			if(head==NULL){
				head=n;
				tail=n;
			}
			else{
				Node *last = head;
				while(last->next!=NULL){
					last=last->next;
				}
				last->next = n;
				tail = n;
				
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
			}
			else{
				P->next = D->next;
				if(P->next==NULL){
					tail = P;
				}	
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
};

int main(){
	DoubleSingleGrounded s;
	s.addAtStart(23);
	s.addAtStart(2);
	s.addAtStart(0);
	s.addAtEnd(2);
	s.addAtStart(3);
	s.addAtEnd(5);
	s.display();
	s.Remove(5);
	cout<<endl;
	s.display();
	return 0;
}
