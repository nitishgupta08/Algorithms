//calculates factorial

#include <iostream>

using namespace std;

long long int fact(long long int n) {
    if(n == 0)
        return 1;
    else
        return fact(n-1)*n;
}

int main() {
    long long int total = 0;
    total = fact(20);
    cout << total << endl;
}