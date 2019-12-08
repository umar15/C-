#include <iostream>
using namespace std;

class CircularQueue{
	int arr[10], rear, front, count;
	
	public:
		CircularQueue(){
			rear = 0;
			front = 0;
			count = 0;
		}
		void Enqueue(int value){
			if(isFull()){
				return;
			}
			else{
				arr[rear] = value;
				rear++;
				rear%=10;
				count++;
			}
			
		}
		void Dequeue(){
			if(isEmpty()){
				return;
			}
			else{
				front++;
				front%=10;
				count--;
			}
			
		}
		int getFirst(){
			return arr[front];
		}
		bool isEmpty(){
			return (count==0);
		}
		bool isFull(){
			return (count==10);
		}
		int max(int arr[], int n){
			int m = arr[0];
			for(int i=1; i<n; i++){
				if(arr[i]>m){
					m=arr[i];
				}
			}
			return m;
		}
		
		void RadixSort(int arr[], int size){
			CircularQueue PQ[10];
			int Maximum = max(arr, size);
			int digits = 0;
			int div = 1;
			int d;
			cout<<"Before Sorting"<<endl;
			for(int i=0; i<size; i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			
			while(Maximum>0){   // this loop will return total passes.
				Maximum=Maximum/10;
				digits++;
			}
			
			for(int priority=1; priority<=digits; priority++){
				for(int i=0; i<size; i++){
					d = (arr[i] / div) % 10;  //this loop makes priority queue.
					PQ[d].Enqueue(arr[i]);
				}
				int j=0;
				for(int k=0; k<size; k++){
					while (!PQ[k].isEmpty()){
						arr[j] = PQ[k].getFirst();
						j++;
						PQ[k].Dequeue();
					}
					
				}
				div *= 10;
				
			}
			cout<<"After Sorting."<<endl;
			for(int i=0; i<size; i++){
				cout<<arr[i]<<" ";
			}	
			
	}	
};


int main(){
	CircularQueue c;
	int size = 10;
	int arr1[] = {125, 240, 215, 626, 923, 721, 218, 322, 126, 25};
	c.RadixSort(arr1, size);
	
	return 0;
}

