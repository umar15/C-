#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n){
	bool swap = true;
	int j=0, temp;
	while(swap){
		swap = false;
		j++;
		for(int i=0; i<n-j; i++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swap = true;
			}
		}
	}
}
