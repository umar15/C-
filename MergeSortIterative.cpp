/*
Tanzeel khan
SP18-BCS-162
*/

#include <iostream>
using namespace std;
class MergeSortItertive{
	public:
		void merge(int data[],int s,int e,int len){
			int i=2,j=0;
			while(i<len){
				j=0;
				while(j<(len-1)){
					int r=(j+i)-1,l=j;
					if(r>len){
						r=len-1;
					}
					int m=(l+r)/2;
					mergeSort(data,l,m,r);
					j+=1;	
				}
				i=i*2;
				if(i>=len){
						i=i/2;
						mergeSort(data,0,len-1,i-1);
						i=len;
					}
				
			}
		}

		void mergeSort(int data[],int s,int m,int e){
			int firstHalf=m-s+1;
			int secondHalf=e-m;
			int leftElements[firstHalf];
			int rightElements[secondHalf];
			for(int i=0;i<firstHalf;i++){
				leftElements[i]=data[s+i];
			}
			for(int i=0;i<secondHalf;i++){
				rightElements[i]=data[m+i+1];
			}

			int a=0,b=0,c=s;

			while(a<firstHalf && b<secondHalf){
				if(leftElements[a]<rightElements[b]){
					data[c]=leftElements[a];

					a++;
					c++;
				}
				else{
					data[c]=rightElements[b];
					b++;
					c++;
				}
			}

			while(a<firstHalf){
				data[c]=leftElements[a];
				a++;
				c++;
			
			}
			while(b<secondHalf){
				data[c]=rightElements[b];
					b++;
					c++;
			}	
		}
		void display(int array[],int size){
			for(int i=0;i<size;i++){
				cout<<array[i]<<" ";
			}
		}	
};
int main(){
	int array[]={1, 3, 2, 5, 4};
	int size=5;
	MergeSortItertive s;
	s.merge(array,0,5,size);
	s.display(array,size);
	return -1;	
}
