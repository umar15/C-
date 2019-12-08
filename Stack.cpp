#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
	Stack s;
	s.push(10);
	s.push(1);
	s.push(20);
	s.push(30);
	s.push(15);
	
	while (is.empty()){
		cout<<s.peek();
		s.pop();
	}
	return 0;
	
}
