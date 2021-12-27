#include <iostream>
using namespace std;

struct Node {
int info;

Node *left,*right;
bool leftBit,rightBit;
};

class bstThreaded{
    public:
Node *root,*dummy,*temp,*temp1;


bstThreaded(){

    root=NULL;
    dummy= new Node;
    dummy->right=dummy;
    dummy->rightBit=1;  //1 == child
    dummy->left=dummy;
    dummy->leftBit=0; // 0 == thread

}


void insert(int key, Node *&temp){

  
    
    if(root==NULL){
        root=new Node;
        root->info= key;
        dummy->left=root;
        dummy->leftBit=1;

        root->left=dummy;
        root->leftBit=0;
        
        root->right=dummy;
        root->rightBit=0;
    }

  

     if(key<temp->info){
         if(temp->leftBit==0){
             temp1= new Node;
             temp1->info=key;
             
            temp1->left=temp->left;
            temp->left=temp1;
            temp1->rightBit=0;
            temp1->leftBit=temp->leftBit;
            temp->leftBit=1;
            temp1->right=temp;
            return;

         }
         else
        insert(key,temp->left);
        return;

    }


    if(key>temp->info){
        if(temp->rightBit==0){
             temp1= new Node;
             temp1->info=key;
             
            temp1->right=temp->right;
            temp->right=temp1;
            temp1->leftBit=0;
            
            temp1->rightBit=temp->rightBit;
            temp->rightBit=1;
            temp1->left=temp;
            return;

         }
         else
        insert(key,temp->right);
        return;
    }
   
}

void deletion(int key,Node *temp)
    {
    if(root==NULL)
    {
        cout<<"Khali hai "<<endl;
        return;
    }
    if(temp->left->info==key)
    {
        Delete_Node(temp->left,temp);
        return;
    }
    if (temp!=dummy && temp->right->info==key)
    {
        Delete_Node(temp->right,temp);
        return;
    }
    if(temp==dummy)
    {
        deletion(key,temp->left);
        return;
    }



    if(key<temp->info && temp->leftBit==1)
    {
        deletion(key,temp->left);
        return;
    }
    if(key>temp->info)
    {
        deletion(key,temp->right);
        return;
    }
    cout<<"Value doesnt exist"<<endl;
    return;
}


void Delete_Node(Node * temp, Node * parent){
   if(temp->leftBit==1 && temp->rightBit==1)
    {
        Node *successor_parent=temp;
        Node *successor=findsuccessor(temp->right,successor_parent);
        temp->info=successor->info;
        Delete_Node(successor,successor_parent);
        return;
    }
    if(temp->leftBit==1 && temp->rightBit==0)
    {
                if(temp->info<parent->info)
        {
            parent->left=temp->left;
            parent->leftBit=temp->leftBit;
        }
        else
        {
            parent->right=temp->left;
            parent->rightBit=temp->leftBit;
        }
        Node *temp2=temp->left;
        while(temp2->rightBit!=0)
        {
            temp2=temp2->right;
        }
        temp2->right=temp->right;
        delete temp;
        return;

    }
    if(temp->rightBit==1 && temp->leftBit==0)
    {
        
        if(temp->info>parent->info)
        {
            parent->right=temp->right;
            parent->rightBit=temp->rightBit;
        }
        else
        {
            parent->left=temp->right;
            parent->leftBit=temp->rightBit;
        }
        Node *temp2=temp->right;
        while(temp2->leftBit!=0)
        {
            temp2=temp2->left;
        }
        temp2->left=temp->left;
        delete temp;
        return;
    }
    if(temp->leftBit==0 && temp->rightBit==0)
    {
        if(parent->left==temp)
        {
            parent->left=temp->left;
            parent->leftBit=0;
        }
        if(parent->right==temp && parent!=dummy)
        {
            parent->right=temp->right;
            parent->rightBit=0;
        }
        if(temp==root)
        {
            root=NULL;
            dummy->left=dummy;
            dummy->leftBit=0;
        }
        delete temp;
    }


}


Node * findsuccessor(Node *temp,Node *& parent){
    if(temp->leftBit==0){
        return temp;
    }
    parent=temp;
    return findsuccessor(temp->left,parent);
}

void inorder(Node *temp)
    {
        if(root==NULL)
        {
            return;
        }
        if(temp->leftBit!=0)
        {
            inorder(temp->left);
        }
        cout<<temp->info<<endl;
        if(temp->rightBit!=0)
        {
            inorder(temp->right);
        }
    }


};

int main(){
  
  bstThreaded b;
  b.insert(100,b.root);
  b.insert(50,b.root);
  b.insert(90,b.root);
  b.insert(80,b.root);
  b.insert(70,b.root);
  b.inorder(b.root);      
  b.deletion(50,b.dummy);
  cout<<"done\n";    
  b.inorder(b.root);
    
return 0;
}