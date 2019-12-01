#include <iostream>
using namespace std;

// Node class for binary search tree
class Node{
	public:
		Node * leftChild;
		Node * rightChild;
		int value;
		
		Node(){
			leftChild = NULL;
			rightChild = NULL;
		}
	
};
// Node class for queue
class qNode{
	public:
		qNode * next;
		int value;
};

class IndependentQueue{
	private:
		qNode *front, *rear;
	public:
		IndependentQueue(){
			front=rear=NULL;
		}
		void Enqueue(int v){
			qNode *n = new qNode();
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
};

//Class Binary search tree
class BinarySearchTree{
	private:
		Node * root;
	public:
		BinarySearchTree(){
			root = NULL;
		}
		
		void insert(int v){
			Node * n = new Node();
			n->value = v;
			if(root == NULL){
				root = n;
			}
			else{
				Node * child = root;
				Node * p = child;  //p: previous
				
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
		void displayLevelVise(){
			IndependentQueue *q;
			q->Enqueue(root->value);
			int a;
			Node *n = root;
			while(!q->isEmpty()){
				a = q->Dequeue();
				cout<<a<<" ";
				
				if(n->leftChild != NULL){
					n = n->leftChild;
					q->Enqueue(n->value);
				}
				if(n->rightChild != NULL){
					n = n->rightChild;
					q->Enqueue(n->value);
				}
			}
		}
		
};

// Main method
int main(){
	BinarySearchTree t;
	t.insert(50);
	t.insert(30);
	t.insert(60);
	t.insert(20);
	t.insert(40);
	t.insert(55);
	t.insert(90);
	
	t.displayLevelVise();
	return -1;
	
}
