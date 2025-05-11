#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        int data;
        Node *next;

        Node () {
            key = 0;
            data = 0;
            next = NULL;
        }

        Node (int k, int d) {
            key = k;
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

        SLL (int k, int d) {
            head = new Node(k, d);
        }

        void addAtTail(int k, int d) {
            Node* newnode = new Node(k, d);
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

        void addAtHead (int k, int d) {
            Node *n = new Node(k, d);

            if (n->next == NULL) {
                n->next = head;
            }
            head = n;
        }

        void addAtSpecificPosition (int k, int d, int pos) {
            if (pos<=0) {
                cout << "Position cannot be zero or negative." << endl;
                return;
            }

            if (pos==1) {
                addAtHead(k, d);
                return;
            }

            Node* newnode = new Node(k, d);
            Node *temp = head;
            int i=1;

            while (i<pos-1 && temp != NULL) {
                temp = temp->next;
                i++;
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }

        void deleteNode(int pos) {
            if (pos <= 0) {
                cout<<"Position cannot be zero or negative." << endl;
                return;
            }
            if (pos == 1) {
                Node *temp = head;
                if (head != NULL) {
                    head = head->next;
                    delete temp;
                }
                return;
            }

            Node *prev = head;
            Node *curr = head;
            
            int i=1;
            while (curr != NULL && i < pos) {
                prev = curr;
                curr = curr->next;
                i++;
            }
            prev->next = curr->next;
            delete curr;
        }

        void updateNode (int k, int d, int pos) {
            if (pos <= 0) {
                cout<<"Position cannot be zero or negative." << endl;
                return;
            }

            if (pos == 1) {
                head->key = k;
                head->data = d;
                return;
            }

            Node *curr = head;
            int i=1;
            while (curr != NULL && i < pos) {
                curr = curr->next;
                i++;
            }
            curr->key = k;
            curr->data = d;
        }

        void printLinkedList () {
            Node *temp = head;

            while (temp != NULL) {
                cout << "(" << temp->key << ", " << temp->data << ") ";
                temp = temp->next;
            }
        }
};

int main () {
    
    SLL list(0, 25);
    cout<<"--------------- Element inserted with constructor ---------------" << endl;
    list.printLinkedList();
    cout<<"\n\n--------------- Added elements at Tail ---------------" << endl;
    list.addAtTail(1, 100);
    list.addAtTail(2, 200);
    list.addAtTail(3, 300);
    list.addAtTail(4, 400);
    list.printLinkedList();
    cout<<"\n\n--------------- Added an element at Head ---------------" << endl;
    list.addAtHead(0, 50);
    list.printLinkedList();
    cout<<"\n\n--------------- Added an element at a Specific Position (pos=3) ---------------" << endl;
    list.addAtSpecificPosition(999, 999, 3);
    list.printLinkedList();
    cout<<"\n\n--------------- Deleted a Node at a Specific Position (pos=1 & pos=4) ---------------" << endl;
    cout<<"Before: ";
    list.printLinkedList();
    cout<<endl;
    list.deleteNode(1);
    list.deleteNode(4);
    cout<<"After: ";
    list.printLinkedList();
    cout<<"\n\n--------------- Updated Node at a Specific Position (pos=1 & pos=5) ---------------" << endl;
    list.updateNode(35, 333, 1);
    list.updateNode(55, 555, 5);
    list.printLinkedList();

    return 0;
}