#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (target < arr[mid]) { // Ignore right side
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

void insertElement(int*& arr, int& size, int target, int pos) {
    int* newArr = new int[size + 1];
    
    for (int i=0; i<pos; i++) {
        newArr[i] = arr[i];
    }    
    newArr[pos] = target;
    for (int i=pos; i<size; i++) {
        newArr[i+1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size++;
}

int main() {
    // int arr[7] = {3, 6, 7, 10, 15, 16, 20};
    int size = 5;
    int* arr = new int[5];
    arr[0] = 3; arr[1] = 6; arr[2] = 7; arr[3] = 10; arr[4] = 15; arr[5] = 16;

    cout<<"Original Array: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl<< endl;
    
    int target = 5; // last 2 digits 05
    int pos = binarySearch(arr, size, target);

    if (pos >= size || arr[pos] != target) {
        cout<<"Target '" << target << "' not found in the array."<<endl;
        cout<<"Inserting '" << target << "' in the array: ";
        insertElement(arr, size, target, pos);
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    else {
        cout<<"Target '" << target << "' found at position: " << pos + 1 << endl;
    }

    delete[] arr;
    return 0;
}