#include "btree.h"
#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <ctime>
#include <sstream>
#include <stdlib.h>

#define limit 10000
#define numOperations 20

extern int getInt();

int RecordBTree::totalIDs = 0;

RecordBTree::RecordBTree() : id(0), name(""), age(0) {}

RecordBTree::RecordBTree(std::string n, int a) : name(n), age(a) {
    id = ++totalIDs;
}

NodeBTree::NodeBTree(bool leaf) : numKeys(0), isLeaf(leaf) {
    for (int i = 0; i < MAX_KEYS + 1; i++) {
        children[i] = NULL;
    }
}

BTree_Table::BTree_Table() : root(NULL) {}

void BTree_Table::createRecord() {
    std::string name;
    int age;
    std::cout << "__________ Create Record __________" << std::endl;
    std::cout << "Enter the name: ";
    std::getline(std::cin, name);
    std::cout << "Enter the age: ";
    age = getInt();
    std::cin.ignore();

    RecordBTree newRecord(name, age);
    insert(newRecord);
}

void BTree_Table::insert(RecordBTree newRecord) {
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

void BTree_Table::insertNonFull(NodeBTree* node, RecordBTree newRecord) {
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

void BTree_Table::splitChild(NodeBTree* parent, int index, NodeBTree* fullChild) {
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

void BTree_Table::deleteNode() {
    if (root == NULL) {
        std::cout << "Unable to delete. The B-tree is empty." << std::endl;
        return;
    }

    int id;
    std::cout << "Enter the ID that you want to delete: ";
    id = getInt();

    bool deleted = deleteHelper(root, id);

    if (deleted) {
        std::cout << "ID " << id << " has been deleted." << std::endl;
    } else {
        std::cout << "Delete failed. The ID was not found in the database." << std::endl;
    }

    if (root->numKeys == 0) {
        NodeBTree* oldRoot = root;
        if (root->isLeaf) {
            root = NULL;
        } else {
            root = root->children[0];
        }
        delete oldRoot;
    }
}

bool BTree_Table::deleteHelper(NodeBTree* node, int id) {
    int i = 0;
    while (i < node->numKeys && id > node->records[i].id) {
        i++;
    }

    if (i < node->numKeys && id == node->records[i].id) {
        if (node->isLeaf) {
            for (int j = i; j < node->numKeys - 1; j++) {
                node->records[j] = node->records[j + 1];
            }
            node->numKeys--;
            return true;
        } else {
            if (node->children[i]->numKeys >= MIN_KEYS) {
                RecordBTree pred = getInOrderPredecessor(node, i);
                node->records[i] = pred;
                return deleteHelper(node->children[i], pred.id);
            } else if (node->children[i + 1]->numKeys >= MIN_KEYS) {
                RecordBTree succ = getInOrderSuccessor(node, i);
                node->records[i] = succ;
                return deleteHelper(node->children[i + 1], succ.id);
            } else {
                mergeChildren(node, i);
                return deleteHelper(node->children[i], id);
            }
        }
    } else {
        if (node->isLeaf) {
            return false;
        } else {
            bool deleted = deleteHelper(node->children[i], id);
            if (deleted && node->children[i]->numKeys < MIN_KEYS) {
                handleUnderflow(node, i);
            }
            return deleted;
        }
    }
}

void BTree_Table::mergeChildren(NodeBTree* parent, int index) {
    NodeBTree* leftChild = parent->children[index];
    NodeBTree* rightChild = parent->children[index + 1];

    leftChild->records[leftChild->numKeys] = parent->records[index];
    leftChild->numKeys++;

    for (int j = 0; j < rightChild->numKeys; j++) {
        leftChild->records[leftChild->numKeys + j] = rightChild->records[j];
    }
    leftChild->numKeys += rightChild->numKeys;

    if (!rightChild->isLeaf) {
        for (int j = 0; j <= rightChild->numKeys; j++) {
            leftChild->children[leftChild->numKeys + j] = rightChild->children[j];
        }
    }

    for (int j = index; j < parent->numKeys - 1; j++) {
        parent->records[j] = parent->records[j + 1];
        parent->children[j + 1] = parent->children[j + 2];
    }

    parent->numKeys--;
    delete rightChild;
}

RecordBTree BTree_Table::getInOrderPredecessor(NodeBTree* node, int index) {
    NodeBTree* current = node->children[index];
    while (!current->isLeaf) {
        current = current->children[current->numKeys];
    }
    return current->records[current->numKeys - 1];
}

RecordBTree BTree_Table::getInOrderSuccessor(NodeBTree* node, int index) {
    NodeBTree* current = node->children[index + 1];
    while (!current->isLeaf) {
        current = current->children[0];
    }
    return current->records[0];
}

void BTree_Table::handleUnderflow(NodeBTree* node, int index) {
    if (index > 0 && node->children[index - 1]->numKeys >= MIN_KEYS) {
        borrowFromLeft(node, index);
    } else if (index < node->numKeys && node->children[index + 1]->numKeys >= MIN_KEYS) {
        borrowFromRight(node, index);
    } else {
        if (index < node->numKeys) {
            mergeChildren(node, index);
        } else {
            mergeChildren(node, index - 1);
        }
    }
}

void BTree_Table::borrowFromLeft(NodeBTree* parent, int index) {
    NodeBTree* child = parent->children[index];
    NodeBTree* leftSibling = parent->children[index - 1];

    for (int i = child->numKeys - 1; i >= 0; i--) {
        child->records[i + 1] = child->records[i];
    }
    if (!child->isLeaf) {
        for (int i = child->numKeys; i >= 0; i--) {
            child->children[i + 1] = child->children[i];
        }
    }

    child->records[0] = parent->records[index - 1];

    if (!child->isLeaf) {
        child->children[0] = leftSibling->children[leftSibling->numKeys];
    }

    parent->records[index - 1] = leftSibling->records[leftSibling->numKeys - 1];
    
    child->numKeys++;
    leftSibling->numKeys--;
}

void BTree_Table::borrowFromRight(NodeBTree* parent, int index) {
    NodeBTree* child = parent->children[index];
    NodeBTree* rightSibling = parent->children[index + 1];

    child->records[child->numKeys] = parent->records[index];
    
    if (!child->isLeaf) {
        child->children[child->numKeys + 1] = rightSibling->children[0];
    }

    parent->records[index] = rightSibling->records[0];

    for (int i = 1; i < rightSibling->numKeys; i++) {
        rightSibling->records[i - 1] = rightSibling->records[i];
    }
    if (!rightSibling->isLeaf) {
        for (int i = 1; i <= rightSibling->numKeys; i++) {
            rightSibling->children[i - 1] = rightSibling->children[i];
        }
    }

    child->numKeys++;
    rightSibling->numKeys--;
}

void BTree_Table::display() const {
    if (root == NULL) {
        std::cout << "Unable to display records. The B-Tree database is empty right now." << std::endl;
        return;
    }
    std::cout << "__________ Display Record __________" << std::endl;
    displayHelper(root);
}

void BTree_Table::displayHelper(NodeBTree* node) const {
    if (node == NULL) return;

    for (int i = 0; i < node->numKeys; i++) {
        if (!node->isLeaf) {
            displayHelper(node->children[i]);
        }
        std::cout << "ID: " << node->records[i].id << std::endl;
        std::cout << "Name: " << node->records[i].name << std::endl;
        std::cout << "Age: " << node->records[i].age << std::endl << std::endl;
    }
    if (!node->isLeaf) {
        displayHelper(node->children[node->numKeys]);
    }
}

void BTree_Table::search() const {
    if (root == NULL) {
        std::cout << "Unable to search. The B-Tree is empty." << std::endl;
        return;
    }
    std::cout << "__________ Search Record __________" << std::endl;
    int target;
    std::cout << "Enter the ID that you want to search in the database: ";
    target = getInt();
    
    NodeBTree* result = searchHelper(root, target);
    if (result == NULL) {
        std::cout << "ID " << target << " not found in the database." << std::endl;
    } else {
        std::cout << "ID " << target << " found in the database." << std::endl;
        for (int i = 0; i < result->numKeys; i++) {
            if (result->records[i].id == target) {
                std::cout << "Details of ID " << result->records[i].id << ":" << std::endl;
                std::cout << "Name: " << result->records[i].name << std::endl;
                std::cout << "Age: " << result->records[i].age << std::endl;
            }
        }
    }
}

NodeBTree* BTree_Table::searchHelper(NodeBTree* node, int id) const {
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

void BTree_Table::update() {
    if (root == NULL) {
        std::cout << "Unable to update. The B-Tree is empty." << std::endl;
        return;
    }

    int id;
    std::cout << "__________ Update Record __________" << std::endl;
    std::cout << "Enter the ID that you want to update: ";
    id = getInt();

    NodeBTree* node = searchHelper(root, id);
    if (node == NULL) {
        std::cout << "Update failed. The ID was not found in the database." << std::endl;
        return;
    }

    std::string newName;
    int newAge;
    std::cout << "Enter new name for ID " << id << ": ";
    std::cin.ignore();
    std::getline(std::cin, newName);
    std::cout << "Enter new age for ID " << id << ": ";
    newAge = getInt();

    for (int i = 0; i < node->numKeys; i++) {
        if (node->records[i].id == id) {
            node->records[i].name = newName;
            node->records[i].age = newAge;
            std::cout << "Record updated successfully." << std::endl;
            return;
        }
    }
}

void BTree_Table::createDummyRecord() {
    std::cout << "__________ Create Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i=0; i<limit; i++) {
        std::string name = "Dummy";
        name += std::to_string(i+1);
        srand(time(0));
        int age = rand() % 42 + 18;
        RecordBTree newRecord(name, age);
        insert(newRecord);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "Dummy Record of " << limit << " people have been created." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void BTree_Table::searchDummyRecord(std::string ids, int idsArr[]) {
    std::cout << "\n__________ Search Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    std::cout << "Details of the searched IDs:" << std::endl;

    for (int i = 0; i < numOperations; i++) {
        NodeBTree* temp = searchHelper(root, idsArr[i]);
        if (temp != NULL) {
            for (int j = 0; j < temp->numKeys; j++) {
                if (temp->records[j].id == idsArr[i]) {
                    std::cout << "ID: " << temp->records[j].id << std::endl;
                    std::cout << "Name: " << temp->records[j].name << std::endl;
                    std::cout << "Age: " << temp->records[j].age << std::endl << std::endl;
                    break;
                }
            }
        } else {
            std::cout << "ID " << idsArr[i] << " not found in the database." << std::endl;
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << numOperations << " IDs (" << ids << ") have been searched and displayed." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

NodeBTree* BTree_Table::searchDummyRecordHelper(NodeBTree* node, int target) {
    if (node == NULL) {
        return NULL;
    }

    int i = 0;
    while (i < node->numKeys && target > node->records[i].id) {
        i++;
    }

    if (i < node->numKeys && target == node->records[i].id) {
        return node;
    }

    if (node->isLeaf) {
        return NULL;
    }

    return searchDummyRecordHelper(node->children[i], target);
}

void BTree_Table::updateDummyRecord(std::string ids, int idsArr[]) {
    std::cout << "\n__________ Update Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numOperations; i++) {
        updateDummyHelper(idsArr[i]);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << numOperations << " IDs (" << ids << ") have been updated." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void BTree_Table::updateDummyHelper(int target) {
    NodeBTree* temp = searchHelper(root, target);

    if (temp != NULL) {
        for (int i = 0; i < temp->numKeys; i++) {
            if (temp->records[i].id == target) {
                temp->records[i].name += " ka naya naam";
                srand(time(0));
                int age = rand() % 42 + 18;
                temp->records[i].age = age;
                std::cout << "------- Updated Details for ID " << target << " -------" << std::endl;
                std::cout << "Name: " << temp->records[i].name << std::endl;
                std::cout << "Age: " << temp->records[i].age << std::endl << std::endl;
                break;
            }
        }
    } else {
        std::cout << "ID " << target << " not found in the database." << std::endl;
    }
}

void BTree_Table::deleteDummyRecord(std::string ids, int idsArr[]) {
    std::cout << "\n__________ Delete Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numOperations; i++) {
        deleteDummyRecordHelper(root, idsArr[i]);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << numOperations << " IDs (" << ids << ") have been deleted." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void BTree_Table::deleteDummyRecordHelper(NodeBTree* node, int target) {
    if (node == NULL) {
        return;
    }

    int i = 0;
    while (i < node->numKeys && target > node->records[i].id) {
        i++;
    }

    if (i < node->numKeys && target == node->records[i].id) {
        for (int j = i; j < node->numKeys - 1; j++) {
            node->records[j] = node->records[j + 1];
        }
        node->numKeys--;

        std::cout << "ID " << target << " has been deleted." << std::endl;
    } else if (!node->isLeaf) {
        deleteDummyRecordHelper(node->children[i], target);
    }
}

void BTree_Table::performDummyOperations() {
    createDummyRecord();
    if (root == NULL) {
        std::cout << "Unable to perform operations ahead since there is no dummy record in the database." << std::endl;
        return;
    }

    int idsArray[numOperations] = {(limit/20) * 1, (limit/20) * 2, (limit/20) * 3, (limit/20) * 4, (limit/20) * 5, (limit/20) * 6, (limit/20) * 7, (limit/20) * 8, (limit/20) * 9,
                                  (limit/20) * 10, (limit/20) * 11, (limit/20) * 12, (limit/20) * 13, (limit/20) * 14, (limit/20) * 15, (limit/20) * 16, (limit/20) * 17, 
                                  (limit/20) * 18, (limit/20) * 19, (limit/20) * 20};
    std::string ids = "";
    for (int i=0; i<numOperations; i++) {
        ids = ids + std::to_string(idsArray[i]) + ", ";
    }
    ids.erase(ids.length() - 2 );
    searchDummyRecord(ids, idsArray);
    updateDummyRecord(ids, idsArray);
    deleteDummyRecord(ids, idsArray);
}