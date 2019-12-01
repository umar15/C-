/*  Name = Umar Khalid
	Reg # = SP18-BCS-164.
*/

#include <iostream>
using namespace std;

class dNode{
	public:
		int value;
		dNode *next;
		dNode *previous;
		dNode(){
			next = NULL;
			previous = NULL;
		}
		
};
// Single ended doubly linked circular
class AscendingList{
	private:
		dNode *head;
	public:
		AscendingList(){
			head = NULL;
		}
		AscendingList(int v){
			head = NULL;
			insert(v);
		}
		AscendingList(int arr[], int n){
			head = NULL;
			for(int i=0; i<n; i++){
				insert(arr[i]);
			}
		}
		void insert(int v){
			dNode *n = new dNode();
			n->value = v;
			if(head==NULL){
				n->next = n;
				n->previous = n;
				head = n;
			}
			else{
				bool check = false;
	            dNode *data = head;
	            do{
	                if (n->value <= data->value){
	                    n->next = data;
	                    n->previous = data->previous;
	                    data->previous->next = n;
	                    data->previous = n;
	                    if (data == head)head = n;
	                    check = true;
	                    break;
	                }
	                data = data->next;
	            }while (data!=head);
	            if(!check){
	                n->next = head;
	                n->previous = data->previous;
	                data->previous->next = n;
	                head->previous = n;
	            }
			}
		}
		void display(){
			dNode *d = head;
			do{
				cout<<d->value<<" ";
				d=d->next;
			}while(d!=head);
					
		}
		int Head(){
			return head->value;
		}
		
		AscendingList displayH(){
        AscendingList list;
        dNode *temp = head->next;
        while(temp!=head){
            list.insert(temp->value);
            temp = temp->next;
        }
        return list;
    }
};
int main(){
	int n = 5;
	int Arr[n];
	Arr[0] = 3;
	Arr[1] = 5;
	Arr[2] = 22;
	Arr[3] = 52;
	Arr[4] = 15;
	cout<<"List = ";
	AscendingList AL(Arr,n);
    AL.display();
    
    cout << "\nHead = " << AL.Head();
    
    cout<<"\nOthers = ";
    
    AscendingList AL2 = AL.displayH();
	AL2.display();
    return 0;
}
