#include <iostream>
#include "dNode.h"

using namespace std;

class SingleDoubleGround{
	private:
		dNode *head;
	public:
		SingleDoubleGround(){
			head=NULL;
		}
		void addAtStart(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
			}
			else{
				n->next = head;
				head->previous = n;
				head = n;
			}
		}
		
		void addAtEnd(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
			}
			else{
				dNode *last = head;
				while(last->next!=NULL){
					last = last->next;
				}
				last->next = n;
				n->previous = last;
				
			}
		}
		
		void Remove(int v){
			dNode *P, *D;   //P: for previous and D: for deletion
			P=D=head;
			if(head==NULL){
				cout<<"No data in the list."<<endl;
				return;
			}
			while(D!=NULL && D->value!=v){
				P=D;
				D=D->next;
			}
			if(D==NULL){
				cout<<"Given value in not in the list."<<endl;
				return;
			}
			else if(D==head){
				head = head->next;
				head->next->previous = head;
			}
			else{
				P->next = D->next;
				D->next->previous = P;
			}
			delete D;
		}
		void display(){
			dNode *d = head;
			while(d->next!=NULL){
				cout<<d->value<<" ";
				d=d->next;
			}
		}
};

int main(){
	SingleDoubleGround d;
	d.addAtStart(34);
	d.addAtEnd(45);
	d.addAtStart(23);
	d.addAtStart(12);
	d.addAtStart(78);
	d.addAtEnd(00);
	d.addAtEnd(1);
	cout<<"\n";
	d.display();
	cout<<"\n";
	d.Remove(45);
	d.display();
}
