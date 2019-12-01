#include <iostream>
using namespace std;

class List{
	private:
		int Arr[10];
		int n;
	public:
		List() {n=0;}
		
	void insert(int v){
		if(n<10){
			Arr[n] = v;
			n++;
		}
		
	}
	void Remove(int j){
		for(;j<n; j++){
			Arr[j] = Arr[j+1];
		}
		n--;
	}
	void Display(){
		for(int j=0; j<n; j++){
			cout<<Arr[j]<<",";
		}
	}
};
int main(){
	List l;
	l.insert(10);
	l.insert(20);
	l.insert(30);
	l.insert(25);
	l.insert(5);
	l.insert(2);
	l.insert(3);
	l.insert(27);
	l.insert(26);
	l.insert(28);
	l.Display();
	cout<<"\n";
	l.Remove(1);
	l.Display();
	
}
