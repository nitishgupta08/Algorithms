/*
 * Created Date: Sunday, August 15th 2021, 11:07:01 am
 * Author: Nitish Kumar Gupta
 * 
 * Copyright (c) 2021 nitishgupta
 */



#include <iostream>

using namespace std;

void merge(int *arr,int l, int mid, int h) {
  int i=l,j=mid+1,k=l;
  int temp[100];
  while(i<=mid && j<=h) {
    if(arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  for(;i<=mid;i++) temp[k++] = arr[i];
  for(;j<=h;j++) temp[k++] = arr[j];

  for(i=l;i<=h;i++) arr[i] = temp[i];
}


void mergeSort(int *arr,int n) {
  int p,l,mid,h,i;
  for(p=2;p<=n;p*=2) {
    for(i=0;p+i-1<n;i++) {
      l = i;
      h = p+i-1;
      mid = (l+h)/2;
      merge(arr,l,mid,h);
      if((n-1)>p/2) {
        l = i;
        h = p+i-1;
        mid = (l+h)/2;
        merge(arr,l,mid,n-1);
      }
    }
  }

  if(p/2<n) merge(arr,0,p/2-1,n-1);
}


int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  int A[n];
  cout << "Enter array elements: ";
  for(int i=0;i<n;i++)
      cin >> A[i];
    
  mergeSort(A,n);

	cout << "Sorted Array(Iterative Merge Sort): ";
  for(int i=0;i<n;i++)
    cout << A[i] << " ";
  cout << "\n";
}