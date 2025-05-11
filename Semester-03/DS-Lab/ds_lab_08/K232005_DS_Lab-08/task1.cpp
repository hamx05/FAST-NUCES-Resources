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

        Node* deleteNode (Node *temp, int key) {
            if (temp == NULL) {
                return temp;
            }
        
            // Case 01: Node has no child
            if (key < temp->data) {
                temp->leftChild = deleteNode(temp->leftChild, key); // go left
            }
            else if (key > temp->data) {
                temp->rightChild = deleteNode(temp->rightChild, key); // go right
            }

            // Case 02: Node has one child (left or right)
            else {
                if (temp->leftChild == NULL && temp->rightChild==NULL) {
                    delete temp;
                    return NULL;
                }

                else if (temp->leftChild == NULL) {
                    Node *right = temp->rightChild;
                    delete temp;
                    return right;
                }
                else if (temp->rightChild == NULL) {
                    Node *left = temp->leftChild;
                    delete temp;
                    return left;
                }

                // Case 03: Node has two children
                Node *minRight = findMin(temp->rightChild);
                temp->data = minRight->data;
                temp->rightChild = deleteNode(temp->rightChild, minRight->data);
            }
        }

        Node* findMin (Node *temp) {
            while (temp->leftChild != NULL) {
                temp = temp->leftChild;
            }
            return temp;
        }

        void preOrderTraversal (Node *temp) {
            if (temp == NULL) return;

            cout << temp->data << " ";
            preOrderTraversal(temp->leftChild);
            preOrderTraversal(temp->rightChild);
        }

        void inOrderTraversal (Node *temp) {
            if (temp == NULL) return;

            inOrderTraversal(temp->leftChild);
            cout << temp->data << " ";
            inOrderTraversal(temp->rightChild);
        }

        void postOrderTraversal (Node *temp) {
            if (temp == NULL) return;

            postOrderTraversal(temp->leftChild);
            postOrderTraversal(temp->rightChild);
            cout << temp->data << " ";
        }

        Node* search (Node *temp, int target) {
            if (temp == NULL) {
                cout << "Value not found." << endl;
                return NULL;
            }

            if (target == temp->data) {
                cout << "Value found." << endl;
                return temp;
            }

            if (target <= temp->data) search(temp->leftChild, target);
            else search(temp->rightChild, target);
            return NULL;
        }
};

int main () {

    BinaryTree b1;
    
    b1.insertNode(30);
    b1.insertNode(25);
    b1.insertNode(35);
    b1.insertNode(70);
    b1.insertNode(5);

    cout << "------------------------- Pre-Order Traversal -------------------------\n";
    b1.preOrderTraversal(b1.root);
    cout << endl;
    cout << "------------------------- In-Order Traversal -------------------------\n";
    b1.inOrderTraversal(b1.root);
    cout << endl;
    cout << "------------------------- Post-Order Traversal -------------------------\n";
    b1.postOrderTraversal(b1.root);
    cout << endl;

    cout << "------------------------- Search -------------------------\n";
    b1.search(b1.root, 30);
    b1.search(b1.root, 1);

    cout << "------------------ Print After Deleting 30(Pre-Order) ------------------\n";
    b1.deleteNode(b1.root, 30);
    b1.preOrderTraversal(b1.root);
    cout << endl;


}