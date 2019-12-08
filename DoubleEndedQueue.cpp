#include <iostream>
using namespace std;

class deck{
	private:
		int size, front;
		int *arr;
	public:
		deck(){
			size = 10;
			arr = new int[size];
			front = 0;
		}
		deck(int s){
			size = s;
			arr = new int[size];
			front = 0;
		}
		void addAtStart(int value){
			if(front==0){
				arr[front] = value;
				front++;
			}
			else{
				for(int i=front; i>0; i--){
					arr[i] = arr[i-1];
				}
				arr[0] = value;
				front++;
			}
			
		}
		void addAtEnd(int value){
			arr[front] = value;
			front++;
		}
		void removeFromStart(){
			int i = 1;
			for(i; i<size; i++){
				arr[i-1] = arr[i];
			}
			front--;
		}
		void removeFromEnd(){
			front--;
		}
		int getFirst(){
			return arr[0];
		}
		int getLast(){
			return arr[front-1];
		}
		bool isFull(){
			return (front==0);
		}
		bool isEmpty(){
			return (front==size);
		}
};
int main(){
	deck d;
	d.addAtEnd(10);
	d.addAtEnd(20);
	d.addAtEnd(30);
	d.addAtEnd(50);
	d.addAtStart(204);
	d.addAtStart(400);
	d.addAtStart(500);
	cout<<"first: "<<d.getFirst()<<endl;
	cout<<"last: "<<d.getLast()<<endl;
	d.removeFromEnd();
	cout<<"new last: "<<d.getLast()<<endl;
	d.removeFromStart();
	cout<<"new first: "<<d.getFirst()<<endl;
	
	return -1;
}
