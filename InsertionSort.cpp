#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n){
	int temp, j;
	for(int i=1; i<n; i++){
		j=i;
		while(j>0 && arr[j-1]>arr[j]){
			temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}
