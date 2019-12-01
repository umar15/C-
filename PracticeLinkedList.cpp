#include <iostream>
#include "dNode.h"
#include "NodeClass.h"
using namespace std;

/*
class SingleSingleGrounded{
	private:
		Node * head;
	public:
		SingleSingleGrounded(){
			head=NULL;
		}
		void addAtStart(int v){
			Node *a = new Node();
			a->value = v;
			a->next = head;
			head = a;
		}
		void addAtEnd(int v){
			Node * n = new Node();
			n->value = v;
			if(head==NULL){
				head=n;
			}
			else{
				Node *h = head;
				while(h->next!=NULL){
					h=h->next;
				}
				h->next=n;
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
	SingleSingleGrounded s;
	s.addAtStart(23);
	s.addAtStart(2);
	s.addAtStart(0);
	s.addAtEnd(2);
	s.addAtStart(3);
	s.addAtEnd(5);
	s.display();
	s.Remove(2);
	cout<<endl;
	s.display();
	return 0;
}


class SingleSingleCircular{
	private:
		Node * head;
	public:
		SingleSingleGrounded(){
			head=NULL;
		}
		void addAtStart(int v){
			Node *a = new Node();
			a->value = v;
			if(head==NULL){
				head = a;
				head->next = head;
			}
			else{
				a->next = head;
				head = a;
				Node *h = head;
				while(h->next!=NULL){
					h=h->next;
				}
				h->next = head;
			}
			
		}
		void addAtEnd(int v){
			Node * n = new Node();
			n->value = v;
			if(head==NULL){
				head=n;
				head->next = head;
			}
			else{
				Node *h = head;
				while(h->next!=NULL){
					h=h->next;
				}
				h->next=n;
				n->next=head;
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
				Node *last = head;
				while(last->next!=NULL){
					last=last->next;
				}
				last->next = head;
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
			}while(n!=NULL);
		}
};

int main(){
	SingleSingleCircular s;
	s.addAtStart(23);
	s.addAtStart(2);
	s.addAtStart(0);
	s.addAtEnd(2);
	s.addAtStart(3);
	s.addAtEnd(5);
	s.display();
	s.Remove(2);
	cout<<endl;
	s.display();
	return -1;
}
/*

class DoubleSingleGrounded{
	private:
		Node * head;
		Node * tail;
	public:
		SingleSingleGrounded(){
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
	return -1;
}

/*

class DoubleSingleCircular{
	private:
		Node * head;
		Node * tail;
	public:
		SingleSingleGrounded(){
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
				a->next = head;
				head = a;
				Node *last = head;
				while(last->next!=NULL){
					last=last->next;
				}
				tail = last;
				tail->next = head;
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
				while(last->next!=NULL){
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
			Node *d = head;
			do{
				cout<<d->value<<" ";
				d = d->next;
			}while(d!=NULL);
			
		}
};

int main(){
	DoubleSingleCircular o;
	o.addAtStart(10);
	o.addAtStart(1);
	o.addAtStart(20);
	o.display();
	return 0;
}


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
				while(head->next!=NULL){
					last=last->next;
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
			while(d!=NULL){
				cout<<d->value<<" ";
				d=d->next;
			}
		}
};

int main(){
	SingleDoubleGround d;
	d.addAtEnd(1);
	d.addAtStart(2);
	d.addAtStart(3);
	d.display();
	d.Remove(3);
	cout<<endl;
	d.display();
	return 0;
}

/*
class SingleDoubleCircular{
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
				head->next = n;
			}
			else{
				n->next = head;
				head->previous = n;
				head = n;
				dNode *last = head;
				while(last->next==NULL){
					last = last->next;
				}
				last->next = head;
			}
		}
		void addAtEnd(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
				head->next = n;
			}
			else{
				dNode *last = head;
				while(head->next!=NULL){
					last=last->next;
				}
				last->next = n;
				n->previous = last;
				n->next = head;
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
			}while(d!=NULL);
					
		}
};

int main(){
	SingleDoubleCircular c;
	c.addAtStart(10);
	c.addAtEnd(2);
	c.addAtStart(0);
	c.addAtStart(30);
	c.addAtEnd(20);
	c.display();
	c.Remove(2);
	c.display();
	return 0;
}


class DoubleDoubleGround{
	private:
		dNode *head;
		dNode *tail;
	public:
		SingleDoubleGround(){
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
		void addAtEnd(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
				tail = n;
			}
			else{
				dNode *last = head;
				while(head->next!=NULL){
					last=last->next;
				}
				last->next = n;
				n->previous = last;
				tail = n;
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
	return 0;
}
*/

class DoubleDoubleCircular{
	private:
		dNode *head;
		dNode *tail;
	public:
		SingleDoubleGround(){
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
				tail->next = head;
			}
		}
		void addAtEnd(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				head = n;
				tail = n;
				tail->next = head;
				
			}
			else{
				dNode *last = head;
				while(head->next!=NULL){
					last=last->next;
				}
				last->next = n;
				n->previous = last;
				tail = n;
				tail->next = head;
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
	return 0;
}


