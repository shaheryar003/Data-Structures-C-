 #include <iostream>
 using namespace std;
 struct Node {
     int info;
     Node* next;


 };
 class queue{
     public:
     Node *front, *rear,*temp;
     int size;
     queue(){
         front=rear=NULL;
         size=5;
     }

    void deque(){
        if(front==NULL){
            cout<<"EMPTY QUEUE";
            return;
        }
        temp=front;
        front=front->next;
        delete temp;
        if(front==NULL){
            rear=NULL;
        }
        return;
    }


    void enque(int num){
        if(front==NULL){
            front = new Node;
            front->info=num;
            rear=front;
            return;
        }
        else{
            temp = new Node;
            temp->info=num;
            rear->next=temp;
            rear=temp;
            rear->next=NULL;
            return;
        }



    }

 };
 
 
 
 int main(){
     queue q;
     q.enque(1);
     q.enque(2);
     q.enque(3);
     q.enque(4);
     q.deque();
     q.deque();

     return 0;
 }