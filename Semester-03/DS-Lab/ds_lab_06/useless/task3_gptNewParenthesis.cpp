#include <iostream>
#include <stack>
#include <cctype> // For isalnum
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
            size--;
            char toPop = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            return toPop;
        }
        return '\0'; // Return null char to handle empty case
    }

    char peek() {
        if (top != NULL) {
            return top->data;
        }
        return '\0';
    }

    bool isEmpty() {
        return size == 0;
    }
};

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // For '(' and ')'
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input; // Example input: a+b+(c-d)

    string output;
    Stack s1;

    for (int i = 0; i < input.size(); i++) {
        // If character or number, directly add to output
        if (isalnum(input[i])) {
            output += input[i];
        } 
        else if (input[i] == '(') {
            s1.push(input[i]);
        } 
        else if (input[i] == ')') {
            // Pop until '(' is found
            while (!s1.isEmpty() && s1.peek() != '(') {
                output += s1.pop();
            }
            s1.pop(); // Remove '(' from stack
        } 
        else if (isOperator(input[i])) {
            int precedence = getPrecedence(input[i]);
            while (!s1.isEmpty() && getPrecedence(s1.peek()) >= precedence) {
                output += s1.pop();
            }
            s1.push(input[i]);
        }
    }

    // Pop any remaining operators from the stack
    while (!s1.isEmpty()) {
        output += s1.pop();
    }

    cout << "Output: " << output << endl; // Expected output for a+b+(c-d) -> ab+cd-+
    return 0;
}
