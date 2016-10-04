template <typename T>
class Queue{
	T* theQueue_;
	int max_;
	int back_;
	int front_;
	int size_;
	void grow(){
		T* tmp;
		tmp=new T[max_*2];
		int j=front_;
		for(int i=0;i<size_;i++,j=(j+1)%max_){
			tmp[i]=theStack_[j];
		}
		delete theStack_;
		theStack_=tmp;
		front_=0;
		back_=size_;
		max_*=2;
	}
public:
	Queue(){
		max_=5;
		size_=0;
		back_=0;
		front_=0;
		theQueue_=new T[max_];
	}
	void enqueue(const T& data){
		if(size_==max_){
			grow();
		}
		theQueue_[back_]=data;
		back_=((back_+1)==max)?0:back_+1;
		/*alternatives:
		back_=back_+1;
		if(back_==max_){
			back_=0;
		}
		*/
		/*alternative 2:
		back_=(back_+1)%max_;*/

		size_++;

	}
	void dequeue(){
		if(!isEmpty()){
			front_=(front_+1)%max_;
			size_--;
		}
	}
	T front(){
		return theQueue_[front_]
	}
	bool isEmpty(){
		return 
	}
};