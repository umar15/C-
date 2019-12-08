#include <iostream>
using namespace std;

class heapSort{
	private:
		int arr[10];
		int n;
	public:
		heapSort(){
			n=0;
		}
		void insert(int value){
			arr[n] = value;
			heapUpRecursive(n);
			n++;
		}
		void heapUpRecursive(int index){
			int parent, temp;
			if(index%2==0){
				parent = (index-2)/2;
			}
			else{
				parent = (index-1)/2;
			}
			if(parent<0){
				return;
			}
			if(arr[index]>arr[parent]){
				temp = arr[index];
				arr[index] = arr[parent];
				arr[parent] = temp;
				heapUpRecursive(parent);
			}
		}
		
		void heapUpIterative(int index){
			int parent, temp;
			while(parent>0){
				if(index%2==0){
					parent = (index-2)/2;
				}
				else{
					parent = (index-1)/2;
				}
				if(arr[parent]<arr[index]){
					temp = arr[parent];
					arr[parent] = arr[index];
					arr[index] = temp;
					index = parent;
				}
				else{
					break;
				}
			}
		}
		void remove(){
			n--;
			arr[0] = arr[n];
			heapDown(0);
		}
		
		void heapDown(int index){
			int left, right, temp, child;
			left = (2*index)+1;
			right = left+1;
			if(left<n){
				if(right<n){
					if(arr[left]>arr[right]){
						child = left;
					}
					else{
						child = right;
					}
				}
				child = left;
			}
			else{
				return;
			}
			temp = arr[child];
			arr[child] = arr[index];
			arr[index] = temp;
			heapDown(child);
		}
		int root(){
			return arr[0];
		}
		bool isEmpty(){
			return (n=0);
		}
		
		void display(){
			for(int i=0; i<n; i++){
				cout<<arr[i]<<" ";
			}
		}
};

int main(){
	heapSort h;
	h.insert(10);
	h.insert(20);
	h.insert(30);
	h.insert(40);
	h.insert(50);
	h.insert(60);
	cout<<"Root: "<<h.root()<<endl;
	h.display();
	h.remove();
	cout<<"Root: "<<h.root()<<endl;
	h.display();
}
