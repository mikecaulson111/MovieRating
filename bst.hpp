#ifndef BST_H
#define BST_H

#include "ll.hpp"


struct LLNode {
    char character;
    LL *list;
    LLNode* left;
    LLNode* right;
};


class BST {
    LLNode* root;

    public:
        BST()
        {
            root = NULL;
        }

        int addMovie(string name, int year, int rating, string review = "N/A");
        void printMovies();
        int save_to_file(fstream& file);
        void update();
};

#endif