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
                top = top->next;
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

        void reverse() {
            if (top == NULL) {
                cout<<"The stack is empty, thus cannot be reversed." << endl;
                return;
            }
            cout<<"The stack has been reversed." << endl;
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
};


int main () {

    cout<<endl;
    Stack s1;
    s1.push(1);
    s1.push(6);
    s1.push(5);
    s1.push(4);
    cout<<endl;
    s1.peek();
    cout<<endl;
    s1.push(3);
    cout<<endl;
    s1.print();
    cout<<endl;
    s1.pop();
    cout<<endl;
    s1.print();
    cout<<endl;
    s1.reverse();
    cout<<endl;
    s1.print();

}