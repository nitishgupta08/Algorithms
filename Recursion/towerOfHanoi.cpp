//Tower of hanoi using recursion

#include <iostream>

using namespace std;

int count = 0;
void towerOfHanoi(int n, char A, char B, char C) {
    if(n > 0) {
        towerOfHanoi(n-1,A,C,B);
        ::count++;
        cout << A << " to " << C << endl;
        towerOfHanoi(n-1,B,A,C);
    }
}

int main() {
  towerOfHanoi(4,'A','B','C');
  cout << "Total moves: " << ::count << endl;
}