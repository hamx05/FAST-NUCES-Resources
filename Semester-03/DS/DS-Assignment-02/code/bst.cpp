#include "bst.h"
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

int RecordBST::totalIDs = 0;

RecordBST::RecordBST() : id(++totalIDs), name(""), age(0) {}

RecordBST::RecordBST(std::string n, int a) : id(++totalIDs), name(n), age(a) {}

RecordBST::RecordBST(const RecordBST &other) : id(other.id), name(other.name), age(other.age) {}

RecordBST& RecordBST::operator=(const RecordBST &other) {
    if (this == &other) {
        return *this;
    }
    this->id = other.id;
    this->name = other.name;
    this->age = other.age;
    return *this;
}

NodeBST::NodeBST(RecordBST newRecord) : record(newRecord), leftChild(NULL), rightChild(NULL) {}

BST_Table::BST_Table() : root(NULL) {}

void BST_Table::createRecord() {
    std::string name;
    int age;
    std::cout << "__________ Create Record __________" << std::endl;
    std::cout << "Enter the name: ";
    std::getline(std::cin, name);
    std::cout << "Enter the age: ";
    age = getInt();
    std::cin.ignore();

    RecordBST newRecord(name, age);
    insertNode(newRecord);
}

void BST_Table::insertNode(RecordBST newRecord) {
    if (root == NULL) {
        root = new NodeBST(newRecord);
        return;
    }
    insertHelper(root, newRecord);
}

void BST_Table::insertHelper(NodeBST *temp, RecordBST newRecord, NodeBST *parent) {
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

void BST_Table::deleteNode() {
    if (root == NULL) {
        std::cout << "Unable to delete. The BST is empty." << std::endl;
        return;
    }

    int target;
    std::cout << "Enter the ID that you want to delete: ";
    target = getInt();
    std::cin.ignore();

    bool deleted = deleteHelper(root, target);
    if (deleted) {
        std::cout << "ID " << target << " has been deleted." << std::endl;
    } else {
        std::cout << "Delete failed. The ID was not found in the database." << std::endl;
    }
}

bool BST_Table::deleteHelper(NodeBST*& temp, int target) {
    if (temp == NULL) return false;

    if (target < temp->record.id) {
        return deleteHelper(temp->leftChild, target);
    }
    else if (target > temp->record.id) {
        return deleteHelper(temp->rightChild, target);
    }
    else {
        if (temp->leftChild == NULL && temp->rightChild == NULL) {
            delete temp;
            temp = NULL;
            return true;
        }
        else if (temp->rightChild == NULL) {
            NodeBST* left = temp->leftChild;
            delete temp;
            temp = left;
            return true;
        }
        else if (temp->leftChild == NULL) {
            NodeBST* right = temp->rightChild;
            delete temp;
            temp = right;
            return true;
        }

        NodeBST* inSuccessor = findInSuccessor(temp->rightChild);
        temp->record.id = inSuccessor->record.id;
        return deleteHelper(temp->rightChild, inSuccessor->record.id);
    }
    return false;
}

NodeBST* BST_Table::findInSuccessor(NodeBST* right) {
    while (right->leftChild != NULL) {
        right = right->leftChild;
    }
    return right;
}

void BST_Table::search() {
    if (root == NULL) {
        std::cout << "Unable to search. The BST is empty." << std::endl;
        return;
    }

    int target;
    std::cout << "__________ Search Record __________" << std::endl;
    std::cout << "Enter the ID that you want to search: ";
    target = getInt();
    std::cin.ignore();

    NodeBST* result = searchHelper(root, target);
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

NodeBST* BST_Table::searchHelper(NodeBST *temp, int target) {
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

void BST_Table::update() {
    if (root == NULL) {
        std::cout << "Unable to update. The BST is empty." << std::endl;
        return;
    }

    int target;
    std::cout << "__________ Update Record __________" << std::endl;
    std::cout << "Enter the ID that you want to update: ";
    target = getInt();
    std::cin.ignore();

    NodeBST* result = searchHelper(root, target);
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
}

void BST_Table::display() {
    if (root == NULL) {
        std::cout << "Unable to display records. The BST database is empty right now." << std::endl;
        return;
    }
    std::cout << "__________ Display Record __________" << std::endl;
    inOrder(root);
}

void BST_Table::inOrder(NodeBST *temp) {
    if (temp == NULL) return;

    inOrder(temp->leftChild);
    std::cout << "ID: " << temp->record.id << std::endl;
    std::cout << "Name: " << temp->record.name << std::endl;
    std::cout << "Age: " << temp->record.age << std::endl << std::endl;
    inOrder(temp->rightChild);
}

void BST_Table::createDummyRecord() {
    std::cout << "\n__________ Create Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < limit; i++) {
        std::string name = "Dummy";
        name += std::to_string(i + 1);    
        srand(time(0));
        int age = rand() % 42 + 18;
        RecordBST newRecord(name, age);
        insertNode(newRecord);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "Dummy Record of " << limit << " people have been created." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void BST_Table::searchDummyRecord(std::string ids, int idsArr[]) {
    std::cout << "\n__________ Search Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    std::cout << "Details of the searched IDs:" << std::endl;
    for (int i=0; i<numOperations; i++) {
        NodeBST* temp = searchHelper(root, idsArr[i]);
        if (temp != NULL) {
            std::cout << "ID: " << temp->record.id << std::endl;
            std::cout << "Name: " << temp->record.name << std::endl;
            std::cout << "Age: " << temp->record.age << std::endl << std::endl;
        }
        else {
            std::cout << "ID " << idsArr[i] << " not found in the database." << std::endl;
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << numOperations << " IDs ("<< ids << ") have been searched and displayed." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void BST_Table::updateDummyRecord(std::string ids, int idsArr[]) {
    std::cout << "\n__________ Update Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i=0; i<numOperations; i++) {
        updateDummyHelper(idsArr[i]);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << numOperations << " IDs ("<< ids << ") have been updated." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void BST_Table::updateDummyHelper(int target) {
    NodeBST* temp = searchHelper(root, target);

    if (temp != NULL) {
        temp->record.name += " ka naya naam";
        srand(time(0));
        int age = rand() % 42 + 18;
        temp->record.age = age;
        std::cout << "------- Updated Details for ID " << target << " -------" << std::endl;
        std::cout << "Name: " << temp->record.name << std::endl;
        std::cout << "Age: " <<  temp->record.age << std::endl << std::endl;
    }
    else {
        std::cout << "ID " << target << " not found in the database." << std::endl;
    }
}

void BST_Table::deleteDummyRecord(std::string ids, int idsArr[]) {
    std::cout << "\n__________ Delete Dummy Record __________" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i=0; i<numOperations; i++) {
        if(deleteHelper(root, idsArr[i])) {
            std::cout << "ID " << idsArr[i] << " has been deleted." << std::endl;
        }
        else {
            std::cout << "Delete failed." << idsArr[i] << " not found in the dummy database." << std::endl;
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << numOperations << " IDs ("<< ids << ") have been deleted." << std::endl;
    std::cout << "Duration: " << duration.count() << " milliseconds." << std::endl;
}

void BST_Table::performDummyOperations() {
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