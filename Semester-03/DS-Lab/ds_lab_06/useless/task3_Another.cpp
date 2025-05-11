#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node *next;

        Node () : data(0), next(NULL) {}
        Node (T d) : data(d), next(NULL) {}
};

template <typename T>
class Stack {
    public:
        Node *top;

        Stack () : top(NULL) {}
        Stack (T d) {
            top = new Node (d);
        }

        void push (T d) {
            cout<<"Pushed: " << d << endl;
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
                cout<<"Popped: " << top->data << endl;
                Node *temp = top;
                top = top->next;
                delete temp;
            }
            else {
                cout<<"Top is empty." << endl;
            }
        }

        void peek () {
            if (top != NULL) {
                cout<<"Top: " << top->data << endl;
            }
            else {
                cout<<"Top is empty." << endl;
            }
        }

        void print () {
            
            if (top == NULL) {
                cout<<"Stack is empty." << endl;
                return;
            }

            cout<<"Printing Stack: " << endl;
            Node *temp = top;
            while (temp != NULL) {
                cout<<temp->data << " " << endl;
                temp = temp->next;
            }
            cout<<endl;
        }

        void infixToPostfix () {

        }
};


int main () {

    string input;
    cout<<"Enter a string: ";
    cin >> input;

    Stack <string>s1;
    for (char c: input) {
        s1.push(c);
    }

    // s1.push(4);
    // s1.peek();
    // s1.push(3);
    // s1.print();
    // s1.pop();
    s1.print();

}