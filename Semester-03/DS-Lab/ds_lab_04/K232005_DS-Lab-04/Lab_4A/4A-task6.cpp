#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main () {

    int n;
    cout<<"Enter the number of crates: ";
    cin >> n;

    int *arr = new int(n);
    
    for (int i=0; i<n; i++) {
        cout<<"Enter shipping wait time (in hours) of crate " << i+1 << ": ";
        cin>>arr[i];
    }

    cout<<"Original Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    selectionSort(arr, n);

    cout<<"\n\nSorted Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    return 0;
}