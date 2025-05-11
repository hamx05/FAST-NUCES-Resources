#include <iostream>
using namespace std;


void printStar (int rows) {
    if (rows ==0) {
        return;
    }
    cout<<"* ";
    printStar (rows-1);
}

void jumpRow (int rows) {
    if (rows== 0) {
        return;
    }


    static int count = 1;
    printStar(count);
    count++;
    cout<<endl;
    jumpRow(rows-1);
}


int main () {

    jumpRow(5);

    return 0;
}