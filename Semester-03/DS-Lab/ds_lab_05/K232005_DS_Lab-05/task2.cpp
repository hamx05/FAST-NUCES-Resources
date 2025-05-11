#include <iostream>
using namespace std;

#define MAX 9

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

        void print() {
            cout<<"Elements in the stack are: " << endl;
            for (int i=size-1; i>=0; i--) {
                cout<<arr[i] << " ";
            }
            cout<<endl;
        }

        void checkPalindrome () {
            char temp[MAX/2];
            int lastIndex = size - 1;

            for (int i=0; i<size/2; i++) {
                temp[i] = arr[lastIndex];
                lastIndex--;
            }

            bool isPalindrome = true;
            for (int i=0; i<size/2; i++) {
                if (arr[i] != temp[i]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome) {
                cout<<"The given list is a Palindrome." << endl;
            }
            else {
                cout<<"The given list is not a Palindrome." << endl;   
            }
        }
};

int main () {

    Stack s;\         
    s.push('B');
    s.push('O');
    s.push('R');
    s.push('R');
    s.push('O');
    s.push('W');
    s.push('R');
    s.push('O');
    s.push('B');
    s.print();
    s.checkPalindrome();
    cout<<endl;

    Stack s2;
    s2.push('R');
    s2.push('A');
    s2.push('D');
    s2.push('A');
    s2.push('R');
    s2.print();
    s2.checkPalindrome();
    
    return 0;
}