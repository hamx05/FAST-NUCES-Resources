#include <iostream>
using namespace std;

class Node {
    public:
        string data;
        Node *next;
        Node *prev;

        Node () {
            data = "";
            next = NULL;
            prev = NULL;
        }

        Node (string d) {
            data = d;
            next = NULL;
            prev = NULL;
        }
};

class DLL {
    public:
        Node *head;
        Node *tail;

        DLL () {
            head = NULL;
            tail = NULL;
        }

        DLL (string d) {
            head = new Node(d);
            tail = head;
        }

        void addAtTail(string d) {
            Node* newnode = new Node(d);
            newnode->next = NULL;

            if (head == NULL) {
                head = newnode;
                tail = head;
                return;
            } else {
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;
            }
        }
        

        void printLinkedList () {
            Node *temp = head;

            while (temp != NULL) {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout<<endl;
        }

        DLL concatenate (DLL &L, DLL &M) {
            // now we need to consider all cases, e.g when L is empty, when M is empty.

            if (L.head == NULL) {
                head = M.head;
                tail = M.tail;
                return L;
            }

            if (M.head == NULL) {
                head = L.head;
                tail = L.tail;
                return L;
            }

            L.tail->next = M.head;
            M.head->prev = L.tail;
            head = L.head;
            tail = M.tail;
            return L;
        }
};

int main () {

    DLL list1;
    list1.addAtTail("1");
    list1.addAtTail("2");
    list1.addAtTail("3");
    list1.addAtTail("4");
    list1.addAtTail("5");
    cout<<"List 1: ";
    list1.printLinkedList();

    DLL list2;
    list2.addAtTail("6");
    list2.addAtTail("7");
    list2.addAtTail("8");
    list2.addAtTail("9");
    cout<<"List 2: ";
    list2.printLinkedList();

    DLL list3;
    list3.concatenate(list1, list2);
    cout<<"List 3: ";
    list3.printLinkedList();
    

    return 0;
}