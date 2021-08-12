#include <iostream>

using namespace std;

void ShellSort(int *A,int n) {
    for (int gap=n/2; gap>=1; gap/=2){
        for (int j=gap; j<n; j++){
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp){
                A[i+gap] = A[i];
                i = i-gap;
            }
            A[i+gap] = temp;
        }
    }

    cout << "Sorted Array(Shell Sort): ";
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

    ShellSort(A,n);

}