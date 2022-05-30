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
           if (temp2==NULL)
                      {
           if(temp->info<temp1->info)
           {
                   int swapp=temp->info;
                   temp->info=temp1->info;
                   temp1->info=swapp;  
            }  
                   
                   return;  
                       
                       }



            if(temp1->info>temp2->info){

                if(temp->info<temp1->info){
                   int swapp=temp->info;
                   temp->info=temp1->info;
                   temp1->info=swapp;                }          
                     }
            else
            {
                if(temp->info<temp2->info){
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
           if(temp->info<temp1->info){
                   int swapp=temp->info;
                   temp->info=temp1->info;
                   temp1->info=swapp;
                   
                }
                return;
        }
            if(temp1->info>temp2->info ){
                if(temp->info<temp1->info){
                   int swapp=temp->info;
                   temp->info=temp1->info;
                   temp1->info=swapp;
                }
            }
            else
            {
                if(temp->info<temp2->info){
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

  void row( Node *& temp)
        {
            if ( temp -> left != NULL)
                cout << temp -> left -> info << "\t";
            
            if ( temp -> right != NULL)
            cout << temp -> right -> info << "\t";

            return;
        }
 
 void print_level( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp == root)
            {
                cout << temp -> info << "\t";
                cout << temp -> left -> info << "\t";
                cout << temp -> right -> info << "\t";
            }

            if ( temp -> left != NULL)
                row( temp -> left);

            if ( temp -> right != NULL)
                row( temp -> right);

            if ( temp -> left != NULL)
                print_level( temp -> left);

            if ( temp -> right != NULL)
                print_level( temp -> right);

            return;
        }
 
};

int main(){

bst b;
 b.insertt(9,b.root);
 b.insertt(0,b.root->left);
 b.insertt(2,b.root->right);
 b.insertt(1000,b.root->left->left);
 b.insertt(-10,b.root->left->right);
 b.insertt(10,b.root->left->left->left);
 b.insertt(1,b.root->left->left->right);
 b.insertt(78,b.root->right->left);
 b.insertt(9000,b.root->right->right);




        b.inorder(b.root);

b.print_level(b.root);

cout<<endl;
       b.inorder(b.root);
          
b.print_level(b.root);
          
cout<<endl;
          b.inorder(b.root);
cout<<endl;
b.print_level(b.root);

cout<<endl;

b.print_level(b.root);
    return 0;
}




