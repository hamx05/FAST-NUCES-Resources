#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>

class RecordBST {
    public:
        static int totalIDs;
        int id;
        std::string name;
        int age;
        RecordBST();
        RecordBST(std::string n, int a);
        RecordBST(const RecordBST &other);
        RecordBST& operator=(const RecordBST &other);
};

class NodeBST {
    public:
        RecordBST record;
        NodeBST *leftChild;
        NodeBST *rightChild;
        NodeBST(RecordBST newRecord);
};

class BST_Table {
    public:
        NodeBST *root;
        BST_Table();
        void createRecord();
        void insertNode(RecordBST newRecord);
        void insertHelper(NodeBST *temp, RecordBST newRecord, NodeBST *parent = NULL);
        void deleteNode();
        bool deleteHelper(NodeBST*& temp, int target);
        NodeBST* findInSuccessor(NodeBST* right);
        void search();
        NodeBST* searchHelper(NodeBST *temp, int target);
        void update();
        void display();
        void inOrder(NodeBST *temp);
        void createDummyRecord();
        void searchDummyRecord(std::string ids, int idsArr[]);
        void updateDummyRecord(std::string ids, int idsArr[]);
        void updateDummyHelper(int target);
        void deleteDummyRecord(std::string ids, int idsArr[]);
        void performDummyOperations();
};

#endif