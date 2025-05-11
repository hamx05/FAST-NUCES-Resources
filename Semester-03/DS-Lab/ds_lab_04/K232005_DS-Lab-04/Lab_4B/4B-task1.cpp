#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i=0; i<size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main () {

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    int target = 5;
    int index = linearSearch(arr, n, target);

    cout<<"Original Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    if (index != -1) {
        cout<<"\nTarget '"<< target << "' found at index: " << index << endl;
    } else {
        cout<<"\nTarget '"<< target << "' not found in the array." <<endl;
    }

    return 0;
}