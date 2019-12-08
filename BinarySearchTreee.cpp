#include <iostream>
using namespace std;

class BNode{
	public:
		BNode * leftChild;
		BNode * rightChild;
		int value;
		
		BNode(){
			leftChild = NULL;
			rightChild = NULL;
		}
	
};
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

class BinarySearchTree{
	private:
		BNode * root;
	public:
		BinarySearchTree(){
			root = NULL;
		}
		
		void insert(int v){
			BNode * n = new BNode();
			n->value = v;
			if(root == NULL){
				root = n;
			}
			else{
				BNode * child = root;
				BNode * p = child;  //p: previous
				
				while(child != NULL){
					p = child;
					if(v < child->value){
						child = child->leftChild;
					}
					else{
						child = child->rightChild;
					}
				}
				if(n->value < p->value){
					p->leftChild = n;
				}
				else{
					p->rightChild = n;
				}
			}
		}
		void DisplayInOrder(){
			displayInOrder(root);
		}
		void DisplayPostOrder(){
			displayPostOrder(root);
		}
		void DisplayPreOrder(){
			displayPreOrder(root);
		}
		
		int Max(){
			BNode * c = root;
			BNode * p = c;
			while(c!=NULL){
				p = c;
				c = c->rightChild;
			}
			p = p->rightChild;
			return p->value;
				
		}
		int Min(){
			BNode * c = root;
			BNode * p = c;
			while(c!=NULL){
				p = c;
				c = c->leftChild;
			}
			p = p->leftChild;
			return p->value;
				
		}
		
		void displayLevelVise(){
			IndependentQueue q;
			q.Enqueue(root);
			BNode * a;
			while(!q.isEmpty()){
				a = q.Dequeue();
				cout<<a->value<<" ";
				if(a->leftChild != NULL){
					q.Enqueue(a->leftChild);
				}
				if(a->rightChild != NULL){
					q.Enqueue(a->rightChild);
				}
			}
		}
		
	private:		
		void displayInOrder(Node *a){
			if(root == NULL){
				return;
			}
			else{
				displayInOrder(a->leftChild);
				cout<<a->value<<" ";
				displayInOrder(a->rightChild);
			}
			
		}
		void displayPreOrder(Node *a){
			if(root == NULL){
				return;
			}
			else{
				cout<<a->value<<" ";
				displayInOrder(a->leftChild);
				displayInOrder(a->rightChild);
			}
			
		}
		void displayPostOrder(Node *a){
			if(root == NULL){
				return;
			}
			else{
				displayInOrder(a->leftChild);
				displayInOrder(a->rightChild);
				cout<<a->value<<" ";
			}
			
		}
		
		
		
};
int main(){
	BinarySearchTree b;
	b.insert(50);
	b.insert(60);
	b.insert(40);
	b.insert(70);
	b.insert(20);
	b.insert(80);
	b.insert(50);
	b.displayLevelVise();
	
	return -1;
} 
