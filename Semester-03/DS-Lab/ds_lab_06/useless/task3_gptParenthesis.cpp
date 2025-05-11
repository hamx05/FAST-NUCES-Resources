#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next;

    Node() : data(0), next(NULL) {}
    Node(char d) : data(d), next(NULL) {}
};

class Stack {
public:
    Node *top;
    int size;

    Stack() : top(NULL), size(0) {}

    void push(char d) {
        size++;
        cout << "Pushed: " << d << endl;
        if (top == NULL) {
            top = new Node(d);
        } else {
            Node *newnode = new Node(d);
            newnode->next = top;
            top = newnode;
        }
    }

    char pop() {
        if (top != NULL) {
            cout << "Popped: " << top->data << endl;
            size--;
            char toPop = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            return toPop;
        } else {
            cout << "Top is empty." << endl;
        }
        return '\0'; // Return null char to handle empty case
    }

    char peek() {
        if (top != NULL) {
            return top->data;
        } else {
            cout << "Top is empty." << endl;
        }
        return '\0';
    }

    void print() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Printing Stack: " << endl;
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->data << " " << endl;
            temp = temp->next;
        }
        cout << endl;
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

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input; // For example: x=12+13-5*(0.5+0.5)+1

    string output;

    Stack s1;
    for (int i = 0; i < input.size(); i++) {
        // If character or number, directly add to output
        if (isalnum(input[i]) || input[i] == '=') {
            output += input[i];
        } else {
            bool flagRightParenthesis = false;
            if (input[i] == '(') {
                s1.push(input[i]);
            }

            // Closing parenthesis: pop till opening parenthesis
            if (input[i] == ')') {
                flagRightParenthesis = true;
                while (s1.peek() != '(') {
                    output += s1.pop();
                }
                s1.pop(); // Discard '('
            }

            // Handling operators with precedence
            if (!flagRightParenthesis) {
                int topPrecedence = 0;
                int precedence = getPrecedence(input[i]);
                if (s1.size != 0) {
                    topPrecedence = getPrecedence(s1.peek());
                }

                // If the operator has higher precedence, push it
                if (precedence > topPrecedence) {
                    s1.push(input[i]);
                } 
                // If lower or equal precedence, pop operators and push current
                else {
                    while (s1.size != 0 && precedence <= getPrecedence(s1.peek())) {
                        output += s1.pop();
                    }
                    s1.push(input[i]);
                }
            }
        }
    }

    // Pop any remaining operators
    while (s1.size != 0) {
        output += s1.pop();
    }

    cout << "Output: " << output << endl;
}
