//Sum of first n numbers using recursion.

#include <iostream>

using namespace std;

int sumN(int n) {
    if(n==0){return 0;}

    return sumN(n-1) + n;
}

int SumIterative(int n) {
    int sum = 0;
    for(int i=1;i<=n;i++)
        sum += i;
    return sum;
}

int main() {
    int n = 10,sum=0;
    sum = sumN(n);
    cout << sum << endl;
}