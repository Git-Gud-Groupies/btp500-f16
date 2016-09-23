#include "dlist.h"
#include <iostream>
int main(void){
	DList<int> list;
	list.push_front(10);
	list.push_front(5);
	list.push_front(15);
	list.print();
	cout << "***********" << endl;
	list.pop_back();
	list.print();
}