/*
 * Created Date: Friday, February 26th 2021, 11:27:25 pm
 * Author: Nitish Kumar Gupta
 * 
 * Copyright (c) 2021 nitishgupta
 */


#include <iostream>

using namespace std;

void CountingSort(int *arr,int n) {
    //Finding Maximum in arr
    int max = arr[0];
    for(int i=0;i<n;i++)
        if(arr[i] > max)
            max = arr[i];
    
    //Creating a count array of size max+1;
    int *count;
    count = new int[max+1];
    for(int i=0;i<max+1;i++) count[i] = 0;

    //Filling the array;
    for(int i=0;i<n;i++) 
        count[arr[i]]++;

    //Filling sorted elements back to the original array
    int j=0;
    for(int i=0;i<max+1;i++) {
        if(count[i] != 0) {
            while(count[i] > 0) {
                arr[j++] = i;
                count[i]--;
            }
        } 
    }

    //release space
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