//Check for palindrome

#include <iostream>
#include <string>

using namespace std;

int main() {
  	char A[20] = "1";
    int i=0,j=strlen(A)-1;
    while(i<j) {
        if(A[i] == A[j]) {
            i++;
            j--;
        }
        else {
            cout << "Not a palindrome" << endl;
            break;
        }
    }
    if(i >= j)
        cout << "It is a Palindrome" << endl;
}