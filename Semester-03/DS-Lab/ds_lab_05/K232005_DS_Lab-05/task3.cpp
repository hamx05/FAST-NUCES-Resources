#include <iostream>
using namespace std;

#define MAX 15

class Stack {
    public:
        char arr[MAX];
        int top; // top -1 is empty
        int size; // size = 0 is empty

        Stack () : top(-1), size(0) {}

        void push (char x) {
            if (size == MAX) {
                cout<<"Overflow condition. Element cannot be added." << endl;
                return;
            }
            else {
                top++;
                size++;
                arr[top] = x;
                cout<< arr[top] << " has been pushed to the stack." << endl;
            }
        }

        void pop () {
            if (top == -1) {
                cout<<"Underflow condition. Stack is already empty." << endl;
                return;
            }
            else {
                size--;
                arr[top--];
            }
        }

        void peek () {
            if (top == -1) {
                cout<<"Underflow condition. Stack is empty." << endl;
                return;
            }
            else {
                cout << arr[top] << " ";
            }
        }

        void reverse() {
            int temp = size;
            cout<<"\nPrinting array in reverse." << endl;
            for (int i=0; i<temp; i++) {
                peek();
                pop();
            }
        }

};

int main () {
    
    string input;
    cout<<"Enter a string of maximum 15 characters: ";
    cin>>input;

    Stack s;
    for (char c: input) {
        s.push(c);

    }
    s.reverse();
 
    return 0;
}