#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* leftChild;
        Node* rightChild;
        int height;
        int index;

        Node() : data(0), leftChild(NULL), rightChild(NULL), height(1), index(-1) {}
        Node(int d) : data(d), leftChild(NULL), rightChild(NULL), height(1), index(-1) {}
};

class AVLTree {
    public:
        Node* root;
        int currentIndex;

        AVLTree() : root(nullptr), currentIndex(0) {}

        int getHeight (Node* node) {
            if (node == NULL) return 0;
            return node->height;
        }

        void updateHeight(Node* node) {
            node->height = 1 + max(getHeight(node->leftChild), getHeight(node->rightChild));
        }

        int getBalanceFactor (Node* node) {
            if (node == NULL) return 0;
            return (getHeight(node->leftChild) - getHeight(node->rightChild));
        }

        Node* rotateRight (Node* y) {

            Node *x = y->leftChild;
            Node *T2 = x->rightChild;

            x->rightChild = y;
            y->leftChild = T2;

            updateHeight(y);
            updateHeight(x);
            return x;
        }

        Node* rotateLeft (Node* x) {
            
            Node* y = x->rightChild;
            Node *T2 = y->leftChild;

            y->leftChild = x;
            x->rightChild = T2;

            updateHeight(x);
            updateHeight(y);

            return y;
        }

        Node* insert (Node* node, int data) {
            // if root is empty, then this node becomes the root.
            if (node == NULL) {
                Node* newNode = new Node(data);
                newNode->index = currentIndex++;
                return newNode;
            }

            if (data < node->data) {
                node->leftChild = insert(node->leftChild, data);
            }
            else if (data > node->data) {
                node->rightChild = insert(node->rightChild, data);
            }
            else {
                return node;
            }

            updateHeight(node);
            int bf = getBalanceFactor(node);

            // Left Left
            if (bf > 1 && data < node->leftChild->data) {
                return rotateRight(node);
            }
            // Right Right
            if (bf < -1 && data > node->rightChild->data) {
                return rotateLeft(node);
            }
            // Left Right
            if (bf > 1 && data > node->rightChild->data) {
                node->leftChild = rotateLeft(node->leftChild);
                return rotateRight(node);
            }
            // Right Left
            if (bf < -1 && data < node->leftChild->data) {
                node->rightChild = rotateRight(node->rightChild);
                return rotateLeft(node);
            }

            return node;
        }

        void insertNode(int data) {
            root = insert(root, data);
        }

        Node* search(Node* node, int data) {
            if (node == NULL) {
                return NULL;
            }
            if (node->data == data) {
                return node;
            }
            if (data < node->data) {
                return search(node->leftChild, data);
            } else {
                return search(node->rightChild, data);
            }
        }

        void searchAndInsert(int data) {
            Node* foundNode = search(root, data);
            if (foundNode != NULL) {
                cout << "Value " << data << " found at index " << foundNode->index << endl;
            } else {
                cout << "Value " << data << " not found." << endl;
                cout << "Inserting " << data << " in the tree." << endl;
                insertNode(data);
            }
        }

        void inOrderTraversal (Node *temp) {
            if (temp == NULL) return;

            inOrderTraversal(temp->leftChild);
            cout << temp->data << " ";
            inOrderTraversal(temp->rightChild);
        }
};

int main () {

    AVLTree t1;

    t1.insertNode(1);
    t1.insertNode(2);
    t1.insertNode(3);
    t1.insertNode(4);
    t1.insertNode(5);
    t1.insertNode(6);
    t1.insertNode(7);

    cout << "\n--------- In-Order Traversal ---------\n";
    t1.inOrderTraversal(t1.root);
    cout << endl;

    cout << "\n--------- Searching 5 and 10 ---------\n";
    t1.searchAndInsert(5);
    t1.searchAndInsert(10);

    cout << "\n--------- In-Order Traversal ---------\n";
    t1.inOrderTraversal(t1.root);
    cout << endl;

}