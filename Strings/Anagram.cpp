//Checks if two strings are anagram

#include <iostream>

using namespace std;

int main() {
    char A[]  = "medical";
    char B[]  = "decimal";
    int H[26] = {0},i;

    for(i=0;A[i] != '\0';i++)
        H[A[i]-97]++;

    for(i=0;B[i] != '\0';i++) {
        H[B[i]-97]--;
        if(H[B[i]-97] == -1) {
            cout << "Not an Anagram" << endl;
            break;
        }
    }
    if(B[i] == '\0')
        cout << "It is an Anagram" << endl;
}