#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int key;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        key = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int k, int d) {
        data = d;
        key = k;
        next = NULL;
        prev = NULL;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = NULL;
        tail = NULL;
    }

    DLL(int k, int d) {
        head = new Node (k, d);
        tail = head;
    }

    void addAtTail(int k, int d) {
        Node* newnode = new Node (k, d);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            tail = head;
            return;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void swapNodes(int key1, int key2) {
        if (key1 == key2) return;
        Node* node1 = NULL;
        Node* node2 = NULL;
        Node* curr = head;

        while (curr != NULL) {
            if (curr->key == key1) node1 = curr;
            if (curr->key == key2) node2 = curr;
            curr = curr->next;
        }

        if (!node1 || !node2) return;

        // If nodes are adjacent, handle separately
        if (node1->next == node2) {
            Node* prev1 = node1->prev;
            Node* next2 = node2->next;

            if (prev1 != NULL) prev1->next = node2; // matlab node1 ke peeche ke nextPtr me node2 ajaega
            if (next2 != NULL) next2->prev = node1; // matlab node2 ke aage ke prevPtr me node1 ajaega

            node2->prev = prev1;
            node1->next = next2;
            node2->next = node1;
            node1->prev = node2;

            if (head == node1) head = node2;
            if (tail == node2) tail = node1;
        } else if (node2->next == node1) {
            Node* prev2 = node2->prev;
            Node* next1 = node1->next;

            if (prev2) prev2->next = node1;
            if (next1) next1->prev = node2;

            node1->prev = prev2;
            node2->next = next1;
            node1->next = node2;
            node2->prev = node1;

            if (head == node2) head = node1;
            if (tail == node1) tail = node2;
        } else { // nodes are not adjacent
            Node* prev1 = node1->prev;
            Node* next1 = node1->next;
            Node* prev2 = node2->prev;
            Node* next2 = node2->next;

            if (prev1) prev1->next = node2;
            if (next1) next1->prev = node2;
            if (prev2) prev2->next = node1;
            if (next2) next2->prev = node1;

            node1->prev = prev2;
            node1->next = next2;
            node2->prev = prev1;
            node2->next = next1;

            if (head == node1) head = node2;
            else if (head == node2) head = node1;
            if (tail == node1) tail = node2;
            else if (tail == node2) tail = node1;
        }
    }

    void printLinkedList() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout<< endl<<endl;
    }
};

int main() {
    DLL list1;
    list1.addAtTail(1, 10);
    list1.addAtTail(2, 20);
    list1.addAtTail(3, 30);
    list1.addAtTail(4, 40);
    list1.addAtTail(5, 50);    
    cout<<"Initial Linked List: "<<endl;
    list1.printLinkedList();
    list1.swapNodes(2, 4);
    cout<<"After Swapping nodes 2 and 4: "<<endl;
    list1.printLinkedList();

    return 0;
}
