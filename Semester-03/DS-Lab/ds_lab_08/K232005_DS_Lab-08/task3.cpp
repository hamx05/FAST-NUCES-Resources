#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *leftChild;
        Node *rightChild;

        Node () : data(0), leftChild(NULL), rightChild(NULL) {}      
        Node (int d) : data(d), leftChild(NULL), rightChild(NULL) {}
};

class BST {
    public:
    Node* root;

    BST () : root(NULL) {}

    BST (int d) : root(NULL) {
        root = new Node(d);
    }

    void insertNode (int data) {
        if (root == NULL) {
            root = new Node(data);
            return;
        }

        Node *temp = root;
        Node *parent = NULL;

        while (temp != NULL) {
            parent = temp;

            if (data <= temp->data) {
                temp = temp->leftChild;
            } else {
                temp = temp->rightChild;
            }
        }

        if (data <= parent->data) parent->leftChild = new Node(data);
        else parent->rightChild = new Node(data);
    }

    void merge(Node* temp) {
        if (temp == NULL) {
            return;
        }
       
        merge(temp->leftChild);
        insertNode(temp->data);
        merge(temp->rightChild);
    }

    void preOrderPrint (Node *temp) {
        if (temp == NULL) return;

        cout << temp->data << " ";
        preOrderPrint(temp->leftChild);
        preOrderPrint(temp->rightChild);
    }
   
    void inOrderPrint (Node *temp) {
        if (temp == NULL) return;

        inOrderPrint(temp->leftChild);
        cout << temp->data << " ";
        inOrderPrint(temp->rightChild);
    }
};

int main () {

    BST b1;
    b1.insertNode(5);
    b1.insertNode(3);
    b1.insertNode(6);
    b1.insertNode(2);
    b1.insertNode(4);
    cout << "------ In-Order Traversal of Tree 1 ------\n";
    b1.inOrderPrint(b1.root);
    cout << endl;

    BST b2;
    b2.insertNode(1);
    b2.insertNode(2);
    b2.insertNode(3);
    b2.insertNode(6);
    b2.insertNode(7);
    cout << "\n------ In-Order Traversal of Tree 2 ------\n";
    b2.inOrderPrint(b2.root);
    cout << endl;
   
    cout << "\n------ Merging Tree 1 & Tree 2 and then Printing Tree 3 ------\n";
    BST b3;
    b3.merge(b1.root);    
    b3.merge(b2.root);
    b3.inOrderPrint(b3.root);

    return 0;
}