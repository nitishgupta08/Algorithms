/*
 * Created Date: Friday, February 26th 2021, 9:29:55 am
 * Author: Nitish Kumar Gupta
 * 
 * Copyright (c) 2021 nitishgupta
 */

#include <iostream>

using namespace std;

void SelectionSort(int *A, int n) {
    int min;
    for(int i=0;i<n-1;i++) {
        min = i;
        for(int j=i+1;j<n;j++) {
            if(A[j] < A[min])
                min = j;
        }
        swap(A[i],A[min]);
    } 

    cout << "Sorted Array(Selection Sort): ";
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

    SelectionSort(A,n);
}