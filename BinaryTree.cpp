#include <iostream>
using namespace std;

class BinaryTree{
	private:
		int BT[50];
		int index;
	public:
		BinaryTree(){
			index=0;
		}
		void insert(int value){
			
			BT[index] = value;
			index++;
		}
		void dislayLevelVise(){
			for(int i=0; i<index; i++){
				cout<<BT[i]<<" ";
			}
		}
		void displayInOrder(int p){ //p: Parent
			int leftChild = (2*p) + 1;
			int rightChild = (2*p) + 2;
			if(p>=index){
				return;
			}
			// LPR
			displayInOrder(leftChild);
			cout<<BT[p]<<" ";
			displayInOrder(rightChild);
			
		}
		void displayPostOrder(int p){
			int leftChild = (2*p) + 1;
			int rightChild = (2*p) + 2;
			if(p>=index){
				return;
			}
			// LRP
			displayPostOrder(leftChild);
			displayPostOrder(rightChild);
			cout<<BT[p]<<" ";
		}
		void displayPreOrder(int p){
			int leftChild = (2*p) + 1;
			int rightChild = (2*p) + 2;
			if(p>=index){
				return;
			}
			// PLR
			cout<<BT[p]<<" ";
			displayPreOrder(leftChild);
			displayPreOrder(rightChild);
		}
		void remove(){
			index--;
		}
		int grandFather(int v){
			int child;
			for(int i=2; i<index; i++){
				if(v==BT[i]){
					child = i;	
				}
				else{
					return -1;
				}
			}
			int p;  //p: Parent
			if(child%2==0){
				p = (child-2)/2;				
			}
			else{
				p = (child-1)/2;
			}
			
			int gp;   //gp: Grandparent
			if(p%2==0){
				gp = (p-2)/2;				
			}
			else{
				gp = (p-1)/2;
			}
			return BT[gp];
		}
		
		void maxHeap(int value){
			BT[index] = value;
			int c=index;
			index++;
			int parent;
			
			while(c>0){
				if(c%2==0){
					parent = (c-2)/2;
				}
				else{
					parent = (c-1)/2;
				}	
				
				if(BT[parent]<BT[c]){
					int temp = BT[parent];
					BT[parent] = BT[c];
					BT[c] = temp;
					c= parent;
				}
				else{
					break;
				}				
			}
		}
	
	
};

int main(){
	BinaryTree b;
	b.insert(10);
	b.insert(20);
	b.insert(30);
	b.insert(40);
	b.insert(50);
	b.insert(60);
	
	cout<<"Level vise: ";
	b.dislayLevelVise();
	cout<<endl;
	cout<<"In order: ";
	b.displayInOrder(0);
	cout<<endl;
	cout<<"Post order: ";
	b.displayPostOrder(0);
	cout<<endl;
	cout<<"Pre order: ";
	b.displayPreOrder(0);
	
	return 0;
 }
