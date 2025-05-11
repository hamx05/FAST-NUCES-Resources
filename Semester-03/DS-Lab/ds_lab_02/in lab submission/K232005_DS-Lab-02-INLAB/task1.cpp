#include <iostream>
using namespace std;

int main () {

    /* NOTE: Writing a code to generalize, otherwise for our case, we dont need 'size' and 'sizes' array
    as we know that we have 5 rows and 10 columns only. */

    int i, j;
    int size;
        
    cout<<"Enter number of rows: ";
    cin>>size;

    int **jaggedArray = new int*[size];
    int sizes[size];

    for (i=0; i<size; i++) {
        cout<<"Enter size for Row " << i + 1 <<": ";
        cin>> sizes[i];
        jaggedArray[i] = new int[sizes[i]];
    }

    cout<<endl;

    for (i = 0; i < size; i++) {
        for (j = 0; j < sizes[i]; j++) {
            cout << "Enter row " << i + 1 << " element " << j + 1 << ": ";
            cin >> jaggedArray[i][j];
        }
        cout<<endl;
    }

    cout<<"Jagged Array:"<<endl;
    for (i = 0; i < size; i++) {
        for (j = 0; j < sizes[i]; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    for (i = 0; i < size; i++) {
        delete[] jaggedArray[i];
    }

    delete[] jaggedArray;
    
    return 0;
}