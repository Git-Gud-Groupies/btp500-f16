template <typename T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data, Node* left=nullptr, 
								Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;

		}
	};
	Node* root_;
	//recursively adds data into the subtree
	//with root subtreeroot
	void ins(const T& data,Node*& subtreeroot){

		if(subtreeroot==nullptr){
			subtreeroot=new Node(data);
		}
		else{
			if(data_ < subtreeroot->data_){
				ins(data,subtreeroot->left_);
			}
			else{
				ins(data,subtreeroot->right_);
			}
		}

	}

	void inOrderPrint(const Node* subtreeroot) const{
		if(subtreeroot){
			//print the left subtree
			inOrderPrint(subtreeroot->left_);
			//print the current node
			cout << subtreeroot->data_ << " ";
			//print the right subtree
			inOrderPrint(subtreeroot->right_);
		}
	}

	void cleanup(Node* subtreeroot){
		if(subtreeroot){
			cleanup(subtreeroot->left_);
			cleanup(subtreeroot->right_);
			delete subtreeroot;
		}
	}
	/*detaches and returns the smallest node from tree at 
	root subtreeroot
	*/
	Node* detachSmallest(Node*& r){
		Node* rc;
		if(r->left_==nullptr){
			rc=r;
			r=r->right_;	
		}
		else{
			rc=detachSmallest(r->left_);
		}

		return rc;
	}
	/*removes the node containing data from the subtree 
	with root subtreeroot*/
	void remove(const T& data,Node*& subtreeroot){
		if(subtreeroot){
			if(subtreeroot->data_==data){
				//prevents accidental detachment that makes
				//it so tht we lose the node we want to delete
				Node* rm=subtreeroot;
				if(subtreeroot->right_ && subtreeroot->left_){
					//2 children
					Node* inorderSuccessor=detachSmallest(subtreeroot->right_);
					inorderSuccessor->left_=subtreeroot->left_;
					inorderSuccessor->right_=subtreeroot->right_;
					subtreeroot=inorderSuccessor;
				}
				else{
					if(subtreeroot->left_){
						//only left child
						subtreeroot=subtreeroot->left_;
					}
					else if(subtreeroot->right_){
						//only right child
						subtreeroot=subtreeroot->right_;
					}
					else{
						//leaf node
						subtreeroot=nullptr;
					}
				}
				delete rm;
			}
			else{
				if(data < subtreeroot->data_){
					remove(data,subtreeroot->left_);
				}
				else{
					remove(data,subtreeroot->right_);
				}
			}
		}
	}


public:
	//iterative
	void insert(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{
			bool isInserted=false;
			Node* curr=root_;
			while(!isInserted){
				if(data < curr->data_){
					if(curr->left_==nullptr){
						curr->left_=new Node(data);
						isInserted=true;
					}
					else{
						curr=curr->left_;
					}
				}
				else{
					if(curr->right_==nullptr){
						curr->right_=new Node(data);
						isInserted=true;
					}
					else{
						curr=curr->right_;
					}

				}
			}
		}


	}
	//recursive
	void ins(const T& data){
		ins(data,root_);
	}
	BST(){
		root_=nullptr;
	}


	void remove(const T& data){
		remove(data,root_);
	}
	void print() const{
		inOrderPrint(root_);
	}
	void breadthFirstPrint() const{
		const Node* curr;
		Queue<const Node*>  q;
		q.enqueue(root_);
		while(!q.isEmpty()){
			curr=q.front();
			q.dequeue();
			if(curr){
				cout << curr->data_ << " ";
				q.enqueue(curr->left_);
				q.enqueue(curr->right_);
			}
		}
	}

	~BST(){
		cleanup(root_);
	}
};





