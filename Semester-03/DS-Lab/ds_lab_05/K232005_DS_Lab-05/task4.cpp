#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    public:
        int arr[MAX];
        int top; // top -1 is empty
        int size; // size = 0 is empty

        Stack () : top(-1), size(0) {}

        void push (int x) {
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
            cout<<"\nPrinting integer array in reverse order." << endl;
            for (int i=0; i<temp; i++) {
                peek();
                pop();
            }
        }

};

int main () {
    
    // limiting MAX to 5 in line 4
    int input[MAX];
    Stack s;

    for (int i=0; i<MAX; i++) {
        cout<<"Enter element " << i+1 << ": ";
        cin>> input[i];
        s.push(input[i]);
    }

    s.reverse();
 
    return 0;
}