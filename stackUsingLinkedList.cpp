#include <iostream>

using namespace std;

struct Node{
    Node *previous;
    int info;
};
class Stack{
    Node *top,*temp;
    int data;
    public:
    Stack(){
        top=temp=NULL;
        
    }

    void push();
    void pop();
    void print();
};

void Stack::push(){
    if(top==NULL){
        top=new Node;
        cout<<"Enter Value: \n";
        cin>>top->info;
        top->previous=NULL;
       
        return;
    }
    else{
        temp=top;
        temp=new Node;
        cout<<"Enter Value: \n";
        cin>>temp->info;
        temp->previous=top;
        top=temp;
        
    }


}
void Stack::pop(){
    if(top==NULL){
        cout<<"\nUNDER FLOW\n";
        return;
    }
    temp=top;
    top=top->previous;
    delete temp;
    temp=NULL;
   // cout<<"\nDELETED";
    return;
    
}

void Stack::print(){

    if(top==NULL){
        cout<<"\nUNDER FLOW";
        return;
    }
    while(top!=NULL){
        cout<<endl<<top->info;
        pop();
    }

}




int main(){
    Stack s;
    s.push();
    s.push();
    s.push();
    s.push();
    s.push();
    s.print();
    s.pop();
    
    return 0;
}