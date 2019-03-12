			// BINARY SEARCH TREE
	#include<iostream>
	using namespace std;
	
	// declare class node for the tree
	class node
	{	
		public:
		int data;
		node*left;
		node*right;
		node(int value)
			{
				left=NULL;
				right=NULL;
			}	
	};

	// class for the BST;
	class BST
	{
	public:
		// the beginning of tree
		node*root;
		// default constructor
		BST()
		  {
			root=NULL;
		  }

	// the member functions.
	//1.insert,
	void insertHELPER(int value)
		{
			insert(root,value);
		}
	void insert(node*current,int value)
		{
			/* 1. if current is NULL->create a node with data=value
			   2. if current!=NULL->1.if value<data of current->use recursion to make a node as current->left
						2.if value<data of current-> call the function as current->right.
			*/
			
			if(root==NULL){root=new node(value);}
			else if(value<current->data)
			{ 	if(current->left==NULL) current->left=new node(value);
			  	else insert(current->left,value);	
			}
			else {  if (current->right==NULL) current->right=new node(value);
				else insert(current->right,value); 
			     }
		}

	//DISPLAY THE BST
	void displayHELPER(){ display(root); }
	void display(node*current)
		{
			/* 1. if current==NULL cout the data and return back
			   2. otherwise, cout the data then
			   3. go to left by caling current->left function paratmetr
			   4. go right by calling function with current->right parameter.
			*/	

			if(current==NULL) return;
			else{
				cout<<"display the left branches:"<<endl;
				cout<<current->data<<",";
				display(current->left);
				cout<<" display the right branches:"<<endl;
				display(current->right);
				cout<<current->data;	
			    }
		}

	};
	
	// driver function
	int main()
	{
		BST b1;
		b1.insertHELPER(1);
		b1.insertHELPER(2);
		b1.insertHELPER(3);
		b1.insertHELPER(4);
		b1.displayHELPER();
	return 0;
	}

