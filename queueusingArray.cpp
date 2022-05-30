#include <iostream>
using namespace std;

class queueArray{
public:
int size;
int *front,*rear,*temp,*queue;
queueArray(){
    front=NULL;
    rear=NULL;
    size=5;
    queue= new int [size];

}
void enque(int num){
    if(front==NULL){
    front=queue;
    rear=queue;
    *front=num;
    return;
    }
    if(front==queue && rear == queue + size - 1){
        cout<<"\nQUEUE IS FULL\n";
        return;
    }
    if(rear+1==front){
        cout<<"\nQUEUE IS FULL\n";
        return;
    }
    if(front!=queue && rear == queue + size - 1){
    rear=queue;
    *rear=num;
    return;
    }
    rear++;
    *rear=num;

}
void dequeue(){
    if(front==NULL){
        cout<<"\nQUEUE IS EMPTY";
        return;
    }
    if(front==rear){
        front=rear=NULL;
        cout<<"\nDEQUED\n";
        return;
    }
    if(front==queue + size -1){
        front=queue;
        return;
    }

    front++;
    cout<<"\nDEQUED\n";
    

}

void print(){
    if(front==NULL){
        cout<<"\nQUEUE IS EMPTY";
        return;
        }

        temp=front;
    while (true){
         cout<<*temp<<" ";
        if(temp==rear){
            break;
        }
    if( temp== queue+size-1){
        if(temp==rear){
            break;
        }
        temp=queue;
    }
        else
        temp++;
       
        }
        
        temp=NULL;

  
}

};


int main(){
    queueArray q;
    q.enque(4);
    q.enque(7);
    q.enque(6);
    q.enque(4);
    q.enque(5);
    q.print();
    q.dequeue();
    q.print();
    cout<<"\nAFTER ENQUE:";
    q.enque(6);
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();



    return 0;
}