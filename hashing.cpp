#include <iostream>
using namespace std;

class HashTable
{
    int *arr;
    int size, length;

    public:

        HashTable()
        {
            cout << "\nEnter Hash Table size: ";
            cin >> size;

            arr = new int[ size];

            for ( int i = 0; i < size; i++)
                arr[i] = -1;

            length = 0;
            return;
        }

        HashTable( int size)
        {
            this -> size = size;

            arr = new int[ size];

            for ( int i = 0; i < size; i++)
                arr[i] = -1;

            length = 0;
            return;
        }

        void insert( int key)
        {
            if ( length > size/2)
                ReHashing();

            if ( arr[ key % size] != -1)
            {
                for ( int i = key % size; i < size; i++)
                {
                    if ( arr[i] == -1)
                    {
                        arr[i] = key;
                        length++;
                        return;
                    }
                }

                for ( int i = 0; i < size; i++)
                {
                    if ( arr[i] == -1)
                    {
                        arr[i] = key;
                        length++;
                        return;
                    }
                }
            }

            else
            {
                arr[ key % size] = key;
                length++;
                return;
            }
        }

        int search( int key)
        {
            if ( arr[ key % size] == -1)                    // if location of searched key is empty
            {
                cout << "\nKey not found." << endl;
                return -1;
            }

            else if ( key == arr[ key % size])               // if key is found at hash function location
                return key % size;

            else
            {
                for ( int i = key % size; i < size; i++)    // circular search for key
                {
                    if ( key == arr[i])
                    return i;

                    if ( arr[i] == -1)                      // if searching ahead encounters empty slot, means key is not in hash table
                    {
                        cout << "\nKey not found." << endl;
                        return -1;
                    }
                }
                
                for ( int i = 0; i < size; i++)
                {
                    if ( arr[i] == key)
                        return i;

                    if ( arr[i] == -1)
                    {
                        cout << "\nKey not found." << endl;
                        return -1;
                    }
                }

                cout << "\nKey not found." << endl;
                return -1;
            }
        }

        void ReHashing()
        {
            cout << "\nReHashing..." << endl;
            
            size  = prime( size *2 );           /* Find nearest prime number for size of new reshashing array */
            int * arr1 = new int[size];

            for ( int i = 0; i < size; i++)
                arr1[i] = -1;

            for ( int i = 0; i < size/2; i++)
            {
                if ( arr[i] != -1)
                    arr1[ arr[i] % size] = arr[i];
            }

            arr = arr1;
            return;
        }

        
        int prime( int n)
        {
            bool isPrime = true;

            for ( int i = 2; i <= n / 2; ++i) 
            {
                if ( n % i == 0) 
                {
                    isPrime = false;
                    break;
                }
            }

            if ( isPrime)
                return n;
            
            else
                prime( n + 1);
        }
};

int main()
{
    HashTable h( 7);

    h.insert( 13);
    h.insert( 15);
    h.insert( 24);
    h.insert( 6);

    cout << h.search( 13) << endl;
    cout << h.search( 15) << endl;
    cout << h.search( 24) << endl;
    cout << h.search( 6) << endl;

    // Re-Hashing
    h.insert( 23);

    cout << h.search( 13) << endl;
    cout << h.search( 15) << endl;
    cout << h.search( 24) << endl;
    cout << h.search( 23) << endl;
    cout << h.search( 6) << endl;
}