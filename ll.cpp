#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "ll.hpp"
#include "get_string.hpp"

using namespace std;

int LL::list_file_save(fstream& file)
{
    Node *temp = head;
    while(temp != NULL)
    {
        file << "" << ","
            << temp->name << ","
            << temp->year << ","
            << temp->rating << ","
            << temp->review << ","
            << temp->time << endl;
        
        temp = temp->next;
    }
    return 1;
}

void LL::addElement(string name, int year, int rating, string review)
{
    if ( head == NULL )
    {
        Node *tempNode = new Node();
        tempNode->name = name;
        tempNode->year = year;
        tempNode->rating = rating;
        tempNode->review = review;
        tempNode->previous = NULL;
        tempNode->next = NULL;
        tempNode->time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        head = tempNode;

        cout << "Added " << head->name << " as the head node" << endl;
    }
    else
    {
        Node *tempNode = head;
        while ( tempNode->next != NULL )
        {
            tempNode = tempNode->next;
        }

        Node *newNode = new Node();
        newNode->name = name;
        newNode->year = year;
        newNode->rating = rating;
        newNode->review = review;
        newNode->previous = tempNode;
        newNode->time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        newNode->next = NULL;
        
        tempNode->next = newNode;

        cout << "Added " << newNode->name << endl;
    }
}

void LL::printList()
{
    Node* place = head;
    while(place != NULL)
    {
        cout << place->name << ":" << place->year << " got a rating of " << place->rating << " with review: " << place->review << endl;
        place = place->next;
    }
}

int ll_find_movie(Node *node, string name_to_update)
{
    if ( node == NULL )
    {
        return 2;
    }
    else if ( 0 == node->name.compare(name_to_update) )
    {
        string input;
        int numInput;
        string strInput;
        int new_year;
        int new_rating;

        cout << "Please enter what part you would like to update for " << name_to_update << ":" << endl;
        cout << "[1] Name" << endl;
        cout << "[2] Year" << endl;
        cout << "[3] Rating" << endl;
        cout << "[4] Review" << endl;
        cout << "[5] Go Back" << endl;
        getline(cin, input);
        numInput = get_int_from_string(input);
        
        if ( -1 == numInput )
        {
            cout << "Please only enter a digit" << endl;
            return -1;
        }
        else if ( numInput <= 0 || numInput >= 6 )
        {
            cout << "Please only enter a digit between 1 and 5" << endl;
            return -1;
        }
        else
        {
            if ( 1 == numInput ) // could maybe use a generic parameter (template)
            {
                // do name change
                cout << "Please enter the new name of the movie " << name_to_update << ":" << endl;
                getline(cin, strInput);

                node->name = strInput;
                return 1;
            }
            else if ( 2 == numInput)
            {
                // do year change
                cout << "Please enter the new year of the movie " << name_to_update << ":" << endl;
                getline(cin, strInput);
                new_year = get_int_from_string(strInput);
                if ( -1 >= new_year )
                {
                    return -1;
                }
                else
                {
                    node->year = new_year;
                    return 1;
                }
            }
            else if ( 3 == numInput )
            {
                // do rating change
                cout << "Please enter the new rating of the movie " << name_to_update << ":" << endl;
                getline(cin, strInput);
                new_rating = get_int_from_string(strInput);
                if ( -1 >= new_rating )
                {
                    return -1;
                }
                else
                {
                    node->rating = new_rating;
                    return 1;
                }
            }
            else if ( 4 == numInput )
            {
                // do review change
                cout << "Please enter the new review of the movie " << name_to_update << ":" << endl;
                getline(cin, strInput);

                node->review = strInput;
                return 1;
            }
            else
            {
                return 4;
            }
        }
    }
    else
    {
        ll_find_movie(node->next, name_to_update);
    }
    return -1;
}

int LL::find_movie(string name_to_update)
{
    return(ll_find_movie(head, name_to_update));
}