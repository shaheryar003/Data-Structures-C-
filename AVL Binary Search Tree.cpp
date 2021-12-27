#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// BST: Left Child Node is less than Parent, Right Child Node is greater than Parent.
class BST
{
    private:

        Node *root, *temp, *temp1;

    public:

        BST()
        {
            root = NULL;
        }

        Node * getRoot()
        {
            return root;
        }

        // Unbalanced due to insertion in Left subtree of Left child. ( Right rotation on unbalanced Node).
        void leftleft( Node *& temp)
        {
            temp1 = temp -> left;               // temp1 on left child of unbalanced Node
            temp -> left = temp1 -> right;
            temp1 -> right = temp;
            temp = temp1;

            temp1 = NULL;
            return;
        }

        // Unbalanced due to insertion in Right subtree of Right child. ( Left rotation on unbalanced Node).
        void rightright( Node *& temp)
        {
            temp1 = temp -> right;              // temp1 on right child of unbalanced Node
            temp -> right = temp1 -> left;
            temp1 -> left = temp;
            temp = temp1;

            temp1 = NULL;
            return;
        }

        // Unbalanced due to insertion in Right subtree of Left child
        void leftright( Node *& temp)
        {
            rightright( temp -> left);          // left rotation on left child of unbalanced Node

            cout << "\n" << temp -> data;

            leftleft( temp);                   // right rotation on unbalanced Node

            return;
        }

        // Unbalanced due to insertion in Left subtree of Right child
        void rightleft( Node *& temp)
        {
            leftleft( temp -> right);           // right rotation on left child of unbalanced Node

            rightright( temp);                  // left rotation on unbalanced Node

            return;
        }

        
        void insert( int key, Node *& temp)
        {
            if ( temp == NULL)
            {
                temp = new Node;
                temp -> data = key;
                temp -> right = temp -> left = NULL;
                
                if ( root == NULL)
                    root = temp;

                return;
            }

            if ( key == temp -> data)
            {
                cout << "\nDuplicate value." << endl;
                return;
            }

            if ( key > temp -> data)
            {
                insert ( key, temp -> right);
            }

            if ( key < temp -> data)
            {
                insert ( key, temp -> left);
            }

            /* To keep Binary Search Tree in AVL form */

            int balance = balanceFactor( temp);

            if ( balance == 2)
            {
                if ( key < temp -> left -> data)
                {
                    leftleft( temp);
                    return;
                }

                else
                {
                    leftright( temp);
                    return;
                }
            }

            if ( balance == -2)
            {

                if ( key > temp -> right -> data)
                {
                    rightright( temp);
                    return;
                }

                else
                {
                    rightleft( temp);
                    return;
                }
            }
        }

        // Searching data in BST. return ADDRESS of searched data.
        Node * search( int key, Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return NULL;
            }

            if ( temp -> data == key)
            {
                return temp;
            }

            if ( ( temp -> right != NULL) && ( key > temp -> data))
            {
                return search( key, temp -> right);
                
            }

            if ( ( temp -> left != NULL) && ( key < temp -> data))
            {
                return search( key, temp -> left);
            }

            if ( temp -> left == NULL && temp -> right == NULL)
            {
                cout << "\nData not found." << endl;
                return NULL;
            }
        }

        // Tree Traversal ( Pre Order )
        void print_pre( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            cout << temp -> data << "(balance factor = " << balanceFactor( temp) << ")\t";

            if ( temp -> left != NULL)
                print_pre( temp -> left);
            
            if ( temp -> right != NULL)
                print_pre( temp -> right);
            
            return;
        }

        // Tree Traversal ( In Order )
        void print_in( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp -> left != NULL)
                print_in( temp -> left);

            cout << temp -> data << "(balance factor = " << balanceFactor( temp) << ")\t";

            if ( temp -> right != NULL)
                print_in( temp -> right);
        }

        // Tree Traversal ( Post Order )
        void print_post( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp -> left != NULL)
                print_post( temp -> left);

            if ( temp -> right != NULL)
                print_post( temp -> right);
            
            cout << temp -> data << "\t";
        }

        Node * succesor( int key)
        {
            temp1 = NULL;

            temp = search( key, root);

            if ( temp -> right != NULL) // if right sub tree is not NULL
            {
                temp = temp -> right;

                if ( temp -> left != NULL) // if right subtree has a left subtree
                {
                    while ( temp -> left != NULL)
                    {
                        temp = temp -> left;
                    }
                }
                return temp;
            }

            temp = root;

            while ( temp -> data != key)
            {

                if ( temp -> data > key)
                {
                    temp1 = temp;
                }

                if ( ( temp -> right != NULL) && ( key > temp -> data))
                {
                    temp = temp -> right;

                    if ( temp -> data > key)
                    {
                        temp1 = temp;
                    }
                }

                if ( ( temp -> left != NULL) && ( key < temp -> data))
                {
                    temp = temp -> left;

                    if ( temp -> data > key)
                    {
                        temp1 = temp;
                    }
                }
            }

            if ( temp1 == NULL)
            {
                return NULL;
            }

            return temp1;
        }

        void deletion( int key, Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp -> left -> data == key)
            {
                if ( balanceFactor( temp) == 0)     // Case 1a
                {
                    temp1 = temp -> left;
                    temp -> left = NULL;

                    delete temp1;
                    temp1 = NULL;
                    return;
                }

                if ( balanceFactor( temp) == 1)     // Case 2a
                {
                    temp1 = temp -> left;
                    temp -> left = NULL;

                    delete temp1;
                    temp1 = NULL;

                    return;
                }

                if ( balanceFactor( temp) == -1)
                {
                    if ( balanceFactor( temp -> right) == 0)    // Case 3a
                    {
                        temp1 = temp -> left;
                        temp -> left = NULL;

                        delete temp1;
                        temp1 = NULL;

                        rightright( temp);
                        return;
                    }
                    
                    if ( balanceFactor( temp -> right) == 1)    // Case 4a
                    {
                        
                        temp1 = temp -> left;
                        temp -> left = NULL;

                        delete temp1;
                        temp1 = NULL;

                        rightleft( temp);
                        
                        return;
                    }

                    if ( balanceFactor( temp -> right) == -1) // CASE 5a
                    {
                        temp1 = temp -> left;
                        temp -> left = NULL;

                        delete temp1;
                        temp1 = NULL;

                        rightright( temp);

                        return;
                    }
                }
            }

            if ( temp -> right -> data == key)
            {
                if ( balanceFactor( temp) == 0)     // Case 1b
                {
                    temp1 = temp -> right;
                    temp -> right = NULL;

                    delete temp1;
                    temp1 = NULL;
                    return;
                }

                if ( balanceFactor( temp) == 1)     // Case 2b
                {
                    temp1 = temp -> right;
                    temp -> right = NULL;

                    delete temp1;
                    temp1 = NULL;

                    return;
                }

                if ( balanceFactor( temp) == -1)
                {
                    if ( balanceFactor( temp -> right) == 0)    // Case 3b
                    {
                        temp1 = temp -> right;
                        temp -> right = NULL;

                        delete temp1;
                        temp1 = NULL;

                        leftleft( temp);
                        return;
                    }
                    
                    if ( balanceFactor( temp -> right) == 1)    // Case 4b
                    {
                        temp1 = temp -> right;
                        temp -> right = NULL;

                        delete temp1;
                        temp1 = NULL;

                        leftright( temp);
                        
                        return;
                    }

                    if ( balanceFactor( temp -> right) == -1) // CASE 5a
                    {
                        temp1 = temp -> left;
                        temp -> left = NULL;

                        delete temp1;
                        temp1 = NULL;

                        rightright( temp);

                        return;
                    }
                }
            }

            if ( key < temp -> data)
            {
                deletion( key, temp -> left);
                return;
            }

            if ( key > temp -> data)
            {
                deletion( key, temp -> right);
                return;
            }
        }

        int maxDepth( Node *& temp)
        {
            if ( temp == NULL)
            {
                return -1;
            }

            else
            {
                int l = maxDepth( temp -> left);
                int r = maxDepth( temp -> right);

                if ( l > r)
                    return l + 1;
                else
                    return r + 1;
            }
        }

        int balanceFactor( Node * temp)
        {
            if ( temp == NULL)
            {
                cout << "\nTree is empty." << endl;
                return 0;
            }

            int balance = 0;

            balance = maxDepth( temp ->left) - maxDepth( temp -> right);

            return balance;
        }
};

int main()
{
    BST tree;

    Node * r = tree.getRoot(); // using getRoot function since root is a private class variable

    tree.insert( 5,  r);
    tree.insert( 2,  r);
    tree.insert( 7,  r);
    tree.insert( 1,  r);
    tree.insert( 4,  r);
    tree.insert( 6,  r);
    tree.insert( 9,  r);
    tree.insert( 3,  r);
    tree.insert( 16,  r);
    tree.insert( 15,  r);

    cout << endl;

    tree.print_pre(r);

    tree.deletion( 7, r);

    cout << endl;

    tree.print_pre(r);
}