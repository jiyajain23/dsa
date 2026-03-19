// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        Node* root=new Node;
        root=newNode(pre[0]);
        int i=1;
        
        while(i<size){
            Node* temp=root;// code here
        Node* toAdd=new Node;
        toAdd=newNode(pre[i]);
            while(temp){
                if(pre[i]>temp->data){
                    if(temp->right==NULL){
                        temp->right=toAdd;
                        break;
                    }else temp=temp->right;
                }
                
                else{
                    if(temp->left==NULL){
                        temp->left=toAdd;
                        break;
                    }else temp=temp->left;
                }
            }
            i++;
        }
        return root;
    }
};