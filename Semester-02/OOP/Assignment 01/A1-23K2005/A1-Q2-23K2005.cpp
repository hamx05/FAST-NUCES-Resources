#include <iostream>
#include <cmath>
using namespace std;

#define N 5 // Number of tables

class Table {
    private:
        int totalSeats; // 4 or 8
        int occSeats; // Jitne log bethe hon
        int freeSeats; // Jitni seats free hon
        bool clean;

    public:
        Table () { // Default constructor
            totalSeats = 4;
            occSeats = 0;
            clean = true;
        }
        Table (int capacity) { // Parameterized constructor
            if (capacity % 4 == 0 || capacity % 8 == 0) {
                totalSeats = capacity;
            }

            else {
                int roundedCapacity = std::round((float)capacity / 4) * 4;
                if (capacity % 8 > 4) {
                    roundedCapacity = std::round((float)capacity / 8) * 8;
                }
                totalSeats = roundedCapacity;
            }
        }

        int getTotalSeats() const { return totalSeats; }
        int getOccSeats() const { return occSeats; }
        int getFreeSeats() const { return freeSeats; }
        bool isClean() const { return clean; }

        void changeTableProperties (int tempCapacity, int size) { // Called in OccupyTable
            totalSeats = tempCapacity;
            occSeats = size;
            freeSeats = totalSeats - occSeats;
        }

        void resetTable() { // Called in EmptyTable
            clean = true;
            occSeats = 0;
            freeSeats = totalSeats;
        }

        friend void Occupytable(Table tableArray[], int tableIndex, int sizeOfFriendsGroup);
        friend void Emptytable(Table tableArray[], int tableIndex);
        
        void useTable () {
            cout<< "The table is being used by " << occSeats << " people." << endl;
            freeSeats = totalSeats - occSeats;
        }

        void lunchOnTable () {
            cout<< "The table is now dirty, after the lunch." << endl;
            clean=0;
        }

        void leaveTable () {
            cout<<"The table is now empty and ready to be cleaned." << endl;
            freeSeats = totalSeats;
        }

        void cleanTable () {
            cout<<"The table has been cleaned and ready to allot." << endl;
            clean=1;
        }

};

void OccupyTable (Table tableArray[], int tableIndex, int sizeOfFriendsGroup) {
    int tempTotalSeats = tableArray[tableIndex].getTotalSeats();
    int tempOccSeats = tableArray[tableIndex].getOccSeats();
    bool tempClean = tableArray[tableIndex].isClean();

    if (tableIndex >= 0 && tableIndex < N) {
       if (tempTotalSeats >= sizeOfFriendsGroup) {
            cout << "You have been assigned table number " << tableIndex + 1 << "! The table has a capacity to fit " << tableArray[tableIndex].getTotalSeats() << " people." << endl;
            tableArray[tableIndex].changeTableProperties(tableArray[tableIndex].getTotalSeats(), sizeOfFriendsGroup);
        } else {
            cout << "Table " << tableIndex + 1 << " cannot be occupied." << endl;
        }
    } else {
        cout << "Invalid table number." << endl;
    }
}

void EmptyTable(Table tableArray[], int tableIndex) {
    if (tableIndex >= 0 && tableIndex < N) {
        cout<<"Table " << tableIndex + 1 << " has been made empty and ready to re-use." << endl;
        tableArray[tableIndex].resetTable();
    } else {
        cout << "Invalid table number." << endl;
    }
}

int main () {
	cout<<"********************"<<endl;
	cout<<"Name: Muhammad Hammad"<<endl;
	cout<<"Roll no: 23K-2005"<<endl;
	cout<<"********************"<<endl;
	
    Table tableArray[N] = {Table(4), Table(8), Table(8), Table(8), Table(4)};
    
    OccupyTable(tableArray, 0, 4);
    OccupyTable(tableArray, 1, 6);
    
    tableArray[0].useTable();
    tableArray[0].lunchOnTable();
    tableArray[0].leaveTable();
    tableArray[0].cleanTable();

    EmptyTable(tableArray, 1);

    return 0;
}
