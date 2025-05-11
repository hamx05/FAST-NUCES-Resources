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
        int count;

        BinaryTree () : count(0), root(NULL) {}

        BinaryTree (int d) : root(NULL) {
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

        void inOrderTraversal (Node *temp, int index = 0) {
            if (temp == NULL) return;

            inOrderTraversal(temp->leftChild);
            count++;
            cout << temp->data << " ";
            inOrderTraversal(temp->rightChild);
        }

        void printMedian (Node *temp, int index) {
            static int counter = 0;
            if (temp == NULL) return;

            if (counter == index) {
                cout << "Median Node's Value is: " << temp->data << endl;
                return;
            }

            printMedian(temp->leftChild, index);
            counter++;
            printMedian(temp->rightChild, index);
        }

        int findMedian () {
            if (count%2 == 0) {
                return (count/2 + ((count)/2+1)) / 2;
            }
            else {
                return (count + 1) / 2;
            }
        }
};

int main () {

    BinaryTree b1;
    
    b1.insertNode(30);
    b1.insertNode(25);
    b1.insertNode(35);
    b1.insertNode(70);
    b1.insertNode(5);

    cout << "------------------------- In-Order Traversal -------------------------\n";
    b1.inOrderTraversal(b1.root);
    cout << endl;

    b1.printMedian(b1.root, b1.findMedian());

    return 0;
}