#include <iostream>
using namespace std;

template <typename T>
class SList{
	struct Node{
		T data_;
		Node* next_;
		Node(const T& data,Node* next=nullptr){
			data_=data;
			next_=next;
		}
	};
	Node* head_;
	Node* tail_;
public:
	SList(){
		head_=tail_=nullptr;
	}
	void push_front(const T& data){
		Node* temp=new Node(data,head_);
		if(!head_){
			tail_=temp;
		}
		head_=temp;


	}
	void push_back(const T& data){

	}
	void pop_front(){
		
	}
	void pop_back(){
		if(head_){
			if(head_!=tail_){
				Node* last=tail_;
				Node* secondLast=head_;//=tail_->prev_;
				while(secondLast->next_!=tail_){
					secondLast=secondLast->next_;
				}
				secondLast->next_=nullptr;
				delete last;
				tail_=secondLast;
			}
			else{
				delete head_;
				head_=tail_=nullptr;
			}
		}	
	}
	void print() const{
		Node* it=head_;
		while(it){
			cout << it->data_ << endl;
			it=it->next_;
		}

	}
};

