#include <iostream>
using namespace std;

#define rows 5
#define cols 5

/* Logic Assumption: I am assuming that the rows are the persons and columns are their friends.
So, I'll be checking every person's friends with others' friends i.e every row with the remaining rows*/

int main () {

    bool** friendsArray = new bool*[rows];
    
    for (int i=0; i<rows; i++) {
        friendsArray[i] = new bool[cols];
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout<<"Enter (" << i << "," << j <<") element: ";
            cin>>friendsArray[i][j];
        }
        cout<<endl;
    }

    // debug: displaying friendsArray
    // for (int i=0; i<rows; i++) {
    //     for (int j=0; j<cols; j++) {
    //         cout<<friendsArray[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for (int personA=0; personA<rows-1; personA++) {
        cout<<"\tChecking mutual friends of Person " << personA+1 <<" with others." << endl;
        for (int personB=personA+1; personB<rows; personB++) {
            cout<<"Common friends between Person " << personA+1 <<" and Person " << personB+1 << endl;
            for (int friendIndex=0; friendIndex<cols; friendIndex++) {
                if (friendsArray[personA][friendIndex] && friendsArray[personB][friendIndex]) {
                    cout<<"*  ";
                } else {
                    cout<<"X  ";
                }
            }
            cout<<endl;
        }
        cout<<"----------------------------------------------------------------------------" << endl;
    }

    cout<<"Person 05's friends have already been checked while traversing, so no need to check them again.";

    for (int i=0; i<rows; i++) {
        delete[] friendsArray[i];
    }
    delete[] friendsArray;

    return 0;
}