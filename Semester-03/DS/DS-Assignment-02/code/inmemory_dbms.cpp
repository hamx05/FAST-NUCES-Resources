#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "bst.h"
#include "avl.h"
#include "btree.h"

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

void printOptions() {
    cout << "1. Perform Dummy Operations" << endl;
    cout << "2. Create new/original record" << endl;
    cout << "3. Delete record" << endl;
    cout << "4. Display all records" << endl;
    cout << "5. Search a record" << endl;
    cout << "6. Update a record" << endl;
    cout << "7. Go back to select table" << endl;
    cout << "8. Exit Program" << endl;
    cout << "Your choice: ";
}

int main() {
    int tableChoice, choice;
    BST_Table bst;
    AVL_Table avl;
    BTree_Table btree;
    
    do {
        cout << "\n------------------ Muhammad Hammad || 23K-2005 -------------------";
        cout << "\n--------------------- Trees Database System ----------------------";
        cout << "\nSelect which table to work with:" << endl;
        cout << "1. Binary Search Tree (BST)" << endl;
        cout << "2. AVL Tree" << endl;
        cout << "3. B-Tree" << endl;
        cout << "4. Exit Program" << endl;
        cout << "Your choice: ";
        tableChoice = getInt();
        cin.ignore();

        if (tableChoice == 1) {
            do {
                cout << "\n------------------ Muhammad Hammad || 23K-2005 -------------------";
                cout << "\n--------------------- Trees Database System ----------------------";
                cout << "\nBST Table Operations:" << endl;
                printOptions();
                choice = getInt();
                cin.ignore();

                switch (choice) {
                    case 1:
                        bst.performDummyOperations();
                        break;
                    case 2:
                        bst.createRecord();
                        break;
                    case 3:
                        bst.deleteNode();
                        break;
                    case 4:
                        bst.display();
                        break;
                    case 5:
                        bst.search();
                        break;
                    case 6:
                        bst.update();
                        break;
                    case 7:
                        break;
                    case 8:
                        cout << "\nExiting Program... Ba-bye!" << endl;
                        return 0;
                    default:
                        cout << "Invalid choice, try again." << endl;
                        break;
                }
            } while (choice != 7);
        }
        else if (tableChoice == 2) {
            do {
                cout << "\n------------------ Muhammad Hammad || 23K-2005 -------------------";
                cout << "\n--------------------- Trees Database System ----------------------";
                cout << "\nAVL Table Operations:" << endl;
                printOptions();
                choice = getInt();
                cin.ignore();

                switch (choice) {
                    case 1:
                        avl.performDummyOperations();
                        break;
                    case 2:
                        avl.createRecord();
                        break;
                    case 3:
                        avl.deleteNode();
                        break;
                    case 4:
                        avl.display();
                        break;
                    case 5:
                        avl.search();
                        break;
                    case 6:
                        avl.update();
                        break;
                    case 7:
                        break;
                    case 8:
                        cout << "\nExiting Program... Ba-bye!" << endl;
                        return 0;
                    default:
                        cout << "Invalid choice, try again." << endl;
                        break;
                }
            } while (choice != 7);
        }
        else if (tableChoice == 3) {
            do {
                cout << "\n------------------ Muhammad Hammad || 23K-2005 -------------------";
                cout << "\n--------------------- Trees Database System ----------------------";
                cout << "\nBTree Table Operations:" << endl;
                printOptions();
                choice = getInt();
                cin.ignore();

                switch (choice) {
                    case 1:
                    	btree.performDummyOperations();
                        break;
                    case 2:
                        btree.createRecord();
                        break;
                    case 3:
                        btree.deleteNode();
                        break;
                    case 4:
                        btree.display();
                        break;
                    case 5:
                        btree.search();
                        break;
                    case 6:
                        btree.update();
                        break;
                    case 7:
                        break;
                    case 8:
                        cout << "\nExiting Program... Ba-bye!" << endl;
                        return 0;
                    default:
                        cout << "Invalid choice, try again." << endl;
                        break;
                }
            } while (choice != 7);
        }
        else if (tableChoice == 4) {
            cout << "\nExiting program... Ba-bye!" << endl;
            break;
        } else {
            cout << "Invalid choice, try again." << endl;
        }

    } while (true);

    return 0;
}