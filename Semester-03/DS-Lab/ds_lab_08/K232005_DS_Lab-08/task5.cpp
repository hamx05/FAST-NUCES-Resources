#include <iostream>
using namespace std;

class Node {
    public:
        int id;
        int quantity;
        Node *leftChild;
        Node *rightChild;

        Node () : id(0), quantity(0), leftChild(NULL), rightChild(NULL) {}      
        Node (int d, int q) : id(d), quantity(q), leftChild(NULL), rightChild(NULL) {}
};

class BinaryTree {
    public:
        Node* root;

        BinaryTree () : root(NULL) {}

        void insert (int id, int qty) {
            if (root == NULL) {
                root = new Node(id, qty);
                return;
            }

            Node *temp = root;
            Node *parent = NULL;

            while (temp != NULL) {
                parent = temp;

                if (id <= temp->id) {
                    temp = temp->leftChild;
                } else {
                    temp = temp->rightChild;
                }
            }

            if (id <= parent->id) parent->leftChild = new Node(id, qty);
            else parent->rightChild = new Node(id, qty);
        }

        void update (int targetID, int newQuantity) {
            Node* targetNode = search(targetID);

            if (targetNode) {
                cout << "Product ID " << targetID << "'s quantity have been updated to " << newQuantity << "." << endl;
                targetNode->quantity = newQuantity;
            }
        }
    
        void findHighestQuantityProduct (Node *temp, Node* &maxQuantityProduct) {
            if (temp == NULL) return;

            if (temp->quantity > maxQuantityProduct->quantity || maxQuantityProduct == NULL) {
                maxQuantityProduct = temp;
            }
            findHighestQuantityProduct(temp->leftChild, maxQuantityProduct);
            findHighestQuantityProduct(temp->rightChild, maxQuantityProduct);
        }

        void printHighestQuantityProduct () {
            Node* maxQuantityProduct ;
            maxQuantityProduct->quantity = 0;
            findHighestQuantityProduct(root, maxQuantityProduct);
            if (maxQuantityProduct->quantity != 0) {
                cout << "Product ID " << maxQuantityProduct->id << " has the highest quanity that is: " << maxQuantityProduct->quantity << endl;
            } else {
                cout << "There is no quantity available in the inventory." << endl;
            }
        }

        void inOrderTraversal (Node *temp) {
            if (temp == NULL) return;

            inOrderTraversal(temp->leftChild);
            cout << "Product ID: " << temp->id << " - Quanitity: " << temp->quantity << endl;
            inOrderTraversal(temp->rightChild);
        }

        Node* search(int id) {
            return searchHelper(root, id);
        }

        Node* searchHelper (Node *temp, int targetID) {
            if (temp == NULL) {
                cout << "Product ID " << targetID << " not found." << endl;
                return NULL;
            }

            if (targetID == temp->id) {
                cout << "Product ID " << targetID << " found." << endl;
                return temp;
            }

            if (targetID <= temp->id) searchHelper(temp->leftChild, targetID);
            else searchHelper(temp->rightChild, targetID);
        }
};

int main () {

    BinaryTree b1;
    
    b1.insert(5, 30);
    b1.insert(3, 25);
    b1.insert(1, 35);
    b1.insert(2, 70);
    b1.insert(4, 5);

    cout << "---------- Products ----------\n";
    b1.inOrderTraversal(b1.root);
    cout << endl;


    cout << "---------- Update ----------\n";
    b1.update(3, 100);
    cout << endl;
    
    cout << "---------- Search ----------\n";
    b1.search(2);
    b1.search(10);
    cout << endl;

    cout << "---------- Product with Highest Quantity ----------\n";
    b1.printHighestQuantityProduct();

    return 0;
}