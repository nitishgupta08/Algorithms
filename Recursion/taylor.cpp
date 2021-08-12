//Time complexity: O(n2)
//Space complexity: O(call stack)
//Calculating taylor sum
#include <iostream>

using namespace std;

double taylor(int x,int n) {
    static double p=1,f=1;
    double r;
    if(n == 0)
        return 1;
    else {
        r = taylor(x,n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }
}

int main() {
  int x = 1,n = 5;
  double total;
  total = taylor(x,n);
  cout << total << endl;
}