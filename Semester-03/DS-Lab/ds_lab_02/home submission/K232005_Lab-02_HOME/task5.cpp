#include <iostream>
using namespace std;

int main () {

    int rows;
    cout<<"Enter the number of rows: ";
    cin >> rows;
    int rowsCapacity[rows];

    string **seating = new string*[rows];
    for (int i=0; i<rows; i++) {
        cout<<"Enter the number of seat capacity in row "<< i+1 <<": "; 
        cin>> rowsCapacity[i];
        seating[i] = new string[rowsCapacity[i]];
    }
    
    // store data
    for (int i=0; i<rows; i++) {
        for (int j=0; j<rowsCapacity[i]; j++) {
            cout<<"Enter the name for Row " << i+1 << ", Seat " << j+1 <<": ";
            cin>>seating[i][j];
        }
        cout<<endl;
    }

    // display
    for (int i=0; i<rows; i++) {
        for (int j=0; j<rowsCapacity[i]; j++) {
            cout<<"Name on Row " << i+1 << ", Seat " << j+1 <<": " << seating[i][j];
            cout<<endl;
        }
        cout<<endl;
    }


    return 0;
}