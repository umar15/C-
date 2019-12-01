#include <iostream>
#include "dNode.h"
using namespace std;

class DoubleDoubleCircular{
	private:
		dNode *head;
		dNode *tail;
	public:
		DoubleDoubleCircular(){
			head = NULL;
			tail = NULL;
		}
		void addAtStart(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
				tail = n;
				tail->next = head;
				tail->previous = head;
			}
			else{
				dNode *last = head;
				while(last->next!=head){
					last = last->next;
				}
				n->next = head;
				head->previous = n;
				tail = last;
				tail->next = n;
				head = n;
			}
		}
		void addAtEnd(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
				tail = n;
				tail->next = head;
				tail->previous = head;
				
			}
			else{
				dNode *last = head;
				while(last->next!=head){
					last=last->next;
				}
				last->next = n;
				tail = n;
				tail->previous = last;
				tail->next = head;
				head->previous = tail;
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
			else if(D->next==head){
				tail = P;
				tail->next = head;
			}
			else{
				P->next = D->next;
				D->next->previous = P;
			}
			delete D;
		}
		
		void display(){
			dNode *d = head;
			do{
				cout<<d->value<<" ";
				d=d->next;
			}while(d!=head);
					
		}
};

int main(){
	DoubleDoubleCircular d;
	d.addAtStart(10);
	d.addAtStart(20);
	d.addAtStart(30);
	d.addAtStart(40);
	d.addAtEnd(50);
	d.Remove(10);
	d.display();
	return 0;
}


