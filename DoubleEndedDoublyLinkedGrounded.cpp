#include <iostream>
#include "dNode.h"
using namespace std;

class DoubleDoubleGround{
	private:
		dNode *head;
		dNode *tail;
	public:
		DoubleDoubleGround(){
			head = NULL;
			tail = NULL;
		}
		void addAtStart(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
				tail = n;
			}
			else{
				n->next = head;
				head->previous = n;
				head = n;
				dNode *last = head;
				while(last->next==NULL){
					last = last->next;
				}
				tail = last;
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
			if(D==head){
				head = head->next;
				head->next->previous = head;
			}
			if(D->next==NULL){
				tail = P;
			}
			else{
				P->next = D->next;
				D->next->previous = P;
			}
			delete D;
		}
		
		void display(){
			dNode *d = head;
			while(d!=NULL){
				cout<<d->value<<" ";
				d=d->next;
			}
					
		}
};

int main(){
	DoubleDoubleGround d;
	d.addAtStart(10);
	d.addAtStart(20);
	d.addAtStart(30);
	d.addAtStart(40);
	d.display();
	d.Remove(30);
	cout<<endl;
	d.display();
	return 0;
}
