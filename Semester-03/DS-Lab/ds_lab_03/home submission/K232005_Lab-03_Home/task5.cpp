#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        int data;
        Node *next;
        Node *previous;

        Node() {
            key = 0;
            data = 0;
            next = NULL;
            previous = NULL;
        }

        Node(int k, int d) {
            key = k;
            data = d;
            next = NULL;
            previous = NULL;
        }
};

class DLL {
    public:
        Node *head;

        DLL() {
            head = NULL;
        }

        DLL(int k, int d) {
            head = new Node(k, d);
        }

        void addAtTail(int k, int d) {
            Node* newnode = new Node(k, d);
            newnode->next = NULL;

            if (head == NULL) {
                head = newnode;
                return;
            }

            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->previous = temp;
        }

        void addAtHead(int k, int d) {
            Node *n = new Node(k, d);
            n->next = head;

            if (head != NULL) {
                head->previous = n;
            }

            head = n;
        }

        void addAtSpecificPosition(int k, int d, int pos) {
            if (pos <= 0) {
                cout << "Position cannot be zero or negative." << endl;
                return;
            }

            if (pos == 1) {
                addAtHead(k, d);
                return;
            }

            Node* newnode = new Node(k, d);
            Node *temp = head;
            int i = 1;

            while (i < pos - 1 && temp != NULL) {
                temp = temp->next;
                i++;
            }

            if (temp == NULL) {
                cout << "Position out of bounds." << endl;
                delete newnode;
                return;
            }

            newnode->next = temp->next;
            if (temp->next != NULL) {
                temp->next->previous = newnode;
            }
            temp->next = newnode;
            newnode->previous = temp;
        }

        void deleteNode(int pos) {
            if (pos <= 0) {
                cout << "Position cannot be zero or negative." << endl;
                return;
            }

            if (pos == 1) {
                Node *temp = head;
                if (head != NULL) {
                    head = head->next;
                    if (head != NULL) {
                        head->previous = NULL;
                    }
                    delete temp;
                }
                return;
            }

            Node *temp = head;
            int i = 1;
            while (temp != NULL && i < pos) {
                temp = temp->next;
                i++;
            }

            if (temp == NULL) {
                cout << "Position out of bounds." << endl;
                return;
            }

            if (temp->previous != NULL) {
                temp->previous->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->previous = temp->previous;
            }
            delete temp;
        }

        void updateNode(int k, int d, int pos) {
            if (pos <= 0) {
                cout << "Position cannot be zero or negative." << endl;
                return;
            }

            Node *temp = head;
            int i = 1;
            while (temp != NULL && i < pos) {
                temp = temp->next;
                i++;
            }

            if (temp == NULL) {
                cout << "Position out of bounds." << endl;
                return;
            }

            temp->key = k;
            temp->data = d;
        }

        void printLinkedList() {
            Node *temp = head;
            while (temp != NULL) {
                cout << "(" << temp->key << ", " << temp->data << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    DLL list(0, 25);
    cout << "--------------- Element inserted with constructor ---------------" << endl;
    list.printLinkedList();
    cout << "\n\n--------------- Added elements at Tail ---------------" << endl;
    list.addAtTail(1, 100);
    list.addAtTail(2, 200);
    list.addAtTail(3, 300);
    list.addAtTail(4, 400);
    list.printLinkedList();
    cout << "\n\n--------------- Added an element at Head ---------------" << endl;
    list.addAtHead(0, 50);
    list.printLinkedList();
    cout << "\n\n--------------- Added an element at a Specific Position (pos=3) ---------------" << endl;
    list.addAtSpecificPosition(999, 999, 3);
    list.printLinkedList();
    cout << "\n\n--------------- Deleted a Node at a Specific Position (pos=1 & pos=4) ---------------" << endl;
    cout << "Before: ";
    list.printLinkedList();
    list.deleteNode(1);
    list.deleteNode(4);
    cout << "After: ";
    list.printLinkedList();
    cout << "\n\n--------------- Updated Node at a Specific Position (pos=1 & pos=5) ---------------" << endl;
    list.updateNode(35, 333, 1);
    list.updateNode(55, 555, 5);
    list.printLinkedList();

    return 0;
}
