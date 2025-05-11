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

        bool search (Node *temp, int target) {
            if (temp == NULL) {
                cout << target << " is not found in the tree." << endl;
                return false;
            }

            if (target == temp->data) {
                cout << target << " is found in the tree." << endl;
                return true;
            }

            if (target <= temp->data) search(temp->leftChild, target);
            else search(temp->rightChild, target);
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

    b1.insertNode(35);
    b1.insertNode(30);
    b1.insertNode(21);
    b1.insertNode(65);
    b1.insertNode(4);
    b1.insertNode(81);

    cout << "------------------------- Pre-Order Traversal -------------------------\n";
    b1.preOrderTraversal(b1.root);

    cout << "\n------------------------- Search -------------------------\n";
    cout << "Enter the value that you wanna search for: ";
    int target;
    cin >> target;
  
    if (!b1.search(b1.root, target)) {
        cout << "Inserting " << target << " in the tree." << endl;
        b1.insertNode(target);
        cout << "------------------------- Pre-Order Traversal -------------------------\n";
        b1.preOrderTraversal(b1.root);
        cout << endl;
    }
}