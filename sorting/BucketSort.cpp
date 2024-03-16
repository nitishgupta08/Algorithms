/*
 * Created Date: Saturday, February 27th 2021, 2:28:13 pm
 * Author: GeeksforGeeks
 * I understood this code later.
 * 
 * Copyright (c) 2021 nitishgupta
 */


#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<float> &arr,int n) {
    for(int i=1;i<n;i++) {
        int j = i-1;
        int key = arr[i];
        while(arr[j] > key && j>= 0) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void BucketSort(float *arr, int n) {
    vector<float> bucket[n];
    int f;
    for(int i=0;i<n;i++) {
        f = n * arr[i];
        bucket[f].push_back(arr[i]);
    }

    for(int i=0;i<n;i++) {
        InsertionSort(bucket[i],bucket[i].size());
    }

    int t = 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<bucket[i].size();j++)
            arr[t++] = bucket[i][j];
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    float A[n];
    cout << "Enter array elements: ";
    for(int i=0;i<n;i++)
        cin >> A[i];
    
    BucketSort(A,n);

	cout << "Sorted Array(Bucket Sort): ";
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << "\n";
}