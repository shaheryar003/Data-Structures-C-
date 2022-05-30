#include <iostream>
using namespace std;

struct Node{

int data;
Node *next,*previous;
};

class doubly{

public:
Node *head,*temp,*temp1;

doubly(){
    head=temp=NULL;
}

void add(int num){


    if(head==NULL){
        head=new Node;
        head->data=num;
        head->next=head->previous=NULL;
        return;
    }
    temp =head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(head!=NULL){
        temp1=new Node;
        temp1->data=num;
        temp1->next=temp->next;
        temp1->previous=temp;
        temp->next=temp1;
       
        return;
    }

}

void Delete(int num){
    
    if(head->data==num){
        temp=head;
        head=temp->next;
        head->previous=NULL;
        delete temp;
        temp=NULL;
        return;
    }
     
   
    if(head->data!=num){
        temp=head;
        while(temp!=NULL){
            if(temp->data==num){
        temp1=temp;
        if(temp->next==NULL){
            temp->previous->next=NULL;
            delete temp1;
            return;
        }
        temp->previous->next=temp->next;
        temp->next->previous=temp->previous;

        delete temp1;
        temp1=NULL;
        return;
        }
            temp=temp->next;
        }
       
        
    }

}
void print(){
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}

};

int main(){
    doubly l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.print();
    l.Delete(2);
    cout<<endl;
    l.print();
   
   
}