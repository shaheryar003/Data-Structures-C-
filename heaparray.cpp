#include <iostream>
using namespace std;

class minheap{
public:
int currentsize=0;
int index;
int heap[10]={};
int size=0;

int array[10]={2,3,6,7,9,8,4,1,5,0};





void insert(int key){

  if(currentsize==size){
      cout<<"HEAP OVERFLOW";
      return;
  }
  currentsize++;
  index=currentsize-1;
  heap[index]=key;
  while(index!=0 && heap[parent(index)]>heap[index]){
      swap(heap[index],heap[parent(index)]);
      index=parent(index);
  }


}

int parent(int ind){
    return (ind-1)/2;

}


void print(){
    
for (int i =0; i<10;i++){
    cout<<array[i]<<"\t";
    size+=1;
}
cout<<endl;

}

void printNew(){
    
for (int i =0; i<10;i++){
    cout<<heap[i]<<"\t";
    
}
cout<<endl;
}
}; 
void swap(int &x, int &y){
    int temp =x;
    x=y;
    y = temp;
}
int main(){

minheap m;

m.print();


cout<<endl;

for(int i=0;i<10;i++){
    m.insert(m.array[i]);
}

m.printNew();
return 0;
}
