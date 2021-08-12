//Array ADT
//Implemented data organisation + various operations

#include <iostream>

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;

public:
   
    //Constructor 1
    Array() {
        size = 10; 
        length = 0;
        A = new int[size];  //Deault size of array is 10 and length 0
    }

    //Constructor 2
    Array(int siz) {
        size = siz;
        length = 0;
        A = new int[size];
    }

    //Destructor
    ~Array() {
        delete []A;
    }

    //Various Operations on array ADT
    void display();
    void append(int x);
    void insert(int pos, int x);
    void deleteInd(int pos);
    bool LinearSearch(int x);
    bool BinarySearch(int x,int s, int f);
    int get(int pos);
    bool setIndex(int pos, int x);
    void max();
    void min();
    void sum();
    void avg();
    void reverse();
    void swap(int *a,int *b);
    void insertInSorted(int x);
    bool isSorted();
    Array* mergeArray(Array arr2);
    Array* intersection(Array arr2); 
    Array* Union(Array arr2); 

};


//Displays all array elements
void Array::display() {
    for(int i=0;i <size;i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

//Adds element to the back of the array.
void Array::append(int x) {
    A[length] = x;
    ++length;
}

//Adds element at the defined valid position.
void Array::insert(int pos, int x) {
    if(pos > length)
        cout << "Element cannot be inseted out of the length of array.\n";

    else {
         /*Shifting current array elements by 
         1 position to right to create empty space for new element*/
        for(int i=length ;i>pos;i--)
            A[i] = A[i-1];

        A[pos] = x;
        length++;
    }
}


///Deleting element from the given position
void Array::deleteInd(int pos) {
    if(pos > length)
        cout << "Element cannot be deleted.\n";
    else {
        /*Shifting current array elements by 
         1 position to left so as to not leave any empty space*/
        for(int i=pos;i<length-1;i++) {
             A[i] = A[i+1];
        }
        A[length] = 0;
        length--;
    }
}


//Scanning all the elements to find x
//Time complexity: O(n)
//Space Complexity: O(1)
bool Array::LinearSearch(int x) {
    for(int i=0;i<size;i++) {
        if(x == A[i])
            return true;
        cout << length;
    }
    return false;
}

//Only works on sorted array. Divide the array till you find the element.
//Time complexity: O(logn)
//Space Complexity: O(1)
bool Array::BinarySearch(int x,int l, int r) {
    if(r >= l) {
        int mid = l+(r-l)/2; // Don't use (l+r)/2 because of Integer overflow
        if(x == A[mid])
            return true;
        else if(x < A[mid])
            return BinarySearch(x,l,mid-1);
        else
            return BinarySearch(x,mid+1,r);
    }
    return false;
}


//Returns element at the given position
int Array::get(int pos) {
    if(pos >= length)
        return -1;
    return A[pos];
}

//Updates element at the given position
bool Array::setIndex(int pos, int x) {
    if(pos >= length)
        return;
    A[pos] = x;
}


//Returns max element in the array
void Array::max() {
    int m = A[0];
    for(int i=i;i<length;i++)
        if(A[i] > m)
            m = A[i];
    cout << "Maximum value in array is: " << m << endl;  
}


//Returns min element in the array
void Array::min() {
    int  m = A[0];
    for(int i=i;i<length;i++)
        if(A[i] < m)
            m = A[i];
    cout << "Minimum value in array is: " << m << endl;  
}

//Sum of all the elements in the array
void Array::sum() {
    int s = 0,i=0;
    while(i<length) {
        s += A[i];
        i++;
    }
    cout << "Sum: " << s << endl;
}

//Average of all the elements in array
void Array::avg() {
    double a=0;
    for(int i=0;i<length;i++) {
        a += A[i];
    }
    cout << "Average: " << a/length << endl;
}

//Swap two elements in array
void Array::swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}

//Reverse the array
void Array::reverse() {
    for(int i=0;i<length/2;i++) {
       swap(&A[i],&A[length-1-i]);
    }

    for(int i=0;i<size;i++) 
        cout << A[i] << " ";
}


//Insert element in sorted array;
void Array::insertInSorted(int x) {
    int i=length-1;
    while(x<A[i]) {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

//Checks if array is sorted
bool Array::isSorted() {
    for(int i=0;i<length-1;i++) {
        if(A[i] > A[i+1])
            return false;
    }
    return true;
}

//Merge two sorted arrays
Array* Array::mergeArray(Array arr2) {
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length) {
        if(A[i]<arr2.A[j])
            arr3->A[k++]=A[i++]; 
        else if(arr2.A[j]<A[i])
            arr3->A[k++]=arr2.A[j++];
    }

    for(;i<length;i++)
        arr3->A[k++]=A[i];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];
    arr3->length=k;

   return arr3;
}

//Returns intersection of two arrays
Array* Array::intersection(Array arr2) {
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length) {
        if(A[i] < arr2.A[j])
            i++;
        else if(arr2.A[j] < A[i])
            j++;
        else if(A[i] == arr2.A[j]) {
            arr3->A[k++] = A[i++];
            j++;
        }
        arr3->length = k;
        return arr3;
    }

} 

//Returns union of two arrays
// Array* Union(Array arr2) {
//     int i,j,k;
//     i=j=k=0;
//     Array *arr3=new Array(length+arr2.length);
//     while(i<length && j<arr2.length) {
//         if(A[i]<arr2.A[j])
//             arr3->A[k++]=A[i++]; 
//         else if(arr2.A[j]<A[i])
//             arr3->A[k++]=arr2.A[j++];
//         else {
//             arr3->A[k++]=A[i++];
//             j++;
//         }
//     }

//     for(;i<length;i++)
//         arr3->A[k++]=A[i];
//     for(;j<arr2.length;j++)
//         arr3->A[k++]=arr2.A[j];
//     arr3->length=k;

//    return arr3;
// }


int main() {

    //Testing all functions
    int n;
    Array arr(10);
    Array temp(8);

    for(int i=0;i<25;i+=4)
        temp.append(i);


    for(int i=1;i<=10;i++)
        arr.append(i);
    
    arr.display();
    arr.insert(7,69);
    arr.display();
    arr.deleteInd(7);
    arr.display();
    temp.display();

    
    bool val = arr.LinearSearch(17);
    bool val = arr.BinarySearch(7,0,9);
    if(val == true) cout << "Search was successful" << endl;
    else cout << "Search was unsuccessful" << endl;
    

    arr.max();
    arr.min();
    arr.sum();
    arr.avg();
    arr.reverse();

    arr.insertInSorted(6);
    bool val  = arr.isSorted();
    if(val == true) cout << "Array is sorted\n";
    else cout << "Array is not sorted\n";

    Array *t = arr.mergeArray(temp);
    t->display();


}


