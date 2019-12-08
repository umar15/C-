#include <iostream>
using namespace std;

void swap(int Arr[], int x, int y){
	int temp;
	temp = Arr[x];
	Arr[x] = Arr[y];
	Arr[y] = temp;
}
void QuickSort(int arr[], int left, int right){
	int pivot = arr[(left+right)/2];
	cout<<"Pivot = "<<pivot<<endl;
	int i, j;
	i = left;
	j = right;
	cout<<"i = "<<i<<endl;
	cout<<"j = "<<j<<endl;
	cout<<endl<<"Start while"<<endl;
	while(i<=j){
		while(pivot>arr[i]){
			cout<<"i = "<<i<<endl;
			i++;
		}
		while(pivot<arr[j]){
			cout<<"j = "<<j<<endl;
			j--;
		}
		if(i<=j){
			swap(arr, i, j);
			cout<<arr[i]<<" is swapped with "<<arr[j]<<endl;
			i++;
			j--;
		}
	}
	
	cout<<"After firt loop"<<endl;
	cout<<"i = "<<i<<endl;
	cout<<"j = "<<j<<endl;
	
	for(int k=0; k<10; k++){
		cout<<arr[k]<<" ";
	}
	cout<<endl;
	
	if(left<j){
		cout<<"First condition."<<endl;
		QuickSort(arr, left, j);
	}
	if(right>i){
		cout<<"Second condition"<<endl;
		QuickSort(arr, i, right);
	}
	
}


int main(){
	int arr[] = {125, 240, 215, 626, 923, 721, 218, 322, 126, 25};
	QuickSort(arr, 0, 9);
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
