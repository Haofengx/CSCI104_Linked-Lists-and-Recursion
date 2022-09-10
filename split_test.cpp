#include<iostream>
#include "split.h"

using namespace std;

int main(){
	// initalize vairables
	Node N5(20, NULL), N4(9, &N5), N3(7, &N4), N2(10, &N3), N1(1, &N2);
	Node* in = &N1;
	Node* evens = NULL;
	Node* odds = NULL;
	//put in the function
	split(in, odds, evens);
	//test case
	if(in == NULL){
		cout << "Is NULL" << endl;
	}
	else{
		cout << "Not NULL" << endl;
	}
	cout << "odds numbers: ";
	do{
		cout << odds->value << " ";
	}
	while(odds->next != NULL);
	cout << endl;
	cout << "evens numbers: ";
	do{
		cout << evens->value << " ";
	}
	while(evens->next != NULL);
	cout << endl;
}