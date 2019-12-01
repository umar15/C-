#include <iostream>
#include "NodeClass.h"

using namespace std;

class SingleSingleCircular{
	private:
		Node * head;
	public:
		SingleSingleCircular(){
			head = NULL;
		}
		void addAtStart(int v){
			Node *a = new Node();
			a->value = v;
			if(head==NULL){
				head = a;
				a->next = head;
			}
			else{
				Node *last = head;
				while(last->next != head){
					last=last->next;
				}
				a->next = head;
				last->next = a;
				head = a;
			}
			
		}
		void addAtEnd(int v){
			Node * n = new Node();
			n->value = v;
			if(head==NULL){
				head = n;
				n->next = head;
			}
			else{
				Node *last = head;
				while(last->next!=head){
					last=last->next;
				}
				last->next = n;
				n->next = head;
			}
		}
		void Remove(int v){
			Node *P, *D;
			P=D=head;
			if(head==NULL){
				cout<<"No Value !";
				return;
			}
			while(D->next!=head && D->value!=v){
				P=D;
				D=D->next;
			}
			if(D==NULL){
				cout<<"Value not in the list"<<endl;
				return;
			}
			if(D==head){
				head=head->next;
				Node *last = head;
				Node *temp;
				while(last->next!=head){
					temp = last;
					last=last->next;
				}
				temp->next = head;
			}
			else if(D->next==head){
				P->next = head;
			}
			else{
				P->next = D->next;
			}
			delete D;
		}
		
		void display(){
			Node * n = head;
			do{
				cout<<n->value<<" ";
				n=n->next;
			}while(n!=head);
		}
};

int main(){
	SingleSingleCircular s;
	s.addAtStart(0);
	s.addAtStart(10);
	s.addAtStart(40);
	s.addAtEnd(50);
	s.addAtEnd(30);
	s.addAtEnd(90);
	s.addAtEnd(50);
	s.Remove(40);
	cout<<endl;
	s.display();
	return 0;
}
