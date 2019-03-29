							// BST-III

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*parent;
    node * left;
    node * right;
	// parameterized constructor
	
    node(int value){
        data = value;
        left = NULL;
        right = NULL;
        parent= NULL;
    }
};

class BST{
public:
    node * root;

    BST(){
        root = NULL;
    }
	
	// THE INSERTION FUNCTION
    void insertHelper(int value){
        insert(root, value);
    }
    
    // variable for 
    int count_path=0;
    int count=0;
    void insert(node *curr, int value){
        // If root is NULL, then create a node and make it root.
        if (root == NULL) 
		{
			root = new node(value);
			count++; 
		}
        // Else Decide to move left or right. 
        else if (value < curr->data)  {
            // if left is already NULL, create a new node and link it. 
            if (curr->left == NULL)
			{
			  curr->left = new node(value);
              curr->left->parent=curr;
              count++;
            }
            // Move left and call insert there. 
            else insert(curr->left, value); 
        }
        else {
            // if right is already NULL, create a new node and link it. 
            if (curr->right == NULL)
			{
				curr->right = new node(value);
            	curr->right->parent=curr;
            	count++;
        	}
            // Move right and call insert there. 
            else insert(curr->right, value);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(node * curr)
	{
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display(curr->left);
        // Print myself.
        cout << curr->data << ", ";
        // Print right.
        display(curr->right);
    }
    
    // counting the function---- use it with insert function
    
    node * searchHelper(int value){
        return search(root, value);
    }
    node * search(node * curr, int value){
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        else if(value < curr->data) return search(curr->left, value);
        // Right
        else  return search(curr->right, value);
    }
		
			// for count
			int Count()
			{
				return count;
			}
		
		// FINDING  the minimum node in the given sub-tree
		node*FindHelper()
		{
			return  Find_min(root);
		}
		node*Find_min(node*curr)
		{
			// start from the root 
			//if root id nULL display error
			// else if current left exists move to left ...till it is NULL
			if(curr==NULL) cout<<" error ";
			else
			{
				while(curr->left!=NULL)
				{
					curr=curr->left;
				}
			}
			return curr;
		}
		


	//the RANGE FUNCTOIN

	
	void rangeSearch(int k1,int k2)
	{
        display2(root,k1,k2);
    }
    
    void display2(node * curr,int k1,int k2)
	{
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display2(curr->left,k1,k2);
        // Print myself.
        if((k1<=curr->data)&&(curr->data<=k2))
        {
        	        cout << curr->data << ", ";
		}
        // Print right.
        display2(curr->right,k1,k2);
    }
    
    
	// the HEIGHT FUNCTION
	void height()
	{
		int count_path=0;
		display3(root,count_path);
	}

	void display3(node * curr,int count_path)
	{
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL){	
			cout<<" count_path "<<count_path<<endl;
			count_path=0;
			return;
		} 
		cout<<"i am path"<<count_path<<endl;
        // IN order print.
        // Print left. 
        display3(curr->left,count_path++);
        // Print right.
        display3(curr->right,count_path++);
    }
	
};

int main(){
    BST bst1;
    bst1.insertHelper(1);
    bst1.insertHelper(2);
    bst1.insertHelper(3);
    bst1.insertHelper(4);
    bst1.insertHelper(5);
	bst1.insertHelper(6);
	bst1.insertHelper(7);
	bst1.insertHelper(8);
	bst1.insertHelper(9);
	bst1.insertHelper(10);
    bst1.displayHelper();
    cout<<" display the no. of nodes:- ";
    cout<<bst1.Count();
    if(bst1.searchHelper(10) != NULL){
        cout << endl << bst1.searchHelper(10)->data << endl;
    }
    
    cout<<" the minimum node";
    cout<<endl<<bst1.FindHelper()->data<<endl;
    cout<<" I AM IRON MAN"<<endl;
    
    bst1.rangeSearch(5,10);
    cout<<endl;
    bst1.height();
	
}
