#include <iostream>
using namespace std;

class VariableFrontQueue{
	int size;
	int *arr;
	int rear;
	int front;
	
	public:
		VariableFrontQueue(){
			arr = new int[10];
			size = 10;
			rear = 0;
			front = 0;
		}
		VariableFrontQueue(int s){
			size = s;
			arr = new int[size];
			rear = 0;
			front = 0;
		}
		void Enqueue(int value){
			arr[rear] = value;
			rear++;
		}
		void Dequeue(){
			front++;
		}
		int getFirst(){
			return arr[front];
		}
		bool isEmpty(){
			return (front==rear);
		}
		bool isFull(){
			return (front==0 && rear==size);
		}
		void display(){
			for(int i=0; i<rear; i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	VariableFrontQueue s(10);
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
