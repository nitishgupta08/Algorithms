//Comparing strings

#include <iostream>
#include <string>

using namespace std;

int main() {
  	char A[20] = "012";
  	char B[20] = "120";
	int i=0;
	while(A[i] != '\0' && B[i] != '\0') {
		if(A[i] < B[i]) {
			cout << A << " comes before " << B << endl;
			break;
		}

		else if(A[i] > B[i]) {
			cout << A << " comes after " << B << endl;
			break;
		}
		i++;
	}

	if(i == strlen(A))
		cout << "Both words are equal" << endl;

}