// Bit manupulation 
#include <iostream>
using namespace std;


// n & 1 == 0 ? EVEN : ODD
int checkEvenOdd(int n) {
	return n & 1;
}

//gets bit at ith position
int getBit(int n,int i) {
	n &= (1 << i);
	return n > 0 ? 1 : 0;
}

//set ith bit to 1
int setBit(int n, int i) {
	n |= (1 << i);
	return n;
}

//clear ith bit to 0
int clearBit(int n,int i) {
	// ~(1 << i) is a mask.
	n &= ~(1 << i);
	return n;
}

//clears bits from i to j
int clearRangeBits(int n,int i, int j) {
	int a = -1 << (j+1);
	int b = (1<<i) - 1;
	int mask = a | b;
	n &= mask;
	return n;
}

//updates bit to v = {0,1}
int updateBit(int n,int i, int v) {
	n = clearBit(n,i);
	n |= (v << i);
	return 0;
}


int main() {
	int n;
	cin >> n;
	cout << checkEvenOdd(n) << endl;
	cout << getBit(n,2) << endl;
	cout << setBit(n,6) << endl;
	cout << clearBit(n,9) << endl;
	cout << clearRangeBits(n,3,7) << endl;
	cout << updateBit(n,3,1) << endl;

}