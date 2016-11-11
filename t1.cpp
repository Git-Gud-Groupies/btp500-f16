
void merge(const SortedList& other){
	iterator curr=begin();
	iterator othcurr=other.begin();
	while(curr!=end() && othcurr!=other.end()){
		if(*curr <= *othcurr){
			curr++;
		}
		else{
			Node* n=othcurr.curr_;
			othcurr++;
			//unhooks n from other
			n->next_->prev_=n->prev_;
			n->prev_->next_=n->next_;
			
			Node* c=curr.curr_;
			Node* p =curr.curr_->prev_;

			n->next_=c;
			n->prev_=p;
			c->prev_=n;
			p->next_=n;

		}	
	}
	while(othcurr!=other.end()){
			Node* n=othcurr.curr_;
			othcurr++;
			//unhooks n from other
			n->next_->prev_=n->prev_;
			n->prev_->next_=n->next_;
			
			Node* c=curr.curr_;
			Node* p =curr.curr_->prev_;

			n->next_=c;
			n->prev_=p;
			c->prev_=n;
			p->next_=n;

	}
	//	put the rest of other to back of currentlist

	other.end().curr_->prev_=other.begin().curr_;
	other.begin().curr_->next_=other.end().curr_;

}


//this is for positive in same order
//negative in opposite order
void arrange(int array[],int sz){
	Queue q;
	Stack s;
	for(int i=0;i<sz;i++){
		if(array[i] >= 0){
			q.enqueue(array[i]);
		}
		else{
			s.push(array[i]);
		}
	}
	int i;
	while(!q.isempty() && !s.isEmpty()){
		array[i++]=q.front();
		q.dequeue();
		array[i++]=s.top();
		s.pop();
	}
	while(!q.isEmpty()){
		array[i++]=q.front();
		q.dequeue();

	}
	while(!s.isEmpty()){
		array[i++]=s.top();
		s.pop();		
	}
}


//this is for negative in same order
//positive in opposite order
void arrange(int array[],int sz){
	Queue q;
	Stack s;
	for(int i=0;i<sz;i++){
		if(array[i] < 0){
			q.enqueue(array[i]);
		}
		else{
			s.push(array[i]);
		}
	}

	for(int i=0;i<sz;i++){
		if(i%2 == 0){
			if(!s.isEmpty()){
				array[i]=s.top();
				s.pop();
			}
			else{
				array[i]=q.front();
				q.dequeue();
			}
		}
		else{
			if(!q.isEmpty()){
				array[i]=q.front();
				q.dequeue();
			}
			else{
				arra[i]=s.top();
				s.pop();
			}
		}		
	}
	
}


int binarySearch(int array[],int key, int sz){
	return binarySearch(array,key,0,sz-1);
}
int binarySearch(int array[],int key, int low, int high){
	int rc=-1;
	if(low <= high){
		int mid=(low+high)/2;
		if(array[mid]==key){
			rc=mid;
		}
		else if(key < array[mid]){
			rc=binarySearch(array,key,low,mid-1);
		}
		else
			rc=binarySearch(array,key,mid+1,high);
	}
	return rc;
}


int binarySearch(int array[],int key, int sz){
	int rc=-1;
	int low=0;
	int high=sz-1;
	if(low <= high){
		int mid=(low+high)/2;
		if(array[mid]==key){
			rc=mid;
		}
		else if(key < array[mid]){
			rc=binarySearch(array,key,sz-mid-1);
		}
		else
			rc=binarySearch(array+mid+1,key,sz-mid+1);
	}
	return rc;
}

}