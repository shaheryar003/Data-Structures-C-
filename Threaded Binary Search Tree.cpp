#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    int leftBit, rightBit;  /*  1 = child ||  0 = thread */
};

class ThreadedBinarySearchTree
{
    public:
        Node *root, *temp, *temp1;

        // Threaded Binary Search Tree

        Node *dummy;        // Dummy -> data = -1

        ThreadedBinarySearchTree()
        {
            root = NULL;

            dummy = new Node;

            dummy -> data = -1;

            dummy -> right = dummy;
            dummy -> rightBit = 1;

            dummy -> left = dummy;
            dummy -> leftBit = 0;
        }
        
        void insert( int key, Node *& temp)
        {
                
            if ( root == NULL)
            {   
                root = new Node;
                dummy -> left = root;
                dummy -> leftBit = 1;

                root -> left = dummy;
                root -> leftBit = 0;
                    
                root -> right = dummy;
                root -> rightBit = 0;

                root -> data = key;
                
                return;
            }

            if ( key == temp -> data)
            {
                cout << "\nDuplicate value." << endl;
                return;
            }

            if ( key > temp -> data)
            {
                if ( temp -> rightBit == 0)
                {
                    temp1 = new Node;
                    temp1 -> data = key;
                    
                    temp1 -> right = temp -> right;
                    temp1 -> rightBit = temp -> rightBit;

                    temp -> right = temp1;
                    temp -> rightBit = 1;

                    temp1 -> left = temp;
                    temp1 -> leftBit = 0;

                    return;
                }
                insert ( key, temp -> right);
            }

            if ( key < temp -> data)
            {
                if ( temp -> leftBit == 0)
                {
                    temp1 = new Node;
                    temp1 -> data = key;
                    
                    temp1 -> left = temp -> left;
                    temp1 -> leftBit = temp -> leftBit;

                    temp -> left = temp1;
                    temp -> leftBit = 1;

                    temp1 -> right = temp;
                    temp1 -> rightBit = 0;

                    return;
                }
                insert ( key, temp -> left);
            }
        }

        void deletion( int key, Node *& temp)
        {
            if ( temp -> left -> data == key)
            {
                temp1 = temp -> left;

                if ( temp1 -> leftBit == 0 && temp1 -> rightBit == 0) // Leaf Node Deletion. Node to be deleted has NO children.
                {
                    temp -> left = temp1 -> left;
                    temp -> leftBit = temp1 -> leftBit;

                    delete temp1;
                    temp1 = NULL;
                    return;
                }

                if ( temp1 -> leftBit == 1)     // Node to be deleted has ONE child. Left Child
                {
                    temp -> left = temp1 -> left;
                    temp1 -> left -> right = temp1 -> right;
                    temp1 -> left -> rightBit = temp1 -> rightBit;

                    delete temp1;
                    temp1 = NULL;
                    return;
                }

                if ( temp1 -> rightBit == 1)    // Node to be deleted has ONE child . Right Child
                {
                    temp -> right = temp1 -> right;
                    temp1 -> right -> left = temp1 -> left;
                    temp1 -> right -> leftBit = temp1 -> leftBit;

                    delete temp1;
                    temp1 = NULL;
                    return;
                }
            }
        }
};

int main()
{
    ThreadedBinarySearchTree tree;

    tree.insert( 6,  tree.root);
    tree.insert( 3,  tree.root);
    tree.insert( 8,  tree.root);
    tree.insert( 1,  tree.root);
    tree.insert( 5,  tree.root);
    tree.insert( 7,  tree.root);
    tree.insert( 11, tree.root);
    tree.insert( 9,  tree.root);
    tree.insert( 13, tree.root);
}