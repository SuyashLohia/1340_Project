#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//This function compares two character arrays in a non case-sensitive way for Searching.
bool strcmp2(char *a, char *b)
{
    int lena = strlen(a);
    int lenb = strlen(b);
    
    for (int i = 0; i <= lena - lenb;i++){
        int count = 0;
        for (int j = 0; j <= lenb-1 ; j++){
            if (tolower(b[j]) != tolower(a[i+j])){
                break;
            }
            else{
                count++;
            }
        }
        if (count == lenb) {
            return true;
        }
    }
    return false;
}

