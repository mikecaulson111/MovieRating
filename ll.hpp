#ifndef LL_H
#define LL_H

#include <string>
// #include <time.h>
// #include <iostream>
#include <chrono>

using namespace std;

struct Node {
    string name;
    int year;
    int rating;
    string review;
    Node* next;
    Node* previous;
    // time_t time;
    // chrono::system_clock::duration time;
    uint64_t time;
};

class LL {
    Node* head;

    public:
        LL()
        {
            head = NULL;
        }
        void addElement(string name, int year, int rating, string review);
        void printList();
        int list_file_save(fstream& file);
        int find_movie(string name_to_update);
};

#endif