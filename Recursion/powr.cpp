//To find power using two positive numbers.
//Solved for negative in leetcode.


#include <iostream>

using namespace std;

//Time complexity: O(n)
//Space Complexity: O(size of call stack)
int powr(int m, int n) {
    if(n == 0)
        return 1;
    else
        return powr(m,n-1)*m;
}

//Divide And Conquer paradigm
//Time complexity: O(log(n))
//Space Complexity: O(size of call stack)
int pow(int m, int n) {
    if (n == 0)
        return 1;
    int temp = pow(m,n/2);
    else if( n%2 == 0) 
        return temp*temp;
    else
        return m*temp*temp;
}

//Time complexity: O(log(exp))
//Space Complexity: O(1)
int power(int x, int y) {
    int res = 1; 
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1; 
        x = x * x; 
    }
    return res;
}

int main() {
    int m = 2, n = 5,total = 0,t = 0;
    total = powr(m,n);
    cout << total << endl;
    t = pow(m,n);
    cout << t << endl;
}