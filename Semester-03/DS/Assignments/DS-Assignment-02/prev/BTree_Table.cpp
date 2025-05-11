#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Considering a B Tree of Order 4
const int MAX_KEYS = 3;
const int MIN_KEYS = MAX_KEYS / 2;

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

class RecordBTree {
public:
    static int totalIDs;
    int id;
    string name;
    int age;

    RecordBTree() : id(++totalIDs), name(""), age(0) {}
    RecordBTree(string n, int a) : id(++totalIDs), name(n), age(a) {}
};
int RecordBTree::totalIDs = 0;

class NodeBTree {
public:
    RecordBTree records[MAX_KEYS];
    NodeBTree* children[MAX_KEYS + 1];
    int numKeys;
    bool isLeaf;

    NodeBTree(bool leaf) : numKeys(0), isLeaf(leaf) {
        for (int i = 0; i < MAX_KEYS + 1; i++) {
            children[i] = NULL;
        }
    }
};

class BTree_Table {
private:
    NodeBTree* root;

public:
    BTree_Table() : root(NULL) {}

    void createRecord() {
        string name;
        int age;
        cout << "__________ Create Record __________" << endl;
        cout << "Enter the name: ";
        getline(cin, name);
        cout << "Enter the age: ";
        age = getInt();
        cin.ignore();

        RecordBTree newRecord(name, age);
        insert(newRecord);
    }

    void insert(RecordBTree newRecord) {
        if (root == NULL) {
            root = new NodeBTree(true);
            root->records[0] = newRecord;
            root->numKeys = 1;
        } else {
            if (root->numKeys == MAX_KEYS) {
                NodeBTree* newNode = new NodeBTree(false);
                newNode->children[0] = root;
                splitChild(newNode, 0, root);
                root = newNode;
            }
            insertNonFull(root, newRecord);
        }
    }

    void insertNonFull(NodeBTree* node, RecordBTree newRecord) {
        int i = node->numKeys - 1;

        if (node->isLeaf) {
            while (i >= 0 && newRecord.id < node->records[i].id) {
                node->records[i + 1] = node->records[i];
                i--;
            }
            node->records[i + 1] = newRecord;
            node->numKeys++;
        } else {
            while (i >= 0 && newRecord.id < node->records[i].id) {
                i--;
            }
            i++;
            if (node->children[i]->numKeys == MAX_KEYS) {
                splitChild(node, i, node->children[i]);
                if (newRecord.id > node->records[i].id) {
                    i++;
                }
            }
            insertNonFull(node->children[i], newRecord);
        }
    }

    void splitChild(NodeBTree* parent, int index, NodeBTree* fullChild) {
        NodeBTree* newChild = new NodeBTree(fullChild->isLeaf);
        newChild->numKeys = MIN_KEYS;

        for (int j = 0; j < MIN_KEYS; j++) {
            newChild->records[j] = fullChild->records[j + MIN_KEYS + 1];
        }

        if (!fullChild->isLeaf) {
            for (int j = 0; j < MIN_KEYS + 1; j++) {
                newChild->children[j] = fullChild->children[j + MIN_KEYS + 1];
            }
        }

        fullChild->numKeys = MIN_KEYS;

        for (int j = parent->numKeys; j >= index + 1; j--) {
            parent->children[j + 1] = parent->children[j];
        }
        parent->children[index + 1] = newChild;

        for (int j = parent->numKeys - 1; j >= index; j--) {
            parent->records[j + 1] = parent->records[j];
        }
        parent->records[index] = fullChild->records[MIN_KEYS];
        parent->numKeys++;
    }

    void display() const {
        cout << "__________ Display Record __________" << endl;
        displayHelper(root);
    }

    void displayHelper(NodeBTree* node) const {
        if (node == NULL) return;

        for (int i = 0; i < node->numKeys; i++) {
            if (!node->isLeaf) {
                displayHelper(node->children[i]);
            }
            cout << "ID: " << node->records[i].id << endl;
            cout << "Name: " << node->records[i].name << endl;
            cout << "Age: " << node->records[i].age << endl << endl;
        }
        if (!node->isLeaf) {
            displayHelper(node->children[node->numKeys]);
        }
    }

    NodeBTree* search() const {
        cout << "__________ Search Record __________" << endl;
        int target;
        cout << "Enter the ID that you want to search in the database: ";
		target = getInt();
		
        NodeBTree* result = searchHelper(root, target);
        if (result == NULL) {
            cout << "ID " << target << " not found in the database." << endl;
        } else {
            cout << "ID " << target << " found in the database." << endl;
            for (int i = 0; i < result->numKeys; i++) {
                if (result->records[i].id == target) {
                	cout << "Details of ID " << result->records[i].id << ":" << endl;
                    cout << "Name: " << result->records[i].name << endl;
                    cout << "Age: " << result->records[i].age << endl;
                }
            }
        }
        return result;
    }

    NodeBTree* searchHelper(NodeBTree* node, int id) const {
        if (node == NULL) return NULL;

        int i = 0;
        while (i < node->numKeys && id > node->records[i].id) {
            i++;
        }
        if (i < node->numKeys && id == node->records[i].id) {
            return node;
        }
        if (node->isLeaf) {
            return NULL;
        }
        return searchHelper(node->children[i], id);
    }

    void update() {
        int id;
        cout << "__________ Update Record __________" << endl;
        cout << "Enter the ID that you want to update: ";
        id = getInt();

        NodeBTree* node = searchHelper(root, id);
        if (node == NULL) {
            cout << "Update failed. The ID was not found in the database." << endl;
            return;
        }

        string newName;
        int newAge;
        cout << "Enter new name for ID " << id << ": ";
        cin.ignore();
        getline(cin, newName);
        cout << "Enter new age for ID " << id << ": ";
        newAge = getInt();

        for (int i = 0; i < node->numKeys; i++) {
            if (node->records[i].id == id) {
                node->records[i].name = newName;
                node->records[i].age = newAge;
                cout << "Record for ID " << id << " has been updated." << endl;
                break;
            }
        }
    }
};

int main() {
    BTree_Table btree;
    btree.createRecord();
    btree.createRecord();
    btree.display();

    btree.update();
    btree.display();

    btree.search();

    return 0;
}
