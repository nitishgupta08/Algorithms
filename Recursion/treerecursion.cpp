//Tree Recursion: A function that calls itself multiple times.
//Simple recursion to understand
//Trace it to match with output

#include <iostream>

using namespace std;

void fun(int n) {
    if(n > 0) {
        cout << n << " ";
        fun(n-1); //Tail Recursion
        fun(n-1);
    }
}

int main() {
  int n = 3;
  fun(n);
}