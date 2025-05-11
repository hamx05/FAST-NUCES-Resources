#include <iostream>
#include "matrix_multiply.h"
using namespace std;

int main () {
	
    int matrix1[2][2];
    int matrix2[2][2];
    int resultantMatrix[2][2];

    cout<<"--------Details for Matrix 01--------" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout<<"Enter (" << i << "," << j <<") element: ";
            cin>>matrix1[i][j];
        }
    }

    cout<<"\n--------Details for Matrix 02--------" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout<<"Enter (" << i << "," << j <<") element: ";
            cin>>matrix2[i][j];
        }
    }

    multiply2DMatrix(matrix1, matrix2, resultantMatrix);
	
    cout<<"\n--------Resultant Matrix--------" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout<<"\t  "<<resultantMatrix[i][j] << "   ";
        }
        cout<<endl;
    }

    return 0;
}
