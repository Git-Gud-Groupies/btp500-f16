#include <iostream>
using namespace std;

template <typename T>
class SList{
	struct Node{
		T data_;
		Node* next_;
		Node(const T& data,Node* next=nullptr){

		}
	};
	Node* head_;
	Node* tail_;
public:
	SList(){
	}
	void push_front(const T& data){

	}
	void push_back(const T& data){

	}
	void pop_front(){
		
	}
	void pop_back(){

	}
	void print() const{

	}
};

