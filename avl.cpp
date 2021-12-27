#include <iostream>
using namespace std;

struct Node{

int info;

Node *left,*right;
};

class bst{
    public:
Node *root,*temp,*temp1,*temp2;
int ansesstor,bf;

bst(){
    root=NULL;
}

void insert(int key, Node *&temp){

    if (temp==NULL){
        temp=new Node;
        temp->info=key;
        temp->left=temp->right=NULL;
       // root=temp;
    
        return;
    }

    if (key==temp->info){
        cout<<"Duplication is Not Allowed";
        return;
    }

    if(key>temp->info){
        insert(key,temp->right);
        
    }
    if(key<temp->info){
        insert(key,temp->left);
    }
   

   
int balance=balanceFactor(temp);
if(balance==2){
    if(key<temp->left->info){
           rightRotate(temp);
           return;

    }
    else{
          leftright(temp);
          return;
           
    }
}


if (balance == -2){
    if(key>temp->right->info){
         leftRotate(temp);
         return;
          
    }

    else{
       
          rightleft(temp);
          return;
    }

}
 
}


 Node* rightRotate(Node *& temp){//left left case
    
     temp1=temp->left;
     temp->left=temp1->right;
     temp1->right=temp;
     temp=temp1;
     temp1=NULL;
     return temp;
 }

 Node* leftRotate(Node *& temp){//right right case
     temp1=temp->right;
     temp->right=temp1->left;
     temp1->left=temp;
     temp=temp1;
     temp1=NULL;
     return temp;
 }




Node* leftright(Node *& temp){
    leftRotate(temp->left);
    rightRotate(temp);
    return temp;
}
Node * rightleft(Node *& temp){
    rightRotate(temp->right);
    leftRotate(temp);
    return temp ;
    
}
Node* deleteNode( int key,Node *temp){
  

    if(temp==NULL){
        return temp;
    }
    else if (key<temp->info){
       temp->left= deleteNode(key,temp->left);
    }
    else if(key>temp->info){
        temp->right=deleteNode(key,temp->right);
    }
    else{
     if(temp->left==NULL){
                temp1=temp->right;
               
                delete temp;

                return temp1;
            }
            else if(temp->right==NULL){
                temp1=temp->left;
               
                delete temp;
               
                return temp1;
            }
            else{
                temp1=minValue(temp->right);
                temp->info=temp1->info;
                temp->right=deleteNode(temp1->info,temp->right); 
                
            }
          
    }

     bf=balanceFactor(temp);
    if(bf==2 && balanceFactor(temp->left)>=0){
        return rightRotate(temp);
    }
    else if(bf==2 && balanceFactor(temp->left)==-1){
        temp->left=leftRotate(temp->left);
        return rightRotate(temp);
    }
    else if (bf==-2 && balanceFactor(temp->right)<=-0){
        return leftRotate(temp);
    }
    else if (bf==-2 && balanceFactor(temp->right)==1){
        temp->right=rightRotate(temp->right);
        return leftRotate(temp);
    }

    return temp;


}


Node* search(int key,Node *& temp){

if(root==NULL){
    cout<<"Empty Tree";
    return temp;
}

if(temp->info==key){
    cout<<"FOUND\n";
    return temp;
    
}

if((temp->left!=NULL)&& (key<temp->info)){
     search (key,temp->left);

}


if((temp->right!=NULL)&& (key>temp->info)){
     search (key,temp->right);

}




    if(temp->left==NULL && temp->right==NULL){
        cout<<"\nNOT FOUND";
        return NULL;
    }





}

int ansector(int key,Node *&temp){

    if(key<temp->info){
        ansesstor=temp->info;
    }
    if(key>temp->info){
        ansector(key,temp->right);
    }
    if(key<temp->info){
        ansector(key,temp->left);
    }
    return ansesstor;
}

Node* successor(int key){
    Node *temp2,*temp1;
    temp1=search(key,root);
    if(temp1->right!=NULL){
        if(temp1->right->left==NULL){
            return temp1->right;
        }
        else{

    temp2=temp1->right;
    while(temp2->left!=NULL){
        temp2=temp2->left;
    }
        }
    return temp2;
}
else{
    ansector(key,root);
}

}

Node* backsearch(int key,Node *&temp){

   

if(temp->right != NULL){
if(temp->right->info==key){
   
    return temp;
}


}

if(temp->left != NULL){
if( temp->left->info == key){


    return temp;

}
}
if(key>temp->info){
    
    
    backsearch(key,temp->right);
    
}

if(key<temp->info){
    
    backsearch(key,temp->left);
}

}

void inorder(Node *temp){


    if (root == NULL){
        
        return;

    }
  

    if(temp->left!= NULL){

        inorder(temp->left);
    }

      cout<<temp->info<<endl;
    
    if(temp->right!= NULL){

        inorder(temp->right);
    }
}



int height( Node *& temp)
        {
            if ( temp == NULL)
            {
                return 0;
            }

            else
            {
                int left = height( temp -> left);
                int right = height( temp -> right);

                if ( left > right)
                    return left + 1;
                else
                    return right + 1;
            }
        }


int balanceFactor( Node * temp)
        {
            int left=0;
            int right=0;
            if ( temp == NULL)
            {
                cout << "\nTree is empty." << endl;
                return 0;
            }

           if(temp!=NULL){
               if (temp->left!=NULL){
                   left=height( temp ->left);
               }
               if(temp->right!=NULL){
                   right=height(temp->right);
               }
           }
            return left - right;
        }

        Node * minValue(Node* temp){
    temp2=temp;
    while(temp2->left!=NULL){
        temp2=temp2->left;
    }
    return temp2;
}

};

int main(){

bst b;
b.insert(10,b.root);
b.insert(30,b.root);
b.insert(20,b.root);
b.insert(40,b.root);

b.inorder(b.root);
b.deleteNode(10,b.root);
cout<<"\n";
b.inorder(b.root); 
    return 0;
}



