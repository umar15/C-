#include <iostream>
#include <stack>
#include <queue>
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

//Class Binary search tree
class BinarySearchTree{
	private:
		Node * root;
		
		void DIO(Node *a){
			if(root == NULL){
				return;
			}
			else{
				DIO(a->leftChild);
				cout<<a->value<<" ";
				DIO(a->rightChild);
			}
			
		}
		void DPreO(Node *a){
			if(root == NULL){
				return;
			}
			else{
				cout<<a->value<<" ";
				DPreO(a->leftChild);
				DPreO(a->rightChild);
			}
			
		}
		void DPostO(Node *a){
			if(root == NULL){
				return;
			}
			else{
				DPostO(a->leftChild);
				DPostO(a->rightChild);
				cout<<a->value<<" ";
			}
			
		}
		
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
		// Iterative methods for traversal
		void displayLevelVise(){
			queue<Node *> q;
			q.push(root);
			Node * a;
			while(!q.empty()){
				a = q.front();
				q.pop();
				cout<<a->value<<" ";
				
				if(a->leftChild != NULL){
					q.push(a->leftChild);
				}
				if(a->rightChild != NULL){
					q.push(a->rightChild);
				}
			}
		}
		void displayInOrder(Node *c){
			stack<Node*> s;
			Node *temp = root;
			while(!s.empty() && temp!=NULL){
				if(temp==NULL){
					s.push(temp);
					temp = temp->leftChild;
				}
				else{
					temp = s.top();
					s.pop();
					cout<<temp->value<<" ";
					temp = temp->rightChild;
				}
			}
			
		}
		void displayInOrderIterative(){
			displayInOrder(root);
		}
		//Recursive methods for traversal
		void DisplayInOrder(){
			DIO(root);
		}
		void DisplayPostOrder(){
			DPostO(root);
		}
		void DisplayPreOrder(){
			DPreO(root);
		}
		
		int Max(){
			Node * c = root;
			while(c->rightChild!=NULL){
				c = c->rightChild;
			}
			return c->value;
				
		}
		int Min(){
			Node * c = root;
			while(c->leftChild!=NULL){
				c = c->leftChild;
			}
			return c->value;
				
		}
		
		bool Search(int v){
			Node *p = root;
			while(p != NULL){
				if(p->value==v){
					return true;
				}
				if(v<p->value){
					p = p->leftChild;
				}
				else{
					p = p->rightChild;
				}
			}
			return false;
		}
		
		void Remove(int v){
			Node *parent, *data;
			data = root;
			while(data->value != v && data!=NULL){
				parent = data;
				if(v < data->value){
					data = data->leftChild;
				}
				else{
					data = data->rightChild;
				}
				
			}
			if((data->leftChild == NULL) && (data->rightChild == NULL)){
				if(parent->leftChild == data){
					parent->leftChild = NULL;
				}	
				else{
					parent->rightChild = NULL;
				}
				delete parent;
			}
			/*
			else if((data->leftChild != NULL) || (data->rightChild != NULL)){
				if(parent->leftChild == data){
					if(data->leftChild != NULL){
						parent->leftChild = data->leftChild;
					}
					else{
						parent->leftChild = data->rightChild;
					}
				}
				else{
					if(data->leftChild != NULL){
						parent->rightChild = data->leftChild;
					}
					else{
						parent->rightChild = data->rightChild;
					}
				}
				delete parent;
			}
			*/
			
			
		}
	
};

// Main method
int main(){
	BinarySearchTree t;
	t.insert(60);
	t.insert(40);
	t.insert(100);
	t.insert(20);
	t.insert(50);
	t.insert(90);
	t.insert(120);
	t.insert(30);
	t.Remove(30);
	t.displayInOrderIterative();
	return -1;
	
}
