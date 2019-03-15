							// the BINARY SEARCH TREE
	#include<iostream>
	using namespace std;
	
	class Node
	{
	public:
	    int data;
	    Node * left;
	    Node * right;
	
	    Node(int value){
	        data = value;
	        left = NULL;
	        right = NULL;
	    }  
	};
	
	class BST
	{
	public:
	    Node * root;
	    BST(){
	        root = NULL;
	    }
	    void insertHelper(int value){
	        insert(root, value);
	    }
	    void insert(Node *curr, int value){
	        // If root is NULL, then create a node and make it root.
			// Else Decide to move left or right.  
			// if left is already NULL, create a new node and link it.
			// Move left and call insert there.  
			// if right is already NULL, create a new node and link it.
			// Move right and call insert there.  
	        if (root == NULL) root = new Node(value);
	        
	        else if (value < curr->data)  {
	            
	            if (curr->left == NULL) curr->left = new Node(value);
	           
	            else insert(curr->left, value);
	        }
	        else {
	            
	            if (curr->right == NULL) curr->right = new Node(value);
	            
	            else insert(curr->right, value);
	        }
	    }
	    void displayHelper()
		{
	        display(root);
	    }
	    void display(Node * curr)
		{
	        // Case for empty tree and leaf nodes children.
	        // IN order print.
	        // Print left. 
	        // Print myself.
	        // Print right.
	        if( curr ==  NULL) return;
	        
	        display(curr->left);
	        
	        cout << curr->data << ", ";
	        
	        display(curr->right);
	    }
	    Node * searchHelper(int value)
		{
	        return search(root, value);
	    }
	    Node * search(Node * curr, int value)
		{
	        // check value or NULL if yes return curr
	        // else you search in right or left. 
	        
	        // Left
	        if(curr == NULL || curr->data == value ) return curr;
	        
	        else if(value < curr->data) return search(curr->left, value);
	        // Right
	        else  return search(curr->right, value);
	    }
	
	};
	
	int main()
	{
	    BST bst1;
	    bst1.insertHelper(23);
	    bst1.insertHelper(22);
	    bst1.insertHelper(21);
	    bst1.insertHelper(20);
	    bst1.insertHelper(19);
	    bst1.insertHelper(18);
	    bst1.insertHelper(17);
	    bst1.displayHelper();
	    if(bst1.searchHelper(20) != NULL)
		{
	        cout << endl << bst1.searchHelper(20)->data << endl;
	    }
	    
	    if(bst1.searchHelper(22) != NULL)
		{
	        cout << endl << bst1.searchHelper(22)->data << endl;
	    }
	}
