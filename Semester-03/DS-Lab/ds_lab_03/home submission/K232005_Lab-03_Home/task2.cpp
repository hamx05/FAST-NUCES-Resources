#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node () {
            data = 0;
            next = NULL;
        }

        Node (int d) {
            data = d;
            next = NULL;
        }
};

class SLL {
    public:
        Node *head;

        SLL () {
            head = NULL;
        }

        SLL (int d) {
            head = new Node(d);
        }

        void addAtTail(int d) {
            Node* newnode = new Node(d);
            newnode->next = NULL;
            Node *temp = head;

            if (head == NULL) {
                head = newnode;
            } else {
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }

        void printLinkedList () {
            Node *temp = head;

            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout<<"NULL" << endl;
        }

        void arrangeEvenOdd () {
            Node *evenHead = NULL;
            Node *evenTail = NULL;
            Node *oddHead = NULL;
            Node *oddTail = NULL;
            Node *curr = head;

            while (curr != NULL) {
                if (curr->data%2 == 0) { // if node is even
                    if (evenHead == NULL) {
                        evenHead = curr;
                        evenTail = curr;
                    } else {
                        evenTail->next = curr;
                        evenTail = evenTail->next;
                    }
                }
                else { // if node is  odd
                    if (oddHead == NULL) {
                        oddHead = curr;
                        oddTail = curr;
                    } else {
                        oddTail->next = curr;
                        oddTail = oddTail->next;
                    }
                }
                curr = curr->next;
            }

                if (evenHead != NULL) {
                    head = evenHead;
                    evenTail->next = oddHead; // if there is an odd list, wo connect hojaegi. Warna evenTail->next me null ajaega as required
                } else {
                    head = oddHead; // if no even numbers, head should be oddHead
                }

                if (oddTail != NULL) {
                    oddTail->next = NULL; // last node should be null
                }
            // }
        }
};


int main () {

    // SLL list;
    // list.addAtTail(8);
    // list.addAtTail(12);
    // list.addAtTail(10);
    // list.addAtTail(5);
    // list.addAtTail(4);
    // list.addAtTail(1);
    // list.addAtTail(6);
    // list.printLinkedList();
    // list.arrangeEvenOdd();
    // list.printLinkedList();

    // SLL list2;
    // list2.addAtTail(8);
    // list2.addAtTail(12);
    // list2.addAtTail(10);
    // list2.addAtTail(6);
    // list2.addAtTail(4);
    // list2.addAtTail(2);
    // list2.addAtTail(16);
    // list2.printLinkedList();
    // list2.arrangeEvenOdd();
    // list2.printLinkedList();

    SLL list3;
    list3.addAtTail(1);
    list3.addAtTail(7);
    list3.addAtTail(13);
    list3.addAtTail(5);
    list3.addAtTail(33);
    list3.addAtTail(23);
    list3.addAtTail(11);
    list3.printLinkedList();
    list3.arrangeEvenOdd();
    list3.printLinkedList();

    return 0;
}