#include "avl.h"
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

int RecordAVL::totalIDs = 0;

RecordAVL::RecordAVL() : id(++totalIDs), name(""), age(0) {}

RecordAVL::RecordAVL(std::string n, int a) : id(++totalIDs), name(n), age(a) {}

RecordAVL::RecordAVL(const RecordAVL &other) : id(other.id), name(other.name), age(other.age) {}

RecordAVL& RecordAVL::operator=(const RecordAVL &other) {
    if (this == &other) {
        return *this;
    }
    this->id = other.id;
    this->name = other.name;
    this->age = other.age;
    return *this;
}

NodeAVL::NodeAVL(RecordAVL newRecord) : record(newRecord), height(0), leftChild(NULL), rightChild(NULL) {}

AVL_Table::AVL_Table() : root(NULL) {}

int AVL_Table::getHeight(NodeAVL* node) {
    if (node == NULL) return 0;
    return node->height;
}

void AVL_Table::updateHeight(NodeAVL* node) {
    node->height = 1 + std::max(getHeight(node->leftChild), getHeight(node->rightChild));
}

int AVL_Table::getBalanceFactor(NodeAVL* node) {
    if (node == NULL) return 0;
    return (getHeight(node->leftChild) - getHeight(node->rightChild));
}

NodeAVL* AVL_Table::rotateRight(NodeAVL* y) {
    NodeAVL *x = y->leftChild;
    NodeAVL *T2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

NodeAVL* AVL_Table::rotateLeft(NodeAVL* x) {
    NodeAVL* y = x->rightChild;
    NodeAVL *T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

void AVL_Table::createRecord() {
    std::string name;
    int age;
    std::cout << "__________ Create Record __________" << std::endl;
    std::cout << "Enter the name: ";
    std::getline(std::cin, name);
    std::cout << "Enter the age: ";
    age = getInt();
    std::cin.ignore();

    RecordAVL newRecord(name, age);
    insertNode(newRecord);
}

void AVL_Table::insertNode(RecordAVL newRecord) {
    if (root == NULL) {
        root = new NodeAVL(newRecord);
        return;
    }
    root = insertHelper(root, newRecord);
}

NodeAVL* AVL_Table::insertHelper(NodeAVL* temp, RecordAVL newRecord) {
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

    if (balanceFactor > 1 && newRecord.id < temp->leftChild->record.id) {
        return rotateRight(temp);
    }

    if (balanceFactor < -1 && newRecord.id > temp->rightChild->record.id) {
        return rotateLeft(temp);
    }

    if (balanceFactor > 1 && newRecord.id > temp->leftChild->record.id) {
        temp->leftChild = rotateLeft(temp->leftChild);
        return rotateRight(temp);
    }

    if (balanceFactor < -1 && newRecord.id < temp->rightChild->record.id) {
        temp->rightChild = rotateRight(temp->rightChild);
        return rotateLeft(temp);
    }
    
    return temp;
}

void AVL_Table::deleteNode() {
    if (root == NULL) {
        std::cout << "Unable to delete. The AVL Tree is empty." << std::endl;
        return;
    }

    int target;
    std::cout << "Enter the ID that you want to delete: ";
    target = getInt();
    std::cin.ignore();

    bool deleted = false;
    root = deleteHelper(root, target, deleted);

    if (deleted) {
        std::cout << "ID " << target << " has been deleted successfully." << std::endl;
    } else {
        std::cout << "Deletion failed. ID not found in the database." << std::endl;
    }
}

NodeAVL* AVL_Table::deleteHelper(NodeAVL* temp, int target, bool& deleted) {
    if (temp == NULL) return NULL;

    if (target < temp->record.id) {
        temp->leftChild = deleteHelper(temp->leftChild, target, deleted);
    }
    else if (target > temp->record.id) {
        temp->rightChild = deleteHelper(temp->rightChild, target, deleted);
    }
    else {
        deleted = true;

        if (temp->leftChild == NULL && temp->rightChild == NULL) {
            delete temp;
            return NULL;
        }
        else if (temp->leftChild == NULL) {
            NodeAVL* right = temp->rightChild;
            delete temp;
            return right;
        } else if (temp->rightChild == NULL) {
            NodeAVL* left = temp->leftChild;
            delete temp;
            return left;
        }
        else {
            NodeAVL* inSuccessor = findInSuccessor(temp->rightChild);
            temp->record = inSuccessor->record;
            temp->rightChild = deleteHelper(temp->rightChild, inSuccessor->record.id, deleted);
        }
    }

    updateHeight(temp);
    int bf = getBalanceFactor(temp);

    if (bf > 1 && getBalanceFactor(temp->leftChild) >= 0) {
        return rotateRight(temp);
    }
    if (bf > 1 && getBalanceFactor(temp->leftChild) < 0) {
        temp->leftChild = rotateLeft(temp->leftChild);
        return rotateRight(temp);
    }
    if (bf < -1 && getBalanceFactor(temp->rightChild) <= 0) {
        return rotateLeft(temp);
    }
    if (bf < -1 && getBalanceFactor(temp->rightChild) > 0) {
        temp->rightChild = rotateRight(temp->rightChild);
        return rotateLeft(temp);
    }
    return temp;
}

NodeAVL* AVL_Table::findInSuccessor(NodeAVL* right) {
    while (right->leftChild != NULL) {
        right = right->leftChild;
    }
    return right;
}

void AVL_Table::search() {
    if (root == NULL) {
        std::cout << "Unable to search. The AVL Tree is empty." << std::endl;
        return;
    }

    int target;
    std::cout << "__________ Search Record __________" << std::endl;
    std::cout << "Enter the ID that you want to search: ";
    target = getInt();
    std::cin.ignore();

    NodeAVL* result = searchHelper(root, target);
    if (result == NULL) {
        std::cout << "ID " << target << " not found in the database." << std::endl;
        return;
    }
    std::cout << "ID " << target << " found in the database." << std::endl;
    std::cout << "Details of ID " << target << ":" << std::endl;
    std::cout << "Name: " << result->record.name << std::endl;
    std::cout << "Age: " << result->record.age << std::endl;
    return;
}

NodeAVL* AVL_Table::searchHelper(NodeAVL *temp, int target) {
    if (temp == NULL) {
        return NULL;
    }

    if (target == temp->record.id) {
        return temp;
    }

    if (target <= temp->record.id) 
        return searchHelper(temp->leftChild, target);
    else
        return searchHelper(temp->rightChild, target);
}

void AVL_Table::update() {
    if (root == NULL) {
        std::cout << "Unable to update. The AVL Tree is empty." << std::endl;
        return;
    }

    int target;
    std::cout << "__________ Update Record __________" << std::endl;
    std::cout << "Enter the ID that you want to update: ";
    target = getInt();
    std::cin.ignore();

    NodeAVL* result = searchHelper(root, target);
    if (result == NULL) {
        std::cout << "Update failed. The ID was not found in the database." << std::endl;
        return;
    } 

    std::string newName;
    int newAge;
    std::cout << "Enter new name for ID " << target << ": ";
    std::getline(std::cin, newName);
    std::cout << "Enter new age for ID " << target << ": ";
    newAge = getInt();
    std::cin.ignore();

    result->record.name = newName;
    result->record.age = newAge;

    std::cout << "Record for ID " << target << " has been updated." << std::endl;
    return;
}

void AVL_Table::display() {
    if (root == NULL) {
        std::cout << "Unable to display records. The AVL Tree database is empty right now." << std::endl;
        return;
    }
    std::cout << "__________ Display Record __________" << std::endl;
    inOrder(root);
}

void AVL_Table::inOrder(NodeAVL *temp) {
    if (temp == NULL) return;

    inOrder(temp->leftChild);
    std::cout << "ID: " << temp->record.id << std::endl;
    std::cout << "Name: " << temp->record.name << std::endl;
    std::cout << "Age: " << temp->record.age << std::endl << std::endl;
    inOrder(temp->rightChild);
}

void AVL_Table::createDummyRecord() {
    std::cout << "__________ Create Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i=0; i<limit; i++) {
        std::string name = "Dummy";
        name += std::to_string(i+1);
        srand(time(0));
        int age = rand() % 42 + 18;
        RecordAVL newRecord(name, age);
        insertNode(newRecord);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "Dummy Record of " << limit << " people have been created." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void AVL_Table::searchDummyRecord(std::string ids, int idsArr[]) {
    std::cout << "\n__________ Search Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    std::cout << "Details of the searched IDs:" << std::endl;
    for (int i = 0; i < numOperations; i++) {
        NodeAVL* temp = searchHelper(root, idsArr[i]);
        if (temp != NULL) {
            std::cout << "ID: " << temp->record.id << std::endl;
            std::cout << "Name: " << temp->record.name << std::endl;
            std::cout << "Age: " << temp->record.age << std::endl << std::endl;
        } else {
            std::cout << "ID " << idsArr[i] << " not found in the database." << std::endl;
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << numOperations << " IDs (" << ids << ") have been searched and displayed." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void AVL_Table::updateDummyRecord(std::string ids, int idsArr[]) {
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

void AVL_Table::updateDummyHelper(int target) {
    NodeAVL* temp = searchHelper(root, target);
    if (temp != NULL) {
        temp->record.name += " ka naya naam";
        srand(time(0));
        int age = rand() % 42 + 18;
        temp->record.age = age;
        std::cout << "------- Updated Details for ID " << target << " -------" << std::endl;
        std::cout << "Name: " << temp->record.name << std::endl;
        std::cout << "Age: " << temp->record.age << std::endl << std::endl;
    } else {
        std::cout << "ID " << target << " not found in the database." << std::endl;
    }
}

void AVL_Table::deleteDummyRecord(std::string ids, int idsArr[]) {
    std::cout << "\n__________ Delete Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numOperations; i++) {
        bool deleted = false;
        root = deleteHelper(root, idsArr[i], deleted);

        if (deleted) {
            std::cout << "ID " << idsArr[i] << " has been deleted." << std::endl;
        } else {
            std::cout << "Delete failed. " << idsArr[i] << " not found in the dummy database." << std::endl;
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << numOperations << " IDs (" << ids << ") have been deleted." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void AVL_Table::performDummyOperations() {
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