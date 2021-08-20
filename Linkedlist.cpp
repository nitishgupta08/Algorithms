/*
 * Created Date: Thursday, August 19th 2021, 9:07:29 pm
 * Author: Nitish Kumar Gupta
 * 
 * Copyright (c) 2021 nitishgupta
 */


#include <iostream>
#include <limits>


using namespace std;


template <typename T>
class Node {
    public:
        T data;
        Node *next;
};

template <typename T>
class Linkedlist {
    private:
        Node<T> *head;
    public:
        Linkedlist() {
            head = NULL;
        }

        /*
         * this constructor initializes 
         * linkedlist with a node n
         */
        Linkedlist(T n) {
            head = new Node<T>;
            head->next = NULL;
            head->data = n;
        }

        //deconstructor
        ~Linkedlist() {
            Node<T> *p = head;
            while(head) {
                head = head->next;
                delete p;
                p = head;
            }
        }


        Node<T> *gethead() {
            return head;
        }

        void insertElement(int index,T x);
        void displayList();
        void reverseList();
        int count();
        T sumOfElements();
        T maxElement();
        T minElement();
        bool searchElement(T x);
        int deleteElement(int index);
        void insertInSorted(T x);
        void concatnate(Linkedlist *n);
        Linkedlist *mergeList(Linkedlist *n);
};

//inserts element in the linkedlist at the provided index
template <typename T>
void Linkedlist<T>::insertElement(int index, T x) {
    Node<T> *temp = new Node<T>;
    Node<T> *p = head;
    Node<T> *q = head;
    temp->data = x;

    if(index == 0) {
        temp->next = head;
        head = temp;
    }
    else {
        int i=0;
        while(i<index) {
            q = p;
            p = p->next;
            i++;
        }
        q->next = temp;
        temp->next = p;
    }
}

//Counts the number of nodes in the list
template <typename T>
int Linkedlist<T>::count() {
    Node<T> *temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

template <typename T>
T Linkedlist<T>::sumOfElements() {
    Node<T> *temp = head;
    int sum=0;
    while(temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}


//BUG:: REMOVE INT_MIN
template <typename T>
T Linkedlist<T>::maxElement() {
    Node<T> *temp = head;
    T m = INT_MIN;
    while(temp != NULL) {
        if (temp->data > m)
            m = temp->data;
        temp = temp->next;
    }
    return m;
}

template <typename T>
T Linkedlist<T>::minElement() {
    Node<T> *temp = head;
    T m = INT_MAX;
    while(temp != NULL) {
        if (temp->data < m)
            m = temp->data;
        temp = temp->next;
    }
    return m;
}

//BUG:: Comparisons won't always work for floats
template <typename T>
bool Linkedlist<T>::searchElement(T x) {
    Node<T> *temp = head;
    while(temp != NULL) {
        if(temp->data == x)
            return true;
        temp = temp->next;
    }
    return false;
}

template <typename T>
int Linkedlist<T>::deleteElement(int index) {
    if(index < 0 || index  >= count())
        return 0;
    
    Node<T> *p = head;
    Node<T> *q = head;
    if(index == 0) {
       head = p->next;
       delete q;
    }
    else {
        int i=0;
        while(i<index) {
            q = p;
            p = p->next;
            i++;
        } 

        q->next = p->next;
        delete p;
    }

    return 1;

}

template <typename T>
void Linkedlist<T>::insertInSorted(T x) {
   Node<T> *p = head;
   Node<T> *q = head;
   Node<T> *n = new Node<T>;
   n->data = x;
   int i=0;
   while(i<count()) {
       if(p->data < x) {
           q = p;
           p = p->next;
           i++;
       }
       else break;
   }

   if(p == head) {
       n->next = head;
       head = n;
   }
   else {
       q->next = n;
       n->next = p;
   }
}

template <typename T>
void Linkedlist<T>::reverseList() {
    Node<T> *p = head;
    Node<T> *q = NULL;
    Node<T> *r = NULL;

    while(p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

//This function is not present in the menu
template <typename T>
void Linkedlist<T>::concatnate(Linkedlist *n) {
     Node<T> *temp = head;
     while(temp->next != NULL)
        temp = temp->next;
    temp->next = n->head;
 }

//This function is not present in the menu
//Merges two lists in sorted order
template <typename T>
Linkedlist<T> *Linkedlist<T>::mergeList(Linkedlist *n) {
    Node<T> *p = head;
    Node<T> *q = n->head;
    Linkedlist *l3 = new Linkedlist(INT_MIN);
    Node<T> *tail = l3->head; 

    while(p != NULL && q != NULL) {
        if(p->data < q->data) {
            tail->next = p;
            tail = p;
            p = p->next;
            tail->next = NULL;
        }
        else {
            tail->next = q;
            tail = q;
            q = q->next;
            tail->next = NULL;
        }
    }

    if(p != NULL) tail->next = p;
    if(q != NULL) tail->next = q;
    l3->deleteElement(0);
    return l3;
}

template <typename T>
void Linkedlist<T>::displayList() {
    Node<T> *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//To flush cin
void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menu() {
    system("clear");
    char choice;
    string s;
    int index,x;
    int val;
    float valf;
    double vald;
    Linkedlist<int> li;
    Linkedlist<float> lf;
    Linkedlist<double> ld;
    while(1) {
        cout << "==========LINKED LIST==========" << endl;
        cout << "a. Create linked list" << endl;
        cout << "b. Insert in linked list" << endl;
        cout << "c. Delete index in linked list" << endl;
        cout << "d. Count number of elements" << endl;
        cout << "e. Search element in linked list " << endl;
        cout << "f. Maximum element in linked list " << endl;
        cout << "g. Minimum element in linked list " << endl;
        cout << "h. Sum of all elements in Linked list " << endl;
        cout << "i. Reverse linked list " << endl;
        // cout << "l. Sort linked list " << endl;
        cout << "0. Display linked list " << endl;
        cout << "1. EXIT " << endl;
        cout << "===============================" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 'a' : {
                cout << "Enter data type{int,float,double}: ";
                cin >> s;
                clearCin();
                cout << "Linked list created" << endl;
                break;
            }
            case 'b': {
                cout << "Enter Index: ";
                cin >> index;
                cout << "Enter value to be inserted: ";
                if(s == "int") {
                    cin >> x;
                    clearCin();
                    li.insertElement(index,x);
                }
                if(s == "float") {
                    cin >> x;
                    clearCin();
                    lf.insertElement(index,x);
                }
                if(s == "double") {
                    cin >> x;
                    clearCin();
                    ld.insertElement(index,x);
                }
                cout << "Element inserted" << endl;
                break;
            }

            case 'c': {
                cout << "Enter index of element to delete: ";
                cin >> index;
                if(s == "int") val = li.deleteElement(index);
                if(s == "float") val = lf.deleteElement(index);
                if(s == "double") val = ld.deleteElement(index);
                if(val == 0) cout << "Invalid Index" << endl;
                else cout << "Index sucessfully deleted" << endl;
                break;
            }

            case 'd' : {
                if(s == "int") val = li.count();
                if(s == "float") val = lf.count();
                if(s == "double") val = ld.count();
                cout << "Total number of elements: " << val << endl;
                break;
            }

            case 'e' : {    
                if(s == "int") {
                    cin >> val;
                    clearCin();
                    cout << "Is " << val << " present in the list: " << li.searchElement(val) << endl;
                } 
                if(s == "float") {
                    cin >> valf;
                    clearCin();
                    cout << "Is " << valf << " present in the list: " << lf.searchElement(valf) << endl;

                } 
                if(s == "double") {
                    cin >> vald;
                    clearCin();
                    cout << "Is " << vald << " present in the list: " << ld.searchElement(vald) << endl;

                } 
                break;
            }

            case 'f' : {
                if(s == "int") cout << "Maximum Element in the list: " << li.maxElement() << endl;
                if(s == "float") cout << "Maximum Element in the list: " << lf.maxElement() << endl;
                if(s == "double") cout << "Maximum Element in the list: " << ld.maxElement() << endl;
                break;
            }

            case 'g' : {
                if(s == "int") cout << "Minimum Element in the list: " << li.minElement() << endl;
                if(s == "float") cout << "Minimum Element in the list: " << lf.minElement() << endl;
                if(s == "double") cout << "Minimum Element in the list: " << ld.minElement() << endl;
                break;
            }

            case 'h' : {
                if(s == "int") cout << "Sum of elements in the list: " << li.sumOfElements() << endl;
                if(s == "float") cout << "Sum of elements in the list: " << lf.sumOfElements() << endl;
                if(s == "double") cout << "Sum of elements in the list: " << ld.sumOfElements() << endl;
                break;
            }

            case 'i': {
                if(s == "int") li.reverseList();
                if(s == "float") lf.reverseList();
                if(s == "double") ld.reverseList();
                cout << "Linked list reversed" << endl;
                cout << "Display list to see the effect" << endl;
                break;
            }
   
            case '0': {
                if(s == "int") li.displayList();
                if(s == "float") lf.displayList();
                if(s == "double") ld.displayList();
                break;
            }
                 
            case '1': 
                exit(1);
            default:
                cout << "Invalid option" << endl;
        }
        clearCin();
        cout << '\n' << "Press a key to continue...";
        cin.get();
        system("clear");

    }
    
}

int main() {

    menu();
    return 0;
}