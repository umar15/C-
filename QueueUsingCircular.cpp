#include <iostream>
using namespace std;

class CircularQueue{
	int size, *arr, rear, front, count;
	
	public:
		CircularQueue(){
			arr = new int[10];
			size = 10;
			rear = 0;
			front = 0;
			count = 0;
		}
		CircularQueue(int s){
			size = s;
			arr = new int[size];
			rear = 0;
			front = 0;
			count = 0;
		}
		void Enqueue(int value){
			if(!isFull()){
				arr[rear] = value;
				rear++;
				rear%=size;
				count++;
			}
			
		}
		void Dequeue(){
			if(!isEmpty()){
				front++;
				front%=size;
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
			return (count==size);
		}
		bool emptyWithoutCount(){
			return (front==rear);
		}
		
		bool fullWithoutCount(){
			
		}
		int next(int n){
			return (n+1)%size;
		}
};

int main(){
	CircularQueue s(10);
	s.Enqueue(20);
	s.Enqueue(30);
	s.Enqueue(35);
	s.Enqueue(40);
	s.Enqueue(60);
	cout<<"The first element is: "<<s.getFirst()<<endl;
	s.Dequeue();
	s.Enqueue(70);
	cout<<"The new first element is: "<<s.getFirst()<<endl;
	return 0;
}   
