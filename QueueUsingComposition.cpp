#include <iostream>
using namespace std;

class Node{
	public:
		Node *next;
		int value;
	
};

class SingleSingleGround{
	private:
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

class QueueUsingComposition{
	private:
		SingleSingleGround s;
	public:
		void Enqueue(int value){
			s.addAtEnd(value);
		}
		void Dequeue(){
			s.Remove(s.getHead());
		}
		int getFirst(){
			return s.getHead();
		}
		bool isEmpty(){
			return (head==NULL);
		}
		void display(){
			s.display();
		}
		
};

int main(){
	QueueUsingComposition q;
	q.Enqueue(40);
	q.Enqueue(50);
	q.Enqueue(60);
	q.Enqueue(70);
	q.Dequeue();
	q.display();
	return -1;
}
