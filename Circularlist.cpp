/*
 * Created Date: Thursday, August 19th 2021, 9:07:29 pm
 * Author: Nitish Kumar Gupta
 * 
 * Copyright (c) 2021 nitishgupta
 */

#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class CircularList {
    private:
        Node *head;
    public:
        CircularList() {
            head = NULL;
        }

        CircularList(int n) {
            head = new Node;
            head->next = head;
            head->data = n;
        }

        void insertElement(int index,int x);
        void displayList();
        int count();
        bool searchElement(int x);
        void deleteElement(int index);
        
};


void CircularList::insertElement(int index, int x) {
    Node *temp = new Node;
    Node *p = head;
    Node *q = head;
    temp->data = x;

    if(head == NULL) {
        head = temp;
        temp->next = head;
        return;
    }

    if(index == 0) {
        while(p->next != head)
            p = p->next;
        temp->next = head;
        head = temp;
        p->next = head;
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

int CircularList::count() {
    Node *temp = head;
    int cnt = 0;
    do {
        cnt++;
        temp = temp->next;
    } while(temp != head);
    return cnt;
}

bool CircularList::searchElement(int x) {
    Node *temp = head;
    do {
        if(temp->data == x)
            return true;
        temp = temp->next;
    }while(temp != head);
    return false;
}

void CircularList::deleteElement(int index) {
    Node *p = head;
    Node *q = head;
    if(index == 0) {
        q = head;
        while(p->next != head)
            p = p->next;
       head = head->next;
       p->next = head;
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

}

void CircularList::displayList() {
    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);

    cout << endl;
}

void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menu() {
    system("clear");
    char choice;
    int index,x,val;
    CircularList l;
    while(1) {
        cout << "==========CIRCULAR LINKED LIST==========" << endl;
        cout << "a. Create linked list" << endl;
        cout << "b. Insert in linked list" << endl;
        cout << "c. Delete index in linked list" << endl;
        cout << "d. Count number of elements" << endl;
        cout << "e. Search element in linked list " << endl;
        cout << "0. Display linked list " << endl;
        cout << "1. EXIT " << endl;
        cout << "===============================" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 'a' : {
                cout << "Circular Linked list created" << endl;
                break;
            }
            case 'b': {
                cout << "Enter Index: ";
                cin >> index;
                cout << "Enter value to be inserted: ";
                cin >> x;
                l.insertElement(index,x);
                cout << "Element inserted" << endl;
                break;
            }

            case 'c': {
                cout << "Enter index of element to delete: ";
                cin >> index;
                l.deleteElement(index);
                cout << "Index sucessfully deleted" << endl;
                break;
            }

            case 'd' : {
                val = l.count();
                cout << "Total number of elements: " << val << endl;
                break;
            }

            case 'e' : {    
                cin >> val;
                cout << "Is " << val << " present in the list: " << l.searchElement(val) << endl;
                break;
            }

            case '0': { 
                l.displayList();
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