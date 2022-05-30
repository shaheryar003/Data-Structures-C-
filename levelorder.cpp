  void row( Node *& temp)
        {
            if ( temp -> left != NULL)
                cout << temp -> left -> data << "\t";
            
            if ( temp -> right != NULL)
            cout << temp -> right -> data << "\t";

            return;
        }
 
 void print_level( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp == root)
            {
                cout << temp -> data << "\t";
                cout << temp -> left -> data << "\t";
                cout << temp -> right -> data << "\t";
            }

            if ( temp -> left != NULL)
                row( temp -> left);

            if ( temp -> right != NULL)
                row( temp -> right);

            if ( temp -> left != NULL)
                print_level( temp -> left);

            if ( temp -> right != NULL)
                print_level( temp -> right);

            return;
        }