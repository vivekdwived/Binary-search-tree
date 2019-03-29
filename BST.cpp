					// BST-II

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
    void insertHelper(int value){
        insert(root, value);
    }
    
    void insert(node *curr, int value){
        // If root is NULL, then create a node and make it root. 
        if (root == NULL) 
		{
			root = new node(value);
		}
        // Else Decide to move left or right. 
        else if (value < curr->data)  {
            // if left is already NULL, create a new node and link it. 
            if (curr->left == NULL)
			{
			  curr->left = new node(value);
              curr->left->parent=curr;
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
        	}
            // Move right and call insert there. 
            else insert(curr->right, value);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(node * curr){
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
	// THE REPLACE FUNCTION IN A BST-- used to delete the node with only 1 child
	void replaceHelper(int value1,int value2)
	{
		node*n1=searchHelper(value1);
		node*n2=searchHelper(value2);
		replace_At_parent(n1,n2);
	}
	void replace_At_parent(node*n1,node*n2) 
	{
	
		// where n1 is child of n2
		// we want to delete n2 and replace it with n1
		n1->parent=n2->parent;
		n2->parent=NULL;
		if((n2->data)>(n1->data))  		// if n1 is the left child of n2 -- means we give left point of n2 to corresponding connection of parent of n2
		{
			if((n2->parent->data)<(n2->data)) // n2 is right child of his parent 
			{	
				n2->parent->right=n2->left;
			}
			else					// if n2 is the left child of his/her parent
			{
				n2->parent->right=n2->left;
			}
		}
		else							// if n1 is right child n2
		{
			if((n2->parent->data)<(n2->data)) // n2 is right child of his parent 
			{	
				n2->parent->right=n2->right;
			}
			else					// if n2 is the left child of his/her parent
			{
				n2->parent->right=n2->right;
			}
		}
		
	}

	// the DELETE FUNCTION
	void DELETE(int value)
	{
		// NO CHILD -DELETE A LEAF- SEARCH AND REPLACE WITH NULL
		node*curr=searchHelper(value);
		if((curr->left)&&(curr->right)==NULL)
		{
			curr->parent->left=NULL;
			curr->parent->right=NULL;
		}
	
		// IF THERE IS ONE CHILD--
		else if((curr->left)||(curr->right)!=NULL)
		{	
			if(curr->left==NULL)
			{
				replace_At_parent(curr,curr->right);
			}
			else
			{
				replace_At_parent(curr,curr->left);
			}
		}
		// WHEN 2 CHILDREN--
		else
		{
		// replace it with the mininmum in the right saide of current
		node*mini=Find_min(curr->right);
		//exchange the data of curr and mini
		curr->data=mini->data;
		//breakup the relation with mini--
		mini->parent->left=NULL;
		mini->parent=NULL;
		}
	
	}
	
	
};

int main(){
    BST bst1;
    bst1.insertHelper(2);
    bst1.insertHelper(3);
    bst1.insertHelper(4);
    bst1.insertHelper(5);
    bst1.insertHelper(6);
	bst1.insertHelper(7);
    bst1.displayHelper();
    if(bst1.searchHelper(10) != NULL){
        cout << endl << bst1.searchHelper(10)->data << endl;
    }
    
    cout<<" the minimum node";
    cout<<endl<<bst1.FindHelper()->data<<endl;
    bst1.replaceHelper(5,10);
    cout<<"i am groot";
    bst1.displayHelper();
    //bst1.DELETE(5);
    
}
