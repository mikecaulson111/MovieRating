#include <iostream>
#include <string>
#include <fstream>

#include "bst.hpp"
#include "ll.hpp"
#include "get_string.hpp"

using namespace std;

void initMovie(BST *bst)
{
    int response_value = -1;
    string movieName;
    string strYear;
    string strRating;
    string review;
    int year;
    int rating;

    cout << "Please enter the name of the movie:" << endl;
    getline(cin, movieName);

    cout << "Please enter the year this movie was created:" << endl;
    getline(cin, strYear);
    year = get_int_from_string(strYear);
    
    if ( 0 >= year )
    {
        printf("ERROR, only enter a year greater than 0\n");
        return;
    }

    cout << "Please enter your rating out of 10:" << endl;
    getline(cin, strRating);
    rating = get_int_from_string(strRating);

    if ( -1 >= rating || 11 <= rating )
    {
        printf("ERROR, only enter a rating between 0 and 10\n");
    }

    cout << "Please enter a review for this movie or press enter" << endl;
    getline(cin, review);

    cout << endl; // add a gap

    response_value = bst->addMovie(movieName, year, rating, review);

    if ( -1 == response_value )
    {
        cout << "error, failure creating movie" << endl;
    }

    return;
}

int main(int argc, char *argv[])
{
    fstream fout;
    // fout.open("MovieRatings.csv",std::fstream::in | std::fstream::out | std::fstream::app); // to append to file
    fout.open("MovieRatings.csv",std::fstream::in | std::fstream::out | std::fstream::trunc); // to overwrite file

    BST *b;
    b = new BST();

    string choice;
    int integer_choice;
    int success_to_file = -1;

    printf("Hello and welcome to my app\n");
    while ( true )
    {
        printf("\n\n\n\nPlease choose an option below:\n");
        printf("[1] Add movie to list\n");
        printf("[2] Print list\n");
        printf("[3] Update value\n");
        printf("[4] Quit\n");

        getline(cin, choice);
        integer_choice = get_int_from_string(choice);

        if ( -1 < integer_choice )
        {
            if ( 4 >= integer_choice && 0 < integer_choice )
            {
                if ( 1 == integer_choice )
                {
                    initMovie(b);
                }
                else if ( 2 == integer_choice )
                {
                    b->printMovies();
                }
                else if ( 3 == integer_choice )
                {
                    b->update();
                }
                else if ( 4 == integer_choice )
                {
                    printf("\n\nSAVING TO FILE...\n\n");
                    // add file saving here:

                    success_to_file = b->save_to_file(fout);

                    if ( success_to_file == -1 )
                    {
                        printf("FAILED TO SAVE TO FILE\n");
                    }

                    fout.close();
                    printf("Finished, goodbye\n");
                    break;
                }
            }
            else
            {
                cout << "Please only enter a digit between 1 and 3" << endl;
            }
        }
        else
        {
            cout << "Please only enter a number" << endl;
        }
    }
    return 0;
}