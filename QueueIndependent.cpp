#include <iostream>
using namespace std;

class Node{
	public:
		Node * next;
		int value;
};

class IndependentQueue{
	private:
		Node *front, *rear;
	public:
		IndependentQueue(){
			front=rear=NULL;
		}
		void Enqueue(int v){
			Node *n = new Node();
			n->value = v;
			n->next = NULL;
			if(front==NULL && rear==NULL){
				front = rear = n;
			}
			else{
				rear->next = n;
				rear = n;
			}
			
		}
		void Dequeue(){
			front = front->next;
		}
		bool isEmpty(){
			return (front==NULL && rear==NULL);
		}
		void display(){
			Node *c = front;
			while(c!=NULL){
				cout<<c->value<<" ";
				c = c->next;
			}
		}
};

int main(){
	IndependentQueue q;
	if(q.isEmpty()){
		cout<<"Empty Queue."<<endl;
	}
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Dequeue();
	q.display();
	return -1;
}

