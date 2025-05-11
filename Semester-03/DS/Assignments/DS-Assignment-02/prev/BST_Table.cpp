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

// ------------------------------------------------------ Binary Search Tree ------------------------------------------------------
class RecordBST {
    public:
        static int totalIDs;
        int id;
        string name;
        int age;
        RecordBST() : id(++totalIDs), name(""), age(0) {}
        RecordBST(string n, int a) : id(++totalIDs), name(n), age(a) {}

        // copy constructor for deep copy
        RecordBST (const RecordBST &other) : id(other.id), name(other.name), age(other.age) {
        }

        // copy assignment operator
        RecordBST& operator=(const RecordBST &other) {
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
int RecordBST::totalIDs = 0;

class NodeBST {
    public:
        RecordBST record;
        NodeBST *leftChild;
        NodeBST *rightChild;

        NodeBST (RecordBST newRecord) : record(newRecord), leftChild(NULL), rightChild(NULL) {}
};

class BST_Table {
    public:
        NodeBST *root;

        BST_Table () : root(NULL) {}

        void createRecord () {
            string name;
            int age;
            cout << "__________ Create Record __________" << endl;
            cout << "Enter the name: ";
            getline(cin, name);
            cout << "Enter the age: ";
            age = getInt();
            cin.ignore();

            RecordBST newRecord(name, age);
            insertNode(newRecord);
        }

        void insertNode(RecordBST newRecord) {
            if (root == NULL) {
                root = new NodeBST(newRecord);
                return;
            }
            insertHelper(root, newRecord);
        }

        void insertHelper(NodeBST *temp, RecordBST newRecord, NodeBST *parent = NULL) {
            if (temp == NULL) {
                if (newRecord.id <= parent->record.id)
                    parent->leftChild = new NodeBST(newRecord);
                else
                    parent->rightChild = new NodeBST(newRecord);
                return;
            }

            parent = temp;
            if (newRecord.id <= parent->record.id)
                insertHelper(temp->leftChild, newRecord, parent);
            else
                insertHelper(temp->rightChild, newRecord, parent);
        }

        void deleteNode() {
            int target;
            cout << "Enter the ID that you want to delete: ";
            target = getInt();
            cin.ignore();

            bool deleted = deleteHelper(root, target);
            if (deleted) {
                cout << "ID " << target << " has been deleted." << endl;
            } else {
                cout << "ID " << target << " not found in the database and thus not deleted." << endl;
            }
        }

        bool deleteHelper(NodeBST*& temp, int target) {
            if (temp == NULL) return false; // base case: not found

            // find the node
            if (target < temp->record.id) {
                return deleteHelper(temp->leftChild, target);
            }
            else if (target > temp->record.id) {
                return deleteHelper(temp->rightChild, target);
            }
            else { // node found
                // case 1: no children
                if (temp->leftChild == NULL && temp->rightChild == NULL) {
                    delete temp;
                    temp = NULL; // Nullify the pointer to indicate deletion
                    return true;
                }

                // case 2: 01 children
                else if (temp->rightChild == NULL) { // node has left child
                    NodeBST* left = temp->leftChild;
                    delete temp;
                    temp = left; // move the left child up
                    return true;
                }
                else if (temp->leftChild == NULL) { // node has right child
                    NodeBST* right = temp->rightChild;
                    delete temp;
                    temp = right; // move the right child up
                    return true;
                }

                // case 3: 02 children
                NodeBST* inSuccessor = findInSuccessor(temp->rightChild);
                temp->record.id = inSuccessor->record.id;
                return deleteHelper(temp->rightChild, inSuccessor->record.id);
            }
            return false;
        }

        
        NodeBST* findInSuccessor(NodeBST* right) {
            while (right->leftChild != NULL) {
                right = right->leftChild;
            }
            return right;
        }
        
        NodeBST* search() {
            int target;
            cout << "__________ Search Record __________" << endl;
            cout << "Enter the ID that you want to search: ";
            target = getInt();
            cin.ignore();

            NodeBST* result = searchHelper(root, target);
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

        NodeBST* searchHelper(NodeBST *temp, int target) {
            if (temp == NULL) {
                return NULL;
            }

            if (target == temp->record.id) {
                return temp;
            }

            if (target <= temp->record.id) searchHelper(temp->leftChild, target);
            else searchHelper(temp->rightChild, target);
        }

        NodeBST* update() {
            int target;
            cout << "__________ Update Record __________" << endl;
            cout << "Enter the ID that you want to update: ";
            target = getInt();
            cin.ignore();

            NodeBST* result = searchHelper(root, target);
            if (result == NULL) {
                cout << "Updation failed. The ID was not found in the database." << endl;
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

        void inOrder (NodeBST *temp) {
            if (temp == NULL) return;
    
            inOrder(temp->leftChild);
            cout << "ID: " << temp->record.id << endl;
            cout << "Name: " << temp->record.name << endl;
            cout << "Age: " << temp->record.age << endl << endl;
            inOrder(temp->rightChild);
        }
};


int main () {

    BST_Table b1;
    b1.createRecord();
    b1.createRecord();
    b1.createRecord();
    b1.display();
    cout << endl;

    b1.deleteNode();
    b1.display();
    cout << endl;

    b1.search();
    
    b1.update();

    b1.display();
    cout << endl;

    return 0;
}