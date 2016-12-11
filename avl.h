class AVL{
	struct Node{
		int  data_;
		Node* left_;
		Node* right_;
		int height_;
		Node(int v){
			data_=v;
			left_=right_=nullptr;
			height_=1;
		}
	};
	Node* root_;
	//returns the height stored in n if n is not null
	int height(const Node* n) const{
		int rc=0;
		if(n){
			rc=n->height_;
		}
		return rc;
	}
	//calculates the height n based on the height of its children
	int calcHeight(const Node* n) const{
		int rc=0;
		if(n){
			int heightLeft=height(n->left_);
			int heightRight=height(n->right_));
			rc=(heightLeft > heightRight)?heightLeft:heightRight;
			//wrong way to use ?:
			// (a > b)? (cout << a) : (cout << b);
			//right way to use ?:
			//  cout << (a>b)?a:b;

		}
		return rc;
	}
	int balance(const Node* n) const{
		int rc=0;
		if(n){
			rc=height(n->right_)-height(n->left_);
		}
		return rc;
	}
	void leftRotate(Node*& A){
		Node* B=A->right_;
		Node* y=B->left_;

		A->right_= y;
		A->height_=calcHeight(A);
		B->left_=A;
		B->height_=calcHeight(B);

		A=B;

	}
	void rightRotate(Node*& A){

	}
	void insert(int v, Node*& r){
		if(r==nullptr){
			r=new Node(v);
		}
		else{
			if(v < r->data_){
				insert(v,r->left_);
			}
			else{
				insert(v,r->right_);
			}

			int nodeBalance=balance(r);
			if(nodeBalance == 2){
				if(balance(r->right_)>0){
					//single
					leftRotate(r);
				}
				else{
					rightRotate(r->right_);
					leftRotate(r);
				   //double
				}
			}
			else if(nodeBalance == -2){
				//rotation
				if(balance(r->left_) < 0){
					//single
				}
				else{
					//double
				}
			}
			else{
				r->height_=calcHeight(r);
			}
		}
	}
public:
	AVL(){
		root_=nullptr;
	}
	void insert(int v){
		insert(v,root_);
	}
}