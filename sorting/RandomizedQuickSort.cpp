/*
 * Created Date: Friday, February 26th 2021, 4:24:03 pm
 * Author: Nitish Kumar Gupta
 * 
 * Copyright (c) 2021 nitishgupta
 */


#include <iostream>

using namespace std;

//left-most element is pivot
int partition(int *arr,int p,int r) {
    int pivot = arr[p];
    int i = p;
    int j = r;

    while(i<j) {
        while(arr[i] <= pivot && i <= r) 
            i = i+1;
        while(arr[j] > pivot && j >= p) 
            j = j-1;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[p],arr[j]);
    return j;
}

void RandomizedQuickSort(int *arr, int p, int r) {
    if(p<r) {
        srand(time(NULL));
        int k = p + rand() % (r-p);
        swap(arr[k],arr[r]);

        int q = partition(arr,p,r);
        RandomizedQuickSort(arr,p,q-1);
        RandomizedQuickSort(arr,q+1,r);
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

    RandomizedQuickSort(A,0,n-1);

	cout << "Sorted Array(Randomized Quick Sort): ";
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << "\n";
}