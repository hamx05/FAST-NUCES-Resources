#include <iostream>
using namespace std;

// for descending order
void bubbleSort (int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        bool flagSwap = false;
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flagSwap = true;
            }
        }
        if (!flagSwap) {
            break;
        }
    }
    return;
}

void print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
}

int main () {
    
    int arr[10] = {5,1,3,6,2,9,7,4,8,10};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<"Original Array: " << endl;
    print(arr, n);

    bubbleSort(arr, n);

    cout<<"\n\nSorted Array: " << endl;
    print(arr, n);


    return 0;
}