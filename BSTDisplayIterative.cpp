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
			Node *temp = c;
			while(!s.empty() || temp!=NULL){
				if(temp!=NULL){
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
		
		void displayPreOrder
		
	
};
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
	t.displayInOrderIterative();
	return -1;
	
}
