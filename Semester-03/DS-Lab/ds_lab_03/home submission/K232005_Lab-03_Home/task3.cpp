#include <iostream>
using namespace std;

// NOTE: solution guide taken from geeksforgeeks

class Node {
    public:
        string data;
        Node *next;

        Node () {
            data = "";
            next = NULL;
        }

        Node (string d) {
            data = d;
            next = NULL;
        }
};

class SLL {
    public:
        Node *head;
        Node *tail;

        SLL () {
            head = NULL;
        }

        SLL (string d) {
            head = new Node(d);
        }

        void addAtTail(string d) {
            Node* newnode = new Node(d);
            newnode->next = NULL;
            Node *temp = head;

            if (head == NULL) {
                head = newnode;
            } else {
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newnode;
                tail = temp->next;
            }
        }

        void printLinkedList () {
            Node *temp = head;

            while (temp != NULL) {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout<<endl;
        }

        // NOTE: solution guide taken from geeksforgeeks
        void checkPalindrome () {
            Node *slow = head;
            Node *fast = head;

            while (fast->next != NULL && fast->next->next != NULL) {
                slow = slow->next; // moves 1 step ahead
                fast = fast->next->next; // moves 2 steps ahead
            }
            
            // now, we reverse the string from head2 till the end i.e fast ptr
            Node *head2 = slow->next; // slow is the middle
            slow->next = NULL; // the first half ends here
            Node *nextNode; // used to save the next node in the series
            Node *prev = NULL;
            Node *curr = head2; // curr starts from head2

            while (curr != NULL) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            head2 = prev; // head2 points at the first element of reversed list
            Node *firstHalf = head;
            Node *secondHalf = head2;

            // now we need to compare corresponding elements of both halves
            bool isPalindrome = true;
            while (secondHalf != NULL) {
                if (firstHalf->data != secondHalf->data) {
                    isPalindrome = false;
                    break;
                }
                firstHalf = firstHalf->next;
                secondHalf = secondHalf->next;
            }
            
            if (isPalindrome) {
                cout<<"Linked list is a palindrome." << endl;
            } else {
                cout<<"Linked list is not a palindrome." << endl;
            }

            // now we'll reverse the second half again to restore the original list
            // i skipped this step because it flew over my head
        }
        
};

int main () {

    SLL list;
    list.addAtTail("1");
    list.addAtTail("0");
    list.addAtTail("1");
    list.addAtTail("0");
    list.addAtTail("1");
    list.printLinkedList();
    list.checkPalindrome();
    cout<<endl;

    SLL list2;
    list2.addAtTail("B");
    list2.addAtTail("O");
    list2.addAtTail("R");
    list2.addAtTail("R");
    list2.addAtTail("O");
    list2.addAtTail("W");
    list2.addAtTail("O");
    list2.addAtTail("R");
    list2.addAtTail("R");
    list2.addAtTail("O");
    list2.addAtTail("B");
    list2.printLinkedList();
    list2.checkPalindrome();
    cout<<endl;

    SLL list3;
    list3.addAtTail("1");
    list3.addAtTail("2");
    list3.addAtTail("3");
    list3.addAtTail("3");
    list3.addAtTail("2");
    list3.addAtTail("1");
    list3.printLinkedList();
    list3.checkPalindrome();
    cout<<endl;

    SLL list4;
    list4.addAtTail("0");
    list4.addAtTail("1");
    list4.addAtTail("2");
    list4.addAtTail("3");
    list4.addAtTail("4");
    list4.printLinkedList();
    list4.checkPalindrome();
    cout<<endl;
    
    SLL list5;
    list5.addAtTail("4");
    list5.addAtTail("3");
    list5.addAtTail("2");
    list5.addAtTail("1");
    list5.addAtTail("2");
    list5.addAtTail("3");
    list5.addAtTail("55");
    list5.printLinkedList();
    list5.checkPalindrome();
    cout<<endl;
    

    return 0;
}