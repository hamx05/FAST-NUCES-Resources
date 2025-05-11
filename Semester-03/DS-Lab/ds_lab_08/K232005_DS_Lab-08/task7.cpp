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

class BinaryTree {
    public:
        Node* root;

        BinaryTree () : root(NULL) {}

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

        void inOrderTraversal (Node *temp) {
            if (temp == NULL) return;

            inOrderTraversal(temp->leftChild);
            cout << temp->data << " ";
            inOrderTraversal(temp->rightChild);
        }

        void printInRange (Node *temp, int lower, int upper) {
            if (temp == NULL) return;

            printInRange(temp->leftChild, lower, upper);
            if (temp->data >= lower && temp->data <= upper) {
                cout << temp->data << " ";
            }
            printInRange(temp->rightChild, lower, upper);
        }
};

int main () {

    BinaryTree b1;
    
    b1.insertNode(5);
    b1.insertNode(1);
    b1.insertNode(10);
    b1.insertNode(50);
    b1.insertNode(40);
    b1.insertNode(100);

    cout << "-------- In-Order Traversal --------\n";
    b1.inOrderTraversal(b1.root);
    cout << endl;

    cout << "\n-------- Print In Range [5, 45] --------\n";
    b1.printInRange(b1.root, 5, 45);


    return 0;
}