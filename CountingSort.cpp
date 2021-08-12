#include <iostream>

using namespace std;

void CountingSort(int *arr,int n) {
    int max = arr[0];
    for(int i=0;i<n;i++)
        if(arr[i] > max)
            max = arr[i];
    
    int *count;
    count = new int[max+1];
    int B[n];

    for(int i=0;i<n;i++) 
        count[arr[i]]++;
    
    for(int i=1;i<max+1;i++)
        count[i] = count[i] + count[i-1];
    
    for(int i=n-1;i>=0;i--) {
        B[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)
        arr[i] = B[i];
    delete[] count;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter array elements: ";
    for(int i=0;i<n;i++)
        cin >> A[i];
    
    CountingSort(A,n);

	cout << "Sorted Array(Counting Sort): ";
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << "\n";
}