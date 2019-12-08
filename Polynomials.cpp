/*
Umar Khalid (SP18-BCS-164)
Shariq Ahmad (SP18-BCS-151)
Tanzeel Khan (SP18-BCS-162)
Shams (SP18-BCS-)
Ubaid (SP18-BCS-)
*/
#include <iostream>
using namespace std;

struct Node {
	int power;
	double coeff;
	struct Node * next;
};
// ====================================================================================//
/* This method will insert values and link them
   to one another using circular list and also sort them in ascending order */

Node * insertValues(double c, int p, Node *head){
	Node *n, *temp;
	n = new Node();
	n->power = p;
	n->coeff = c;
	n->next = NULL;
	
	if(head == NULL){
		head = n;
		head->next = head;
		return head;
	}
	
	if(p > head->power){
		n->next = head->next;
		head->next = n;
		head = n;
		return head;
	}
	
	if(p == head->power){
		head->coeff = head->coeff + c;
		return head;
	}
	
	temp = head;
	while(temp->next != head && p >= temp->next->power){
		temp = temp->next;
	}
	if(n->power == temp->power){
		temp->coeff = temp->coeff + c;
	}
	else{
		n->next = temp->next;
		temp->next = n;
	}
	
	return head;
}
// This method will create the polynomial from user instructions
Node *create(){
	Node *head = NULL;
	int n, p;
	double c;
	cout<<endl<<"Enter the number of terms: ";
	cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<"** Enter the values for "<<i+1<<" term **"<<endl;
		cout<<"Enter the co_efficient for "<<i+1<<" term: ";
		cin>>c;
		cout<<"Enter the power for "<<i+1<<" term: ";
		cin>>p; 
		head = insertValues(c, p, head);
	}
	return head;
}

// ========================================================================================//
// Method for adding polynomial
Node *Addition( Node *p1, Node *p2){
	Node *addedPolynomial;
	Node *head = NULL;
	
	addedPolynomial = p1->next;
	do{
		head = insertValues(addedPolynomial->coeff, addedPolynomial->power, head);
		addedPolynomial = addedPolynomial->next;
	}while (addedPolynomial != p1->next);
	
	addedPolynomial = p2->next;
	do{
		head = insertValues(addedPolynomial->coeff, addedPolynomial->power, head);
		addedPolynomial = addedPolynomial->next;
	}while (addedPolynomial != p2->next);
	
	return head;
}

//==================================================================================================//
// Method for multiplication of polynomial
Node *Multiplication(Node *p1, Node *p2){
	Node *head_p1, *head_p2;
	Node *head = NULL;
	
	head_p1 = p1->next;
	do{
		head_p2 = p2->next;
		
		do{
			head = insertValues(head_p1->coeff * head_p2->coeff , head_p1->power + head_p2->power , head);
			head_p2 = head_p2->next;
			
		}while(head_p2 != p2->next);
		
		head_p1 = head_p1->next;
		
	}while (head_p1 != p1->next);
	
	return head;
}
//===================================================================================================//
// Method for subtraction of polynomials
Node *sub(Node *p1, Node *p2){
	Node *head_p1, *head_p2;
	Node *head = NULL;
	
	head_p1 = p1->next;
	head_p2 = p2->next;
			
	do{
		if(head_p1->power == head_p2->power){
			head = insertValues(head_p1->coeff - head_p2->coeff , head_p1->power , head);
			head_p1 = head_p1->next;
			head_p2 = head_p2->next;
		}
		else if(head_p1->power > head_p2->power){
			head = insertValues(head_p1->coeff, head_p1->power , head);
			head_p1 = head_p1->next;
		}
		else{
			head = insertValues(head_p2->coeff, head_p2->power , head);
			head_p2 = head_p2->next;
		}
		
	}while ((head_p1 != p1->next) && (head_p2 != p2->next));
	
	if(head_p1 == p1->next){
		do{
			head = insertValues(head_p2->coeff, head_p2->power , head);
			head_p2 = head_p2->next;
			
		}while(head_p2 != p2->next);
	}
	
	else if(head_p2 == p2->next){
		do{
			head = insertValues(head_p1->coeff, head_p1->power , head);
			head_p1 = head_p1->next;

			
		}while(head_p1 != p1->next);
	}
	
	return head;
}

//=======================================================================================================//
// This method is to copy one polynomial to another which will be used in dividing polynomials

Node *copy(Node *n){
	Node *temp, *x;
	x = n->next;
	do{
		temp = new Node();
		temp->coeff = x->coeff;
		temp->power = x->power;
		temp->next = x->next;
		x = x->next;
		
	}while(x->next != n->next);
	return temp;
}
//=================================================================================================//
// This method is to divide two polynomials
void Div(Node *p1, Node *p2){
	Node *divisor, *dividand, *t;
	Node *quotient = NULL;
	dividand = copy(p1);
	divisor = copy(p2);
	t = p1->next;
	
	do{
		
		if(divisor->power > dividand->power){
			break;
		}
		Node *n = new Node();
		Node *temp = new Node();
		n->coeff = (int)dividand->coeff / divisor->coeff;
		n->power = (int)dividand->power - divisor->power;
		quotient = insertValues(n->coeff, n->power, quotient);
		cout<<(int)quotient->coeff<<"x^"<<quotient->power<<" + ";
		temp = insertValues(n->coeff, n->power, quotient);
		temp = Multiplication(divisor, temp);
		dividand = sub(dividand, temp);
		t = t->next;
		
	}while(t->next != p1->next);
	
}

//====================================================================================================// 
void print(Node *head)
{   Node *p;
    p=head->next;
    cout<<endl;
    do
    {
	    cout<<p->coeff<<"x^"<<p->power;
	    if(p->next != head->next){
    		cout<<" + ";
		}
	    p=p->next;
    }while(p!=head->next);
    
}

//========================================================================================================//

int main(){
	cout<<"** POLYNOMIALS **"<<endl;
 	Node *p1, *p2, *p3;
 	Node *polyAdded, *polySubtracted, *polyMultiplicated;
 	Node *polyDivided;
 	p1=p2=p3=NULL;
 	polyAdded = polySubtracted = polyMultiplicated = polyDivided = NULL;
 	p1 = create();
 	p2 = create();
 	cout<<endl<<"First Polynomial: ";
	print(p1);
	cout<<endl;
	cout<<endl;
 	cout<<"Second Polynomial:  ";
	print(p2);
	cout<<endl;
	cout<<endl;
 	polyAdded = Addition(p1, p2);
 	cout<<"Added Polynomial:  ";
	print(polyAdded);
	cout<<endl;
	cout<<endl;
 	polySubtracted = sub(p1, p2);
 	cout<<"Subtracted Polynomial:  ";
	print(polySubtracted);
	cout<<endl;
	cout<<endl;
 	polyMultiplicated = Multiplication(p1, p2);
 	cout<<"Multiplicated Polynomial:  ";
	print(polyMultiplicated);
 	cout<<endl;
 	cout<<endl;
 	cout<<"Divided Polynomial:  ";
 	cout<<endl;
 	Div(p1, p2);
 	cout<<endl;
 	
 	
}
//=====================================================================================================//

