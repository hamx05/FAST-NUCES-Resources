#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node() : data(0), next(NULL) {}
    Node(char d) : data(d), next(NULL) {}
};

class Stack {
public:
    Node* top;

    Stack() : top(NULL) {}

    void push(char d) {
        Node* newnode = new Node(d);
        newnode->next = top;
        top = newnode;
    }

    char pop() {
        if (top == NULL) {
            return -1;
        }
        char popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    char peek() {
        if (top == NULL) {
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isOperand(char c) {
    return isdigit(c) || isalpha(c);
}

string infixToPostfix(string exp) {
    Stack s;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If operand, add it to the output
        if (isOperand(c)) {
            result += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            s.push(c);
        }
        // If ')', pop and output until '(' is found
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.pop();
            }
            s.pop(); // Remove '('
        }
        // If operator, pop operators with higher or equal precedence and then push the current operator
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                result += s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators in the stack
    while (!s.isEmpty()) {
        result += s.pop();
    }

    return result;
}

int main() {
    string expression;
    cout << "Enter infix expression: ";
    cin >> expression;

    string postfix = infixToPostfix(expression);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
