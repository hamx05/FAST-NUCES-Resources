#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node () : data(0), next(NULL) {}
        Node (int d) : data(d), next(NULL) {}
};

class Stack {
    public:
        Node *top;

        Stack () : top(NULL) {}
        Stack (int d) {
            top = new Node (d);
        }

        void push (int d) { // add new elements at top
            cout<<d<<" has been added on the top." << endl;
            if (top == NULL) {
                top = new Node(d);
            }
            else {
                Node *newnode = new Node(d);
                newnode->next = top;
                top = newnode;
            }
        }

        void pop () {
            if (top != NULL) {
                Node *temp = top;
                if (top->next != NULL) top = top->next; // set the 2nd element to top if the list has more than 1 element
                cout << temp->data << " has been popped from the stack." << endl;
                delete temp;
            }
            else {
                cout<<"Top is empty." << endl;
            }
            }

        void peek () {
            if (top != NULL) {
                cout<<"Top element is: " << top->data << endl;
            }
            else {
                cout<<"Top is empty." << endl;
            }
        }

        void print () {
            if (top == NULL) {
                cout<<"The stack is empty." << endl;
                return;
            }
            cout<<"Elements in stack: " << endl;
            Node *temp = top;
            while (temp != NULL) {
                cout<<temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }

        // we can't iterate backwards in singly linked list, so we need to reverse the LL to iterate backwards
        void printReverse () {
            if (top == NULL) {
                cout<<"The stack is empty." << endl;
                return;
            }
            cout<<"The stack has been reversed and will be printed in reverse now." << endl;
            Node *prev = NULL;
            Node *curr = top;
            Node *nextNode = NULL;

            while (curr != NULL) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            top = prev;

            print();
        }
};


int main () {

    cout<<endl;
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    s1.push(10);
    cout<<endl;
    s1.print();
    cout<<endl;
    s1.pop();
    cout<<endl;
    s1.print();
    cout<<endl;
    s1.printReverse();
}