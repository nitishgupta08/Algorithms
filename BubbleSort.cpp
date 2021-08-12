#include <iostream>

using namespace std;

void BubbleSort(int *A, int n) {
    int flag = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(A[j] > A[j+1]) {
                swap(A[j],A[j+1]);
                flag++;
            }
        }
        if(flag == 0) {
            cout << "Array is Sorted\n";
            return;
        }
    }

    cout << "Sorted Array(Bubble Sort): ";
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter array elements: ";
    for(int i=0;i<n;i++)
        cin >> A[i];

    BubbleSort(A,n);
}