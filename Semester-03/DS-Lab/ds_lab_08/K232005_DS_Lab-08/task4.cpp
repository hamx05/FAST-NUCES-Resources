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
        BinaryTree (int d) : root(NULL) {
            root = new Node(d);
        }

        void recursiveInsertion (Node *temp, int data, Node *parent=NULL) {
            // if root is null, then just add the element at the root
            if (root == NULL) {
                root = new Node(data);
                return;
            }

            // once u reach the correct position, add the data here
            if (temp == NULL) {
                if (data <= parent->data) {
                    parent->leftChild = new Node(data);
                }
                else {
                    parent->rightChild = new Node(data);
                }
                return;
            }

            parent = temp;
            if (data <= temp->data) recursiveInsertion(temp->leftChild, data, parent);
            else recursiveInsertion(temp->rightChild, data, parent);
        }

        bool checkIfBST (Node *temp) {
            static Node *prev = NULL;
            if (temp != NULL) {
                if (!checkIfBST(temp->leftChild)) {
                    return false;
                }

                if (prev != NULL && temp->data <= prev->data) {
                    return false;
                }
                prev = temp;
                return checkIfBST(temp->rightChild);
            }
            else {
                return true;
            }
        }

        void preOrderTraversal (Node *temp) {
            if (temp == NULL) return;

            cout << temp->data << " ";
            preOrderTraversal(temp->leftChild);
            preOrderTraversal(temp->rightChild);
        }
};

int main () {

    BinaryTree b1;

    b1.recursiveInsertion(b1.root, 35);
    b1.recursiveInsertion(b1.root, 30);
    b1.recursiveInsertion(b1.root, 21);
    b1.recursiveInsertion(b1.root, 65);
    b1.recursiveInsertion(b1.root, 4);
    b1.recursiveInsertion(b1.root, 81);

    cout << "------------------------- Pre-Order Traversal -------------------------\n";
    b1.preOrderTraversal(b1.root);
    cout << endl;

    cout << "------------------------- Check if BST -------------------------\n";
    if (b1.checkIfBST(b1.root)) {
        cout << "The given tree is a binary search tree." << endl;
    } else {
        cout << "The given tree is not a binary search tree." << endl;
    }

}