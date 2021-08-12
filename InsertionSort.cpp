#include <iostream>

using namespace std;

void InsertionSort(int *arr,int n) {
    for(int i=1;i<n;i++) {
        int j = i-1;
        int key = arr[i];
        while(arr[j] > key && j>= 0) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    cout << "Sorted Array(Insertion Sort): ";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
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

    InsertionSort(A,n);
}