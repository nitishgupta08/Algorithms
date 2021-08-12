//Combinatrics
//Calculating nCr using nCr = (n-1)Cr + (n-1)C(r-1) 

#include <iostream>

using namespace std;

int C(int n, int r) {

    if(r == 0 || n == r)
        return 1;
    return C(n-1,r-1)+C(n-1,r);
}

int main() {
    int n = 10,r = 4,total = 0;
    total = C(10,4);
    cout << total << endl;
}