#include <iostream>
#include "dNode.h"
using namespace std;

class SingleDoubleCircular{
	private:
		dNode *head;
	public:
		SingleDoubleCircular(){
			head=NULL;
		}
		void addAtStart(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
				n->next = head;
				n->previous = head;
				
			}
			else{
					
				dNode *last = head;
				while(last->next!=head){
					last = last->next;
				}
				n->next = head;
				last->next = n;
				head->previous = n;
				head = n;
			}
		}
		void addAtEnd(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
				n->next = head;
				n->previous = head;
			}
			else{
				dNode *last = head;
				while(last->next!=head){
					last=last->next;
				}
				last->next = n;
				n->previous = last;
				n->next = head;
				head->previous = n;
				
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
				P->next = head;
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
	SingleDoubleCircular c;
	c.addAtStart(20);
	c.addAtStart(40);
	c.addAtStart(30);
	c.addAtStart(90);
	c.addAtEnd(100);
	//c.display();
	c.Remove(20);
	c.display();
	return 0;
}
