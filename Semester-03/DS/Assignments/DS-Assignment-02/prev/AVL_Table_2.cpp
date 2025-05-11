#include <iostream>
#include <string>
#include <limits>
using namespace std;

int getInt() {
    int n;
    for (;;) {
        if (cin >> n) {
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry. Please enter an integer: ";
    }
}

// ------------------------------------------------------ AVL Tree ------------------------------------------------------
class RecordAVL {
    public:
        static int totalIDs;
        int id;
        string name;
        int age;
        RecordAVL() : id(++totalIDs), name(""), age(0) {}
        RecordAVL(string n, int a) : id(++totalIDs), name(n), age(a) {}

        // copy constructor for deep copy
        RecordAVL (const RecordAVL &other) : id(other.id), name(other.name), age(other.age) {
        }

        // copy assignment operator
        RecordAVL& operator=(const RecordAVL &other) {
            // self assignment check
            if (this == &other) {
                return *this;
            }
            this->id = other.id;
            this->name = other.name;
            this->age = other.age;
            return *this;
        }
};
int RecordAVL::totalIDs = 0;

class NodeAVL {
    public:
        RecordAVL record;
        NodeAVL *leftChild;
        NodeAVL *rightChild;
        int height;

        NodeAVL (RecordAVL newRecord) : record(newRecord), height(0), leftChild(NULL), rightChild(NULL) {}
};

class AVL_Table {
    public:
        NodeAVL *root;

        AVL_Table () : root(NULL) {}

        int getHeight (NodeAVL* node) {
            if (node == NULL) return 0;
            return node->height;
        }

        void updateHeight(NodeAVL* node) {
            node->height = 1 + max(getHeight(node->leftChild), getHeight(node->rightChild));
        }

        int getBalanceFactor (NodeAVL* node) {
            if (node == NULL) return 0;
            return (getHeight(node->leftChild) - getHeight(node->rightChild));
        }

        NodeAVL* rotateRight (NodeAVL* y) {
            NodeAVL *x = y->leftChild;
            NodeAVL *T2 = x->rightChild;

            x->rightChild = y;
            y->leftChild = T2;

            updateHeight(y);
            updateHeight(x);
            return x;
        }

        NodeAVL* rotateLeft (NodeAVL* x) {
            NodeAVL* y = x->rightChild;
            NodeAVL *T2 = y->leftChild;

            y->leftChild = x;
            x->rightChild = T2;

            updateHeight(x);
            updateHeight(y);

            return y;
        }

        void createRecord () {
            string name;
            int age;
            cout << "__________ Create Record __________" << endl;
            cout << "Enter the name: ";
            getline(cin, name);
            cout << "Enter the age: ";
            age = getInt();
            cin.ignore();

            RecordAVL newRecord(name, age);
            insertNodeAVL(newRecord);
        }

        void insertNodeAVL(RecordAVL newRecord) {
            if (root == NULL) {
                root = new NodeAVL(newRecord);
                return;
            }
            insertHelper(root, newRecord);
        }

        NodeAVL* insertHelper(NodeAVL* temp, RecordAVL newRecord) {
            // base case: if tree is empty, then this node becomes the root
            if (temp == NULL) {
                return new NodeAVL(newRecord);
            }

            if (newRecord.id < temp->record.id) {
                temp->leftChild = insertHelper(temp->leftChild, newRecord);
            } else if (newRecord.id > temp->record.id) {
                temp->rightChild = insertHelper(temp->rightChild, newRecord);
            } else {
                return temp;
            }

            updateHeight(temp);
            int balanceFactor = getBalanceFactor(temp);

            // Left Left Case
            if (balanceFactor > 1 && newRecord.id < temp->leftChild->record.id) {
                return rotateRight(temp);
            }

            // Right Right Case
            if (balanceFactor < -1 && newRecord.id > temp->rightChild->record.id) {
                return rotateLeft(temp);
            }

            // Left Right Case
            if (balanceFactor > 1 && newRecord.id > temp->leftChild->record.id) {
                temp->leftChild = rotateLeft(temp->leftChild);
                return rotateRight(temp);
            }

            // Right Left Case
            if (balanceFactor < -1 && newRecord.id < temp->rightChild->record.id) {
                temp->rightChild = rotateRight(temp->rightChild);
                return rotateLeft(temp);
            }
            
            return temp;
        }

        void deleteNodeAVL() {
            int target;
            cout << "Enter the ID that you want to delete: ";
            target = getInt();
            cin.ignore();

            bool deleted = deleteHelper(root, target); // update root after deletion
            if (deleted) {
                cout << "ID " << target << " has been deleted." << endl;
            } else {
                cout << "Deletion failed. The ID was not found in the database." << endl;
            }
        }

        bool deleteHelper(NodeAVL*& temp, int target) {
            if (temp == NULL) return false; // base case: not found

            bool deleted = false;
            
            // find the node
            if (target < temp->record.id) {
                deleted = deleteHelper(temp->leftChild, target);
            }
            else if (target > temp->record.id) {
                deleted = deleteHelper(temp->rightChild, target);
            }
            else { // node found
                deleted = true;
                
                // case 1: node with no children
                if (temp->leftChild == NULL && temp->rightChild == NULL) {
                    delete temp;
                    temp = NULL;
                }
                // case 2: node with one child
                else if (temp->leftChild == NULL) { // only right child
                    NodeAVL* right = temp->rightChild;
                    delete temp;
                    temp = right;
                }
                else if (temp->rightChild == NULL) { // only left child
                    NodeAVL* left = temp->leftChild;
                    delete temp;
                    temp = left;
                }
                // case 3: node with two children
                else {
                    NodeAVL* inSuccessor = findInSuccessor(temp->rightChild);
                    temp->record.id = inSuccessor->record.id;
                    deleteHelper(temp->rightChild, inSuccessor->record.id);
                }
            }

            if (!deleted) return false;

            updateHeight(temp);
            int bf = getBalanceFactor(temp);

            // Left Left Case
            if (bf > 1 && getBalanceFactor(temp->leftChild) >= 0) {
                temp = rotateRight(temp);
            }
            // Left Right Case
            else if (bf > 1 && getBalanceFactor(temp->leftChild) < 0) {
                temp->leftChild = rotateLeft(temp->leftChild);
                temp = rotateRight(temp);
            }
            // Right Right Case
            else if (bf < -1 && getBalanceFactor(temp->rightChild) <= 0) {
                temp = rotateLeft(temp);
            }
            // Right Left Case
            else if (bf < -1 && getBalanceFactor(temp->rightChild) > 0) {
                temp->rightChild = rotateRight(temp->rightChild);
                temp = rotateLeft(temp);
            }

            return true;
        }
        
        NodeAVL* findInSuccessor(NodeAVL* right) {
            while (right->leftChild != NULL) {
                right = right->leftChild;
            }
            return right;
        }
        
        NodeAVL* search() {
            int target;
            cout << "__________ Search Record __________" << endl;
            cout << "Enter the ID that you want to search: ";
            target = getInt();
            cin.ignore();

            NodeAVL* result = searchHelper(root, target);
            if (result == NULL) {
                cout << "ID " << target << " not found in the database." << endl;
                return NULL;
            }
            cout << "ID " << target << " found in the database." << endl;
            cout << "Details of ID " << target << ":" << endl;;
            cout << "Name: " << result->record.name << endl;
            cout << "Age: " << result->record.age << endl;
            return result;
        }

        NodeAVL* searchHelper(NodeAVL *temp, int target) {
            if (temp == NULL) {
                return NULL;
            }

            if (target == temp->record.id) {
                return temp;
            }

            if (target <= temp->record.id) searchHelper(temp->leftChild, target);
            else searchHelper(temp->rightChild, target);
        }

        NodeAVL* update() {
            int target;
            cout << "__________ Update Record __________" << endl;
            cout << "Enter the ID that you want to update: ";
            target = getInt();
            cin.ignore();

            NodeAVL* result = searchHelper(root, target);
            if (result == NULL) {
                cout << "Update failed. The ID was not found in the database." << endl;
                return NULL;
            } 

            string newName;
            int newAge;
            cout << "Enter new name for ID " << target << ": ";
            getline(cin, newName);
            cout << "Enter new age for ID " << target << ": ";
            newAge = getInt();
            cin.ignore();

            result->record.name = newName;
            result->record.age = newAge;

            cout << "Record for ID " << target << " has been updated." << endl;
            return result;
        }

        void display() {
            cout << "__________ Display Record __________" << endl;
            inOrder(root);
        }

        void inOrder (NodeAVL *temp) {
            if (temp == NULL) return;
    
            inOrder(temp->leftChild);
            cout << "ID: " << temp->record.id << endl;
            cout << "Name: " << temp->record.name << endl;
            cout << "Age: " << temp->record.age << endl << endl;
            inOrder(temp->rightChild);
        }
};


int main () {

    AVL_Table b1;
    b1.createRecord();
    b1.createRecord();
    b1.createRecord();
    b1.display();
    cout << endl;

    b1.deleteNodeAVL();
    b1.display();
    cout << endl;

    b1.search();
    
    b1.update();

    b1.display();
    cout << endl;

    return 0;
}