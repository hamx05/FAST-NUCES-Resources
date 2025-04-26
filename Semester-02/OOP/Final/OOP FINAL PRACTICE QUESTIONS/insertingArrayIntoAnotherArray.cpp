#include <iostream>
using namespace std;

// Inserting an array into another array at a certain index.

template <typename T>
void Insert (T* source, T* dest, int sourceSize, int destSize, int index) {
    int i, j, k;
    T* temp = new T[sourceSize + destSize];

    for (i=0; i<=index; i++) { // 3
        temp[i] = source[i];
    }
    for (j=0; j<=destSize-1; j++) { // 3
        temp[i] = dest[j];
        i++;
    }
    for (k=1; k<=sourceSize-index; k++) {
        temp[i] = source[index+k];
        i++;
    }

    delete []source;
    
    source = new T[sourceSize + destSize];

    for (i=0; i<sourceSize+destSize; i++) {
        source[i] = temp[i];
    }

    delete []temp;

    cout<<"New Source: {";
    for (i=0; i< sourceSize+destSize; i++) {
        cout<<source[i] << ", ";
    }
    cout<<"}";
}


int main() {

    int source[] = {1,0,1,1,0,0};
    int dest[] = {0,0,1};
    // temp[] = {1,0,1,0,0,1,1,0,0};

    // int sourceSize = source.size();
    // int destSize = dest.size();

    Insert<int> (source, dest, 6, 3, 0);

    return 0;
}