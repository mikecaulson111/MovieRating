#include <string>
#include "get_string.hpp"

using namespace std;




// SHOULD PROBABLY CALL THIS AND THE HPP FILE UTILS OR SOMETHING LIKE THAT






int get_int_from_string(string str)
{
    int number = 0;
    for( int i = 0; i < str.length(); i++ )
    {
        number *= 10;
        switch (str.at(i))
        {
            case '0':
                number += 0;
                break;
            case '1':
                number += 1;
                break;
            case '2':
                number += 2;
                break;
            case '3':
                number += 3;
                break;
            case '4':
                number += 4;
                break;
            case '5':
                number += 5;
                break;
            case '6':
                number += 6;
                break;
            case '7':
                number += 7;
                break;
            case '8':
                number += 8;
                break;
            case '9':
                number += 9;
                break;
            default:
                return -1;

        }
    }
    return number;
}