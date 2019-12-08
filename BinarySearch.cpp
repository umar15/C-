#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key){
	int lower, upper, mid;
	lower = 0;
	upper = size-1;
	
	while (lower<=upper){
		mid = (lower+upper)/2;
		if(arr[mid] == key){
			return mid;
		}
		else if(key<arr[mid]){
			upper = mid-1;
		}
		else{
			lower = mid+1;
		}
	}
	return -1;
}

int BinarySearchRecursive(int arr[], int L, int U, int key){
	int mid = (L+U)/2;
	if(L>U){
		return -1;
	}
	else if(arr[mid] == key){
			return mid;
	}
	else if (key<arr[mid]){
		return BinarySearchRecursive(arr, L, mid-1, key);
	}
	else{
		return BinarySearchRecursive(arr, mid+1, U, key);
	}
}

int main(){
	int Arr[] = {2, 3, 5, 7, 9};
	int size = 5;
	cout<<"Key is at index "<<BinarySearchRecursive(Arr, 0, size-1, 7);
	return 0;
}
