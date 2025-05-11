#include <iostream>
using namespace std;

void shellSort (int arr[], int gap, int size) {
    int count = 0;
    int j;
    for (gap = size / 2; gap > 0; gap = gap / 2) {
        for (int i=gap; i<size; i++) {
            int temp = arr[i];
                j = i; 
                while (j >= gap && arr[j-gap]>temp) {
                    arr[j] = arr[j - gap];
                    j = j - gap;
                    count++;
                }
                arr[j] = temp;
        }
    }
    // cout << "\ncount (for time complexity): " << count;
}

void print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " kg, ";
    }
}


int main () {

    int arr[11] = {50,66,54,78,74,90,96,102,120,60,63};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Original Array: " << endl;
    print(arr, n);

    // formula to calculate gap: total weight / total people
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }

    int gap = sum/n;

    shellSort(arr, 15, n);

    cout<<"\n\nSorted Array: " << endl;
    print(arr, n);

    // number of loops (or time complexity) seemed to be same with gap = 2, gap with my formula, and other random gaps (e.g. 10, 12, 15).

    return 0;
}