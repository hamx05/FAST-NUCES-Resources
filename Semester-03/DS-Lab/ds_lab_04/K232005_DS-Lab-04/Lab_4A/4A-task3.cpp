#include <iostream>
using namespace std;

// note: sorting explanation and logic taken from gpt
void combSort(int arr[], int n, float shrinkFactor) {
    int gap = n;
    bool swapped = false;

    while (gap > 1  || swapped) {
        gap = gap / shrinkFactor;

        if (gap < 1) {
            gap = 1;
        }
        swapped = false;

        for (int i=0; i<n-gap; i++) {
            if (arr[i] > arr[i+gap]) {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;
                swapped = true;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout << "Rs " << arr[i] << " - ";
    cout << endl;
}

int main() {

    int n;
    cout<<"Enter the number of products: ";
    cin >> n;
    int* arr = new int[n];
    
    for (int i=0; i<n; i++) {
        cout<<"Enter the price of product " << i+1 <<": ";
        cin >> arr[i];
    }

    float shrinkFactor = n / (n-3);

    combSort(arr, n, shrinkFactor);

    cout<<"Sorted product prices: ";
    printArray(arr, n);

    return 0;
}
