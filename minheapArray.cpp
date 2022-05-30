#include <iostream>

using namespace std;
class heaps
{
public:
    int *minheap=new int[15];
    int *arr=new int[15];
    int sizes=0;
    int *check;
    heaps()
    {

        for(int i=1;i<=15;i++)
        {
            cout<<"Enter element : ";
            cin>>arr[i];
        }



    }
    void trasnfer()
    {
        if(sizes>15)
        {
            cout<<"Full"<<endl;
        }
        else
        {

            for(int i=1;i<=15;i++)
            {
                minheap[i]=arr[i];
                sizes++;
            }

        }


    }
    void buildheap()
    {

        check=minheap;
        check++;
        for(int i=1;i<=15/2;i++)
        {
            if(*check>minheap[2*i])
            {
                int swaps=*check;
                *check=minheap[2*i];
                minheap[2*i]=swaps;
            }
            if(*check>minheap[2*i+1])
            {
                int swaps=*check;
                *check=minheap[2*i+1];
                minheap[2*i+1]=swaps;
            }
            check++;

        }


    }
    void printheap()
    {
        check=minheap;
        check++;
        for(int i=1;i<=15;i++)
        {
            cout<<*check<<"     ";
            check++;
        }
    }

};

int main()
{
    heaps h;
    h.trasnfer();
    h.buildheap();
    h.buildheap();
    h.buildheap();
    h.buildheap();
    h.buildheap();
    h.buildheap();
    h.printheap();
}
