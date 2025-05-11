#include <iostream>
using namespace std;

class Node {
    public:
        char data;
        Node *next;

        Node () : data(0), next(NULL) {}
        Node (char d) : data(d), next(NULL) {}
};

class Queue {
    public:
        Node *front;
        Node *rear;

        Queue () : front(NULL), rear(NULL) {}
        Queue (char d) {
            front = new Node(d);
            rear = front;
            rear->next = front;
        }

        void enqueue (char d) {
            cout<<"Enqueued: " << d << endl;
            if (front == NULL) {
                front = new Node(d);
                rear = front;
                rear->next = front;
                front->next = rear;
            } else {
                Node *temp = rear;
                temp->next = new Node(d);
                rear = temp->next;
                rear->next = front;  
            }
        }

        char dequeue () {
            if (front == NULL) {
                return '\0';
            }
            if (front->next == front) {
                cout<<"Dequeued: " << front->data << endl;
                char todequeue = front->data;
            	delete front;
            	front = NULL;
            	rear = NULL;
                return todequeue;
			}
			
			cout<<"Dequeued: " << front->data << endl;
            char todequeue = front->data;
            Node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
            return todequeue;
        }

        char peek () {
            if (front != NULL) {
                return front->data;
            }
            else {
                cout<<"Front is empty." << endl;
                return '\0';
            }
        }

        void print() {
        	
        	if (front == NULL) {
        		cout<<"Queue is empty." << endl;
        		return;
			}
			
            Node *temp = front;
            cout<<"Elements in the queue: "<<endl;
            do {
                cout<< temp->data << " ";
                temp = temp->next;
            } while (temp != front);
            
            cout<< endl;
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

    string output;

    Queue q1;
    for (int i=0; i<input.size(); i++) {
		
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
        
        else { // if an operator, then enqueue to stack
            if (input[i] == '(') {
                q1.enqueue(input[i]);
                continue;
            }

            if (input[i] == ')') {
                while (q1.peek() != '(') {
                    output += q1.dequeue();
                }
                q1.dequeue(); // '(' dequeue hojaega idhr 
                continue;
            }

            int precedence = getPrecedence(input[i]);
            if (precedence > getPrecedence(q1.peek())) {
                q1.enqueue(input[i]);
            } else {
                // if precedence is same or low then dequeue the front, and compare the incoming with the new front
                while (q1.front != NULL && precedence<=getPrecedence(q1.peek()) && q1.peek() != '(') {
                    output += q1.dequeue();
                }
                q1.enqueue(input[i]);
            }
        }
    }
    
    cout<<"Concatenating the remaining elements from the queue: " << endl;
    while (q1.front != NULL) {
        output += q1.dequeue();
    }

    cout<<"Output: " << output;

}