#include <iostream>
using namespace std;

// Using a doubly circular linked list

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node () : data(0), next(NULL), prev(NULL) {}
        Node (int d) : data(d), next(NULL), prev(NULL) {}
};

class CQ {
    public:
        Node *head;
        Node *tail;

        CQ () : head(NULL), tail(NULL) {}
        CQ (int d) {
            head = new Node(d);
            tail = head;
            tail->next = head;
        }

        void addData (int d) {
            if (head == NULL) {
                head = new Node(d);
                tail = head;
                tail->prev = head;
                head->next = tail;
            }
            else {
                Node *temp = tail;
                temp->next = new Node(d);
                tail = temp->next;
                tail->prev = temp;
            }
            tail->next = head;
            head->prev = tail;
        }

        void popData () {
            if (head == NULL) {
                cout<<"\nList is already empty, no element can be popped." << endl;
                return;
            }
            
            if (head->next == head) {
            	delete head;
            	head = NULL;
            	tail = NULL;
            	return;
			}

            Node *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }

        void print() {
        	
        	if (head == NULL) {
        		cout<<"Queue is empty. Nothing to print." << endl;
        		return;
			}
			
            Node *temp = head;
            cout<<"Elements in the queue: "<<endl;
            do {
                cout<< temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            
            cout<< endl;
        }
        
        void printReversed() {
        	
        	if (head == NULL || tail == NULL) {
        		cout<<"Queue is empty. Nothing to print." << endl;
        		return;
			}
			
            Node *temp = tail;
            cout<<"Printing elements in the queue in reverse order: "<<endl;
            do {
                cout<< temp->data << " ";
                temp = temp->prev;
            } while (temp != tail);
            
            cout<< endl;
        }
};

int main () {
	
    CQ q1;
    q1.addData(1);
    q1.addData(2);
    q1.addData(3);
    q1.addData(4);
    q1.addData(5);
    q1.addData(6);
    q1.addData(7);
    q1.addData(8);
    q1.addData(9);
    q1.addData(10);
    q1.print();
    
    // Pop 1
    cout<<"\nPopping 1 and then printing the queue: ";
    q1.popData();
    cout<<endl;
    q1.print();                
	
	// Pop 2
	cout<<"\nPopping 2 and then printing the queue: ";
	q1.popData();
    cout<<endl;
    q1.print();
    
	// Pop 3
	cout<<"\nPopping 3 and then printing the queue: ";
	q1.popData();
    cout<<endl;
    q1.print();
    cout<<endl;
    q1.printReversed();
    
    
    

    
	
	return 0;
}
