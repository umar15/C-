#include <iostream>

using namespace std;

int Search(int Arr[], int n, int key){
	int i;
	for(i=0; i<n; i++){
		if(key==Arr[i]){
			return i;
		}
	}
	return -1;
	
}

int main(){
	int n = 10;
	int Arr[n] = {2, 3, 4, 5, 6, 5, 3, 5, 6 ,8};
	
	int key;
	cout<<"Enter a key to search: ";
	cin>>key;
	
	cout<<"The index of searched key is: "<<Search(Arr, n, key);
	
	
}
