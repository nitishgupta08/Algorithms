//Finding nth fibonacci number;

#include <iostream>

using namespace std;


//Simple Recusrion
//Time complexity: O(2^n)
//Space complexity: O(call stack)
int fib(int n) {

    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

//Dynamic Programming
//Time complexity: O(n)
//Space complexity: O(n)
int fibdp(int n) {
  if(n == 0 || n == 1)
    return n;
  int nums[n+1];
  nums[0] = 0;
  nums[1] = 1;
  for(int i=2;i<n+1;i++) {
    nums[i] = nums[i-1] + nums[i-2];
  }
  return nums[n];
}

//Optimizing space
//Time complexity: O(n)
//Space complexity: O(1)
int fibspa(int n) {
  if(n == 0 || n == 1)
    return n;
  
  int  a = 0, b = 1,c;

  for(int i=2;i<n+1;i++) {
    c = a+b;
    a = b; 
    b = c;
  }
  return c;
}



int main() {
  int n=7;
  cout << fibspa(n) << endl; 
  cout << fib(n) << endl; 
  cout << fibdp(n) << endl; 
}