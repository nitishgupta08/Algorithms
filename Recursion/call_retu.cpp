//To understand head and tail recursion

#include <iostream>

using namespace std;

void fun1(int n) { //procrssing is done at calling (Tail Recursion)
    if(n > 0) {
        cout << n << " ";
        fun1(n-1);
    }
}

void fun2(int n) { //processing is done at returning(Head Recursion)
    if(n > 0) {
        fun2(n-1);
        cout << n << " ";
    }
}

int main() { 
    int n=5; 
    cout << "Print while calling: ";
    fun1(n);
    cout << endl;
    cout << "Print while returning: ";
    fun2(n);
    cout << endl;
}


