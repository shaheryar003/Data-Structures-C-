#include <iostream>
using namespace std;
struct Node{
int info;
Node *left,*right;
};
class bst{
    public:
Node *root,*temp,*temp1,*temp2 ,*temp3;
bst(){
    root=NULL;
}

void inorder(Node *temp){
if (root == NULL){      
      return;
      }
    if(temp->left!= NULL){
        inorder(temp->left);
        }
    if(temp->left != NULL){
        temp1= temp->left;
        temp2=temp->right;
           if (temp2==NULL){
           if(temp->info>temp1->info){
                   int swapp=temp->info;
                   temp->info=temp1->info;
                   temp1->info=swapp;  
                   }  return;      }
            if(temp1->info<temp2->info){
                if(temp->info>temp1->info){
                   int swapp=temp->info;
                   temp->info=temp1->info;
                   temp1->info=swapp;                }            }
            else
            {
                if(temp->info>temp2->info){
                      int swapp=temp->info;
                   temp->info=temp2->info;
                   temp2->info=swapp;
}
            }
    }
    
    if(temp->right != NULL){
        temp1= temp->left;
        temp2=temp->right;
        if (temp2==NULL){
           if(temp->info>temp1->info){
                   int swapp=temp->info;
                   temp->info=temp1->info;
                   temp1->info=swapp;
                   
                }
                return;
        }
            if(temp1->info<temp2->info ){
                if(temp->info>temp1->info){
                   int swapp=temp->info;
                   temp->info=temp1->info;
                   temp1->info=swapp;
                }
            }
            else
            {
                if(temp->info>temp2->info){
                      int swapp=temp->info;
                   temp->info=temp2->info;
                   temp2->info=swapp;
                }
            }
    }
    
      
  //  cout<<temp->info<<endl;
    
    if(temp->right!= NULL){

        inorder(temp->right);
    }
}

void print(Node *temp){

  cout<<temp->info<<endl;
    if (root == NULL){
        
        return;

    }

    if(temp->left!= NULL){

        print(temp->left);
    }

  
    
    if(temp->right!= NULL){

        print(temp->right);
    }
}
void insertt(int key, Node *&temp){
     temp=new Node;
        temp->info=key;
        temp->left=temp->right=NULL;
        return;   
}

void checkheap( Node *&temp){
    bool flag=0;
     if (flag ==1){
        
        return;

    }

    if(temp->info< temp->left->info){
        
        checkheap(temp->left);
        flag=1;
    }
     else
    inorder(root);

  
    
   
    if(temp->info< temp->right->info){

        checkheap(temp->right);
        flag=1;
    }
    else
    inorder(root);


}
// Function to find the total number of nodes in a binary tree
int size(Node* root)
{
    if (root == nullptr) {
        return 0;
    }
 
    return 1 + size(root->left) + size(root->right);
}
 
// Function to check if a given binary tree is a complete binary tree
// and each node has a higher value than its parent
bool isHeap(Node* root, int i, int n)
{
    // base case
    if (root == nullptr) {
        return true;
    }
 
    // not complete binary tree: out of valid index range
    if (i >= n) {
        return false;
    }
 
    // current node has a higher value than its left or right child
    if ((root->left && root->left->info <= root->info) ||
            (root->right && root->right->info <= root->info)) {
        return false;
    }
 
    // check for left and right subtree
    return isHeap(root->left, 2*i + 1, n) && isHeap(root->right, 2*i + 2, n);
}
 
// Function to check if a given binary tree is a min-heap or not
bool isHeap(Node* root)
{
    int i = 0;
    return isHeap(root, i, size(root));
}
 
};

int main(){

bst b;
 b.insertt(5000,b.root);
 b.insertt(0,b.root->left);
 b.insertt(2,b.root->right);
 b.insertt(1000,b.root->left->left);
 b.insertt(-10,b.root->left->right);
 b.insertt(10,b.root->left->left->left);
 b.insertt(1,b.root->left->left->right);
 b.insertt(78,b.root->right->left);
 b.insertt(9,b.root->right->right);



// b.inorder(b.root);

// b.print(b.root);

// b.inorder(b.root);
// cout<<endl;
// b.print(b.root);

// b.inorder(b.root);
while(b.isHeap(b.root)!= 1){

        b.inorder(b.root);

    }

cout<<endl;
b.print(b.root);

cout<<endl;

b.inorder(b.root);
b.print(b.root);
    return 0;
}




