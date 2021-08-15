/*
 * Created Date: Saturday, February 27th 2021, 12:08:14 am
 * Author: Nitish Kumar Gupta
 * 
 * Copyright (c) 2021 nitishgupta
 */


#include <iostream>

using namespace std;

void CountingSort(int *arr,int n,int place) {
    const int max = 9;
    int count[max+1] = {0};
    int B[n];

    for(int i=0;i<n;i++) 
        count[(arr[i]/place)%10]++;
    
    for(int i=1;i<max+1;i++)
        count[i] = count[i] + count[i-1];
    
    for(int i=n-1;i>=0;i--) {
        B[count[(arr[i]/place)%10]-1] = arr[i];
        count[(arr[i]/place)%10]--;
    }
    for(int i=0;i<n;i++)
        arr[i] = B[i];
}

void RadixSort(int *a,int n) {
    int max = a[0];
    for(int i=0;i<n;i++)
        if(a[i] > max)
            max = a[i];
    
    for(int place=1; max/place > 0; place *= 10) {
        CountingSort(a,n,place);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter array elements: ";
    for(int i=0;i<n;i++)
        cin >> A[i];
    
    RadixSort(A,n);

	cout << "Sorted Array(Radix Sort): ";
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << "\n";
}