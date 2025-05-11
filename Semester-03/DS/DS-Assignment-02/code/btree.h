#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>

const int MAX_KEYS = 3;
const int MIN_KEYS = MAX_KEYS / 2;

class RecordBTree {
    public:
        static int totalIDs;
        int id;
        std::string name;
        int age;
        RecordBTree();
        RecordBTree(std::string n, int a);
};

class NodeBTree {
    public:
        RecordBTree records[MAX_KEYS];
        NodeBTree* children[MAX_KEYS + 1];
        int numKeys;
        bool isLeaf;
        NodeBTree(bool leaf);
};

class BTree_Table {
    private:
        NodeBTree* root;

    public:
        BTree_Table();
        void createRecord();
        void insert(RecordBTree newRecord);
        void insertNonFull(NodeBTree* node, RecordBTree newRecord);
        void splitChild(NodeBTree* parent, int index, NodeBTree* fullChild);
        void deleteNode();
        bool deleteHelper(NodeBTree* node, int id);
        void mergeChildren(NodeBTree* parent, int index);
        RecordBTree getInOrderPredecessor(NodeBTree* node, int index);
        RecordBTree getInOrderSuccessor(NodeBTree* node, int index);
        void handleUnderflow(NodeBTree* node, int index);
        void borrowFromLeft(NodeBTree* parent, int index);
        void borrowFromRight(NodeBTree* parent, int index);
        void display() const;
        void displayHelper(NodeBTree* node) const;
        void search() const;
        NodeBTree* searchHelper(NodeBTree* node, int id) const;
        void update();
        void createDummyRecord();
        void searchDummyRecord(std::string ids, int idsArr[]);
        NodeBTree* searchDummyRecordHelper(NodeBTree* node, int target);
        void updateDummyRecord(std::string ids, int idsArr[]);
        void updateDummyHelper(int target);
        void deleteDummyRecord(std::string ids, int idsArr[]);
        void deleteDummyRecordHelper(NodeBTree* node, int target);
        void performDummyOperations();
};

#endif