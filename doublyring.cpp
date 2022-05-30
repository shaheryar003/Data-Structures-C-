#include <iostream>
using namespace std;

struct Node
{   
    int data;
    Node *next,*previous;
};
class doubly{
    public:
    int count1=0;
    int count2=0;
Node *head,*temp,*temp1;

doubly(){
    head=temp=temp1=NULL;
}
void add(int num);
void Delete(int num);
void print();
void search(int num);


int searchfwd(int num, Node *&temp){

    if (temp==NULL){
        return NULL;
    }
    if(temp->data==num){       
        return count1;
    }
    if(temp->data!=num){
        count1++;
        searchfwd(num,temp->next);
    }
}

int searchbck(int num, Node *&temp){

    if (temp==NULL){
        return NULL;
    }
    if(temp->data==num){       
        return count2;
    }
    if(temp->data!=num){
        count2++;
        searchbck(num,temp->previous);
    }    
}

};
void doubly::search(int num){
if(searchfwd(num,head) <= searchbck(num,head)){
     cout<<"ITS EASY TO FIND BY GOING NEXT";
 }
 else
 cout<<"ITS EASY TO FIND BY GOING BACK";
}


void doubly::add(int num){

        if (head==NULL){
            head=new Node;
            head->data=num;
            head->next=head->previous=head;
            return;
        }
        temp=head;
        if(head!=NULL){
            while (temp->next!=head)
            {
              temp=temp->next;
            }
              if(temp->next==head){
                temp1 =new Node;
                temp1->data=num;
                temp1->next=temp->next;
                temp->next=temp1;
                temp1->previous=temp;
                head->previous=temp1;
              }
            
            
            
        }


}

void doubly::Delete(int num){

if(head==NULL){
    cout<<"NO NODE AVAILABLE " ;
    return;
}
temp=head;
if(head->data==num){
if(head->next==head){
    delete head;
    head=NULL;
    cout<<"\nNODE DELETED";
   
    return;
}

}
while(temp->data!=num){   
    temp=temp->next;
}

if(temp==head){
    head=head->next;
}


temp->next->previous=temp->previous;
temp->previous->next=temp->next;
delete temp;
temp=NULL;
cout<<"\nNODE DELETED\n";

return;

}


void doubly::print(){
temp=head;
do{
    cout<<temp->data<<" ";
    temp=temp->next;
}
while(temp!=head);
}




int main(){
    doubly d;
    d.add(1);
    d.add(2);
    d.add(3);
    d.add(4);
    d.add(5);
    
    // d.Delete(1);
    // d.Delete(4);
    
    d.print();

    d.search(4);


 

  
    

    return 0;
}