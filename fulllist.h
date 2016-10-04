#include <iostream>
using namespace std;

template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data = T{},Node* next=nullptr,Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* head_;
	Node* tail_;
public:
	class const_iterator{
		Node* curr_;
		DList* myList_;
		const_iterator(Node* n, DList* list){
			curr_=n;
			myList_=list;
		}
	public:
		const_iterator(){
			curr_=nullptr;
			myList_=nullptr;
		}
		const_iterator operator++(int){
			//p++
			const_iterator old=*this;
			curr_=curr_->next_;
			return old;	
		}
		const_iterator operator++(){
			//++p
			curr_=curr_->next_;
			return *this;

		}
		const_iterator operator--(int){
			//p--
			const_iterator old=*this;
			curr_=curr_->prev_;
			return old;			
		}
		const_iterator operator--(){
			//--p
			curr_=curr_->prev_;
			return *this;
		}
		const T& operator*() const{
			return curr_->data_;
		}
		bool operator==(const_iterator right){
			return curr_==right.curr_;
		}
		bool operator!=(const_iterator right){
			return curr_!=right.curr_;
		}

	};
	class iterator:public const_iterator{
	public:
		T& operator*() const{
			return curr_->data_;
		}
	};
	DList(){
		head_=new Node();  //create front sentinel
		tail_=new Node();  //create back sentinel
		head_->next_=tail_;
		tail_->prev_=head_;

	}
	void push_front(const T& data){
		//this function adds a node between 
		//front sentinel and the first node in list

		Node* first=head_->next_; //it is ok if this
		                          //is back sentinel
		Node* temp=new Node(data,first,head_);
		head_->next_=temp;
		first->prev_=temp;

	}
	void push_back(const T& data){

	}
	void pop_front(){

	}


	void pop_back(){
		Node* last=tail_->prev_;
		//checks if list is empty
		if(last!=head_){
			Node* secondLast=last->prev_;
			tail_->prev_=secondLast;
			secondLast->next_=tail_;
			delete last;
		}

	}
	void print() const{
		Node* it=head_->next_;
		while(it!=tail_){
			cout << it->data_ << endl;
			it=it->next_;
		}
	}
};

