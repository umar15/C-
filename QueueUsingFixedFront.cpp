#include <iostream>
using namespace std;

class FixedFrontQueue{
	int size;
	int *arr;
	int rear;
	
	public:
		FixedFrontQueue(){
			arr = new int[10];
			size = 10;
			rear = 0;
		}
		FixedFrontQueue(int s){
			size = s;
			arr = new int[size];
			rear = 0;
		}
		void Enqueue(int value){
			arr[rear] = value;
			rear++;
		}
		void Dequeue(){
			int i=1;
			for(i; i<rear; i++){
				arr[i-1] = arr[i];
			}
		}
		int getFirst(){
			return arr[0];
		}
		bool isEmpty(){
			return (rear==0);
		}
		bool isFull(){
			return (rear==size);
		}
		void display(){
			for(int i=0; i<rear; i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	FixedFrontQueue s(10);
	s.Enqueue(20);
	s.Enqueue(30);
	s.Enqueue(35);
	s.Enqueue(40);
	s.Enqueue(60);
	s.display();
	cout<<"The first element is: "<<s.getFirst()<<endl;
	s.Dequeue();
	s.Enqueue(70);
	s.display();
	cout<<"The new first element is: "<<s.getFirst()<<endl;
	return 0;
}
