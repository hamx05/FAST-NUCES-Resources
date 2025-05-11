#include <iostream>
using namespace std;

class Node {
    public:
        char data;
        Node *next;

        Node () : data(0), next(NULL) {}
        Node (char d) : data(d), next(NULL) {}
};

class Stack {
    public:
        Node *top;

        Stack () : top(NULL) {}
        Stack (char d) {
            top = new Node (d);
        }

        void push (char d) {
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

        char pop () {
            if (top != NULL) {
                cout<<"Popped: " << top->data << endl;
                char toPop = top->data;
                Node *temp = top;
                top = top->next;
                delete temp;
                return toPop;
            }
            else {
                cout<<"Top is empty." << endl;
            }
        }

        char peek () {
            if (top != NULL) {
                return top->data;
            }
            else {
                cout<<"Top is empty." << endl;
                return 0;
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
};


int getPrecedence(char currChar) {
    if (currChar == '^') {
        return 3;
    }

    if (currChar == '*' || currChar == '/') {
        return 2;
    }

    if (currChar == '+' || currChar == '-') {
        return 1;
    }
    return 0;
}

int main () {

    string input;
    cout<<"Enter a string: ";
    cin >> input;
    // x=12+13–5(0.5+0.5)+1

    string output;

    Stack s1;
    for (int i=0; i<input.size(); i++) {
//        if (iswalnum(input[i]) || input[i] == '=') { // if char or number, directly add into the output
//            output += input[i];
//        }

		// NOTE: case where dealing with floating point is fixed by gpt.
		
		if (isdigit(input[i]) || input[i] == '.') { // if number, directly add into the output
            string number;
            bool decimalSeen = false;

            while (i < input.size() && (isdigit(input[i]) || input[i] == '.')) {
                if (input[i] == '.') {
                    if (decimalSeen) break; // Only one decimal point allowed
                    decimalSeen = true;
                }
                number += input[i];
                i++;
            }
            i--; // Adjust the index after the inner loop
            output += number;
        }

        else if (isalpha(input[i]) || input[i] == '=') { // if char, directly add into the output
            output += input[i];
        }
        
        else { // if an operator, then push to stack
            if (input[i] == '(') {
                s1.push(input[i]);
                continue;
            }

            if (input[i] == ')') {
                while (s1.peek() != '(') {
                    output += s1.pop();
                }
                s1.pop(); // '(' pop out hojaega idhr 
                continue;
            }

            int precedence = getPrecedence(input[i]);
            if (precedence > getPrecedence(s1.peek())) {
                s1.push(input[i]);
            } else {
                // if precedence is same or low then pop the top, and compare the incoming with the new top
                while (s1.top != NULL && precedence<=getPrecedence(s1.peek())) {
                    output += s1.pop();
                }
                s1.push(input[i]);
            }
        }
    }
    
    while (s1.top != NULL) {
        output += s1.pop();
    }

    cout<<"Output: " << output;

}