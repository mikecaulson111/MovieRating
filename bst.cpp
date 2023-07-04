#include "bst.hpp"
// #include "ll.hpp" 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int file_saver(fstream& file, LLNode* node)
{
    int checker = -1;

    if ( node == NULL )
    {
        return 1;
    }

    file_saver(file, node->left);
    //save to file
    file << node->character << endl;
    checker = node->list->list_file_save(file);
    if (checker == -1)
    {
        return -1;
    }
    file_saver(file, node->right);
    return 1;
}

int BST::save_to_file(fstream& file)
{
    int bst_file_check = -1;
    bst_file_check = file_saver(file, root);
    return bst_file_check;
}

int BST::addMovie(string name, int year, int rating, string review)
{
    if ( this->root == NULL )
    {
        // need to make a new linked list, so should call ll.addNode to create a new linked list and add node:
        LLNode *temp = new LLNode;

        LL *list = new LL();
        list->addElement(name, year, rating, review);
        temp->character = name[0];
        temp->list = list;
        temp->left = NULL;
        temp->right = NULL;

        root = temp;

        return 1;
    }
    else
    {
        char tempChar = name[0];
        LLNode *temp = root;
        LLNode *prev = NULL;
        bool right = false;

        while ( temp != NULL && temp->character != tempChar )
        {
            if ( tempChar < temp->character )
            {
                prev = temp;
                temp = temp->left;
                right = false;
            }
            else
            {
                prev = temp;
                temp = temp->right;
                right = true;
            }
        }

        if ( NULL != temp && temp->character == tempChar )
        {
            temp->list->addElement(name, year, rating, review);
            return 1;
        }
        else
        {
            LLNode* tempNode = new LLNode();
            LL *list = new LL();
            list->addElement(name, year, rating, review);
            tempNode->character = tempChar;
            tempNode->list = list;
            tempNode->left = NULL;
            tempNode->right = NULL;

            if ( right == true )
            {
                prev->right = tempNode;
            }
            else
            {
                prev->left = tempNode;
            }
            return 1;
        }
    }
    return -1;
}

void bstprinter(LLNode* node)
{
    if ( node == NULL )
    {
        return;
    }

    bstprinter(node->left);
    cout << "Movies that start with " << node->character << endl;
    node->list->printList();
    cout << endl;
    bstprinter(node->right);
}

void BST::printMovies() {
    bstprinter(root);
}

int findChar(LLNode *node, char c, string name_to_update)
{
    int status = -1;
    if ( NULL == node )
    {
        return 2; 
    }
    else if ( node->character == c )
    {
        status = node->list->find_movie(name_to_update);

        return status;
    }
    else if ( node->character > c )
    {
        findChar(node->left, c, name_to_update);
    }
    else
    {
        findChar(node->right, c, name_to_update);
    }

    return -1;
}

void BST::update()
{
    string name_to_update;
    int status = -1;

    cout << "Please enter the name of the movie that you would like to update:" << endl;

    getline(cin, name_to_update);

    status = findChar(root, name_to_update.at(0), name_to_update); // 2 on fail to get char, 1 on success, -1 to say no such movie
    
    if ( status == -1 )
    {
        cout << "ERROR, general error occured" << endl;
    }
    else if ( status == 2 )
    {
        cout << "ERROR, " << name_to_update << " not found in database" << endl;
    }
    else if ( status == 4 )
    {
        cout << "Going back" << endl;
    }
    else if ( status == 1 )
    {
        cout << "Success" << endl;
    }

    return;
}