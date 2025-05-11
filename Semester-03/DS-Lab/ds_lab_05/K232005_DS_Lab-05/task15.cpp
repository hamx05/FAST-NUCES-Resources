#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
    
        Node () : data(0), next(NULL) {}
        Node (int d) : data (d), next(NULL) {}
};

class SLL {
    public:
        Node *head;

        SLL () : head(NULL) {}
        SLL (int d) {
            head = new Node(d);
        }

        void addAtTail (int d) {
            if (head == NULL) {
                head = new Node(d);
            } else {
                Node *temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new Node(d);
            }
        }

        void print () {
            Node *temp = head;
            while (temp != NULL) {
                cout<<temp->data << " ";
                temp = temp->next;
            }

        }

        Node* getHead () {
            if (head != NULL) return head;
            else {
                cout<< "List is empty." << endl;
                return NULL;
            }
        }

        int calculateLength (Node* curr, int count) {
            if (curr == NULL) return count;
            return calculateLength(curr->next, count+1);
        }
};

int main () {

    SLL l1;
    l1.addAtTail(3);
    l1.addAtTail(4);
    l1.addAtTail(5);
    l1.print();
    cout<<endl;
    Node *currHead = l1.getHead();
    cout<<"Number of elements in the list: " << l1.calculateLength(currHead, 0);
    cout<<endl;

    return 0;
}

