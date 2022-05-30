#include <iostream>
using namespace std;

struct Node{

int info;

Node *left,*right;

};

class bst{
    public:
Node *root,*temp,*temp1,*temp2 ,*temp3;
int ansesstor,counter=0;

bst(){
    root=NULL;
}

void insert(int key, Node *&temp){

   
    if(temp==NULL){
        temp=new Node;
        temp->info=key;
        temp->left=temp->right=NULL;
        return;
    }

    if (key==temp->info){
        cout<<"Duplication is Not Allowed";
        return;
    }

    if(key>temp->info){
        insert(key,temp->right);
        return;
    }
    if(key<temp->info){
        insert(key,temp->left);
        return;

    }

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

//same asestor without recursion working

// else{
    
//    temp=root;
//    while(temp->info!=key){
//    if(temp->info>key){
//        temp1=temp;
//    }
//    if((temp->right != NULL)&& (key > temp->info)){
//        temp=temp->right;
//        if(temp->info>key){
//            temp1=temp;
//        }
//    }
//    if(temp->left!=NULL && key < temp->info){
//        temp= temp->left;
//        if(temp->info>key){
//            temp1=temp;
//        }
//    }
   
//    }
//    return temp1->info;
// } 
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
                //temp=NULL;
                return temp1;
            }
            else if(temp->right==NULL){
                temp1=temp->left;
                
                delete temp;
                //temp=NULL;
                return temp1;
            }
            else{
                temp1=minValue(temp->right);
                temp->info=temp1->info;
                temp->right=deleteNode(temp1->info,temp->right);    
            }  
           
    }   
     return temp;    
}
void inorder(Node *temp){


    if (root == NULL){
        
        return;

    }

    if(temp->left!= NULL){

        inorder(temp->left);
    }
if(counter>1 && counter <=3){
    cout<<temp->info<<endl;
   
}
 counter++;
    if(temp->right!= NULL){

        inorder(temp->right);
    }
}

int height(Node *temp){
    int leftheight,rightheight;
    if (temp==NULL){
        return -1;
    }
    else{
        leftheight=height(temp->left);
        rightheight=height(temp->right);
        if(leftheight>rightheight){
            return leftheight+1;
        }
        else
        return rightheight+1;

    }
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
b.insert(5,b.root);
b.insert(2,b.root);


b.inorder(b.root);


    return 0;
}



