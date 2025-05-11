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

        int findValue (Node* curr, int target, int position) {
            if (curr->data == target) return position;
            if (curr == NULL) return -1;

            int output = findValue(curr->next, target, position+1);
            return output;
        }
};

int main () {

    SLL l1;
    l1.addAtTail(3);
    l1.addAtTail(4);
    l1.addAtTail(5);
    l1.addAtTail(1);
    l1.addAtTail(2);
    l1.addAtTail(6);
    l1.addAtTail(9);
    l1.addAtTail(11);
    l1.print();
    cout<<endl;
    Node *currHead = l1.getHead();
    int res = l1.findValue(currHead, 11, 1);
    if (res != -1) {
        cout<<"Target found at position: " << res;
    } else {
        cout<<"Target not found." << endl;
    }
    cout<<endl;

    return 0;
}

