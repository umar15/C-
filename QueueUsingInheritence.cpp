#include <iostream>
using namespace std;

class Node{
	public:
		Node *next;
		int value;
	
};

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
		
		void addAtEnd(int v){
			Node *n = new Node();
			n->value = v;
			if(head==NULL){
				head = n;
			}
			else{
				Node *last = head;
				while(last->next!=NULL){
					last = last->next;
				}
				last->next = n;
			}
			
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
		
		int getHead(){
			return head->value;
		}

};

class QueueUsingInheritence: SingleSingleGround{
	public:
		void Enqueue(int value){
			addAtEnd(value);
		}
		void Dequeue(){
			Remove(getHead());
		}
		int getFirst(){
			return getHead();
		}
		void Display(){
			display();
		}
		
};

int main(){
	QueueUsingInheritence q;
	q.Enqueue(40);
	q.Enqueue(50);
	q.Enqueue(60);
	q.Enqueue(70);
	q.Dequeue();
	q.Display();
	return -1;
}
