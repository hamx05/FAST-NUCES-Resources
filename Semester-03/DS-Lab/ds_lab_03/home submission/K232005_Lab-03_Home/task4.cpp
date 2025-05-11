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
        Node *tail;

        SLL () {
            head = NULL;
            tail = NULL;
        }

        SLL (int k, int d) {
            head = new Node(k, d);
            tail = head;
            tail->next = head;
        }

        void addAtTail(int k, int d) {
            Node* newnode = new Node(k, d);
            newnode->next = NULL;
            Node *temp = head;

            if (head == NULL) {
                head = newnode;
                tail = newnode;
                tail->next = head;
            } else {
                tail->next = newnode; // previous (2nd last node) mein newnode ajaega
                tail = newnode; // newnode becomes the tail
                tail->next = head; // tail points at head
            }
        }

        void addAtHead (int k, int d) {
            Node *n = new Node(k, d);
            if (head == NULL) {
                head = n;
                tail = head;
                tail->next = head;
            } else {
                n->next = head;
                head = n;
                tail->next = head;
            }
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

            while (i<pos-1 && temp->next != head) {
                temp = temp->next;
                i++;
            }

            newnode->next = temp->next;
            temp->next = newnode;
            
            if (temp == tail) {
                tail = newnode;
            }
        }

        void deleteNode(int pos) {
            if (pos <= 0) {
                cout<<"Position cannot be zero or negative." << endl;
                return;
            }
            if (head == nullptr) {
                cout << "List is empty." << endl;
                return;
            }
            if (pos == 1) {
                if (head == tail) {
                    delete head;
                    head = NULL;
                    tail = NULL;
                } else {
                    Node *temp = head;
                    head = head->next;
                    tail->next = head;
                    delete temp;
                }
                return;
            }

            Node *prev = head;
            Node *curr = head->next;
            
            int i=1;
            while (curr != head && i < pos - 1) {
                prev = curr;
                curr = curr->next;
                i++;
            }

            if (curr == head || curr == nullptr) {
                cout << "Position out of range." << endl;
                return;
            }

            prev->next = curr->next;
            if (curr == tail) {
                tail = prev;
            }
            delete curr;
        }

        void updateNode (int k, int d, int pos) {
            if (pos <= 0) {
                cout<<"Position cannot be zero or negative." << endl;
                return;
            }

            if (head==NULL) {
                cout<<"List is empty." << endl;
            }

            if (pos == 1) {
                head->data = d;
                head->key = k;
                return;
            }

            Node *curr = head;
            int i=1;
            while (curr != NULL && i < pos) {
                curr = curr->next;
                i++;
                if (curr == head) {
                    cout << "Position out of range." << endl;
                    return;
                }
            }

            if (curr == nullptr) {
                cout << "Position out of range." << endl;
                return;
            }
            curr->key = k;
            curr->data = d;
        }

        void printLinkedList () {
            // use do-while loop because first time, temp==head            
            if (head==NULL) {
                cout<<"List is empty." << endl;
                return;
            }

            Node* temp = head;
            do {
                cout << "(" << temp->key << ", " << temp->data << ") ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
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
    cout<<"\n\n--------------- Deleted a Node at a Specific Position (pos=4) ---------------" << endl;
    cout<<"Before: ";
    list.printLinkedList();
    cout<<endl;
    list.deleteNode(4);
    cout<<"After: ";
    list.printLinkedList();
    cout<<"\n\n--------------- Updated Node at a Specific Position (pos=1 & pos=5) ---------------" << endl;
    list.updateNode(35, 333, 1);
    list.updateNode(55, 555, 5);
    list.printLinkedList();

    return 0;
}