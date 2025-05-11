#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>

class RecordAVL {
    public:
        static int totalIDs;
        int id;
        std::string name;
        int age;
        RecordAVL();
        RecordAVL(std::string n, int a);
        RecordAVL(const RecordAVL &other);
        RecordAVL& operator=(const RecordAVL &other);
};

class NodeAVL {
    public:
        RecordAVL record;
        NodeAVL *leftChild;
        NodeAVL *rightChild;
        int height;
        NodeAVL(RecordAVL newRecord);
};

class AVL_Table {
    public:
        NodeAVL *root;
        AVL_Table();
        int getHeight(NodeAVL* node);
        void updateHeight(NodeAVL* node);
        int getBalanceFactor(NodeAVL* node);
        NodeAVL* rotateRight(NodeAVL* y);
        NodeAVL* rotateLeft(NodeAVL* x);
        void createRecord();
        void insertNode(RecordAVL newRecord);
        NodeAVL* insertHelper(NodeAVL* temp, RecordAVL newRecord);
        void deleteNode();
        NodeAVL* deleteHelper(NodeAVL* temp, int target, bool& deleted);
        NodeAVL* findInSuccessor(NodeAVL* right);
        void search();
        NodeAVL* searchHelper(NodeAVL *temp, int target);
        void update();
        void display();
        void inOrder(NodeAVL *temp);
        void createDummyRecord();
        void searchDummyRecord(std::string ids, int idsArr[]);
        void updateDummyRecord(std::string ids, int idsArr[]);
        void updateDummyHelper(int target);
        void deleteDummyRecord(std::string ids, int idsArr[]);
        void performDummyOperations();
};

#endif