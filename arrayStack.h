template <typename T>
class Stack{
	T* theStack_;
	int max_;
	int top_;
	void grow(){
		T* tmp;
		tmp=new T[max_*2];
		for(int i=0;i<max_;i++){
			tmp[i]=theStack_[i];
		}
		delete theStack_;
		theStack_=tmp;
		max_*=2;
	}
public:
	Stack(){
		top_=0;
		max_=5;
		theStack_=new T[max_];
	}
	void push(const T& data){
		if(top_ ==max_){
			grow();
		}
		theStack_[top_]=data;
		top_++;
		
	}
	void pop(){
		if(!isEmpty()){
			top_--;
		}
	}
	T top(){
		return theStack_[top_-1];
	}
	bool isEmpty(){
		return top_==0;
	}
};