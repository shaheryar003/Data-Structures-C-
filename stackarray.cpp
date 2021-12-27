#include <iostream>
using namespace std;
class stack{
int *top,*stackArray;
int size,num;
public:
stack(){
    top=NULL;
    cout<<"Enter size of Array: \n";
    cin>>size;
    stackArray =new int [size];
}
void push(){
    if(top==NULL){
        top=stackArray;
        cout<<"\nEnter Value: ";
        cin>>num;
        *top=num;
        return;
    }
    if(top==(size-1)+stackArray){
        cout<<"\nOVER FLOW...";
        return;
    }
    top++;
    cout<<"\nEnter Value: ";
    cin>>num;
    *top=num;
}

void pop(){
    if(top==NULL){
        cout<<"\nUNDER FLOW...";
        return;
    }
    
    
    if(top==stackArray){
        top=NULL;
        return;
    }
    top--;
    return;

}

void printTop(){
    if(top==NULL){
        cout<<"\nUNDER FLOW";
        return;
    }
    cout<<*top<<endl;
}
void printAll(){
    while(top!=NULL){
        cout<<endl<<*top<<endl;
        pop();
    }
}

};



int main(){

    stack s;
    s.push();
    s.push();
    s.push();
    s.push();
    s.push();
    s.printAll();
    
    s.pop();
    

    return 0;
}