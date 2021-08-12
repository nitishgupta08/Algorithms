//Time complexity: O(n)
//Space complexity: O(call stack)
//Calculating taylor sum
#include <iostream>

using namespace std;

double taylor(int x,int n) {
    static double s=1;
    double r;
    if(n == 0)
        return s;

    s = (1+x*s/n);
    return taylor(x,n-1);
    
}

int main() {
  int x = 1,n = 5;
  double total;
  total = taylor(x,n);
  cout << total << endl;
}