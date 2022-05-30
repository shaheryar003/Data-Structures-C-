#include <iostream>
#include <cmath>
using namespace std;

// MERGE SORT { 

void Merge(int arr[], int left, int mid, int right)
{
    int LeftSize = mid - left + 1;
    int RightSize = right - mid;

    int LeftArr[ LeftSize];
    int RightArr[ RightSize];

    for ( int i = 0; i < LeftSize; i++)
        LeftArr[i] = arr[ left + i];

    for ( int i = 0; i < RightSize; i++)
        RightArr[i] = arr[ mid + 1 + i];

    int indexLeft = 0, indexRight = 0, indexMerged = left;

    while ( indexLeft < LeftSize && indexRight < RightSize)
    {
        if ( LeftArr[indexLeft] <= RightArr[indexRight])
        {
            arr[indexMerged] = LeftArr[indexLeft];
            indexLeft++;
        }
        else
        {
            arr[indexMerged] = RightArr[indexRight];
            indexRight++;
        }
        indexMerged++;
    }

    while ( indexLeft < LeftSize)
    {
        arr[indexMerged] = LeftArr[indexLeft];
        indexLeft++;
        indexMerged++;
    }

    while ( indexRight < RightSize)
    {
        arr[indexMerged] = RightArr[indexRight];
        indexRight++;
        indexMerged++;
    }
}

void MergeSort( int arr[], int l, int r)
{
    if ( l >= r)
        return;

    int mid = (( r - l) / 2) + l;

    MergeSort( arr, l, mid);
    MergeSort( arr, mid+1, r);
    Merge( arr, l, mid, r);
}

// MERGE SORT }


void BubbleSort( int arr[], int size)
{
    for ( int i = 0; i < size - 1; i++)
    {
        for ( int j = 0; j < size - i - 1; j++)
        {
            if ( arr[j+1] < arr[j])
            {
                int swap = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = swap;
            }
        }
    }
}

int BinarySearch( int arr[], int l, int r, int key)
{
    if ( r >= l)
    {
        int mid = (( r - l) / 2) + l;

        if ( key == arr[mid])
            return mid;

        if ( key < arr[mid])
            return BinarySearch( arr, l, mid, key);

        if ( key > arr[mid])
            return BinarySearch( arr, mid + 1, r, key);
    }

    else
    {
        cout << "Not found." << endl;
        return -1;
    }
}

void print( int arr[], int size)
{
    cout << endl;

    for ( int i = 0; i < size; i++)
        cout << arr[i] << "\t";

    cout << endl;

    return;
}

int main()
{
    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof( arr) / sizeof( arr[0]);

    cout << "\nBefore Merge Sort:" << endl;
    print( arr, size);
    
    MergeSort( arr, 0, size-1);

    cout << "\nAfter Merge Sort:" << endl;
    print( arr, size);
}