/*
Tanzeel khan
SP18-BCS-162
*/

#include <iostream>
using namespace std;

void merge(int arr[], int start, int end){
	int size = start+end+1;
	int a[size];
	int i = start;
	int mid = (start+end)/2;
	int k = 0;
	int j = mid+1;
	
	while(k<=size){
		if(i>mid){
			a[k] = arr[j];
			k++;
			j++;
		}
	 	else if(j>end){
			a[k] = arr[i];
			k++;
			i++;
		}
		else if(arr[i]<arr[j]){
			a[k] = arr[i]  ;
			k++;
			i++;
		}
		else{
			a[k] = arr[j];
			k++;
			j++;
		}
	}
	for(k=0; k<size; k++){
		arr[start] = a[k];
		start++;
	}
	
}
void mergeSort(int ar[], int istart, int iend){
	int imid;
	if(istart>=iend){
		return;
	}
	
	imid = (istart+iend)/2;
	cout<<endl;
	mergeSort(ar, istart, imid);
	
	mergeSort(ar, imid+1, iend);
	
	merge(ar, istart, iend);
	
}

int main(){
	int Arr[] = {2, 4, 1, 6, 3, 9, 7, 8, 10, 5};
	mergeSort(Arr, 0, 9);
	for(int i=0; i<10; i++){
		cout<<Arr[i]<<" ";
	}
	return 0;
}
