/*
 * Created Date: Friday, February 26th 2021, 3:24:25 pm
 * Author: Nitish Kumar Gupta
 * 
 * Copyright (c) 2021 nitishgupta
 */


#include <iostream>

using namespace std;

void Merge(int *arr, int l, int m, int r)
{
	int s1 = m - l + 1;
	int s2 = r - m;

	int L[s1], R[s2];

	for (int i = 0; i < s1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < s2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0,j=0,k=l;

	while (i < s1 && j < s2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < s1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < s2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int *arr,int l,int r){
	if(l>=r){
		return;
	}
	int m =l+ (r-l)/2;
	MergeSort(arr,l,m);
	MergeSort(arr,m+1,r);
	Merge(arr,l,m,r);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter array elements: ";
    for(int i=0;i<n;i++)
        cin >> A[i];

    MergeSort(A,0,n-1);

	cout << "Sorted Array(Merge Sort): ";
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << "\n";
}
