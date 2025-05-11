#include <iostream>
using namespace std;

int partition (int arr[], int low, int high) {
    int mid = low + ((high-low)/2);
    int pivot = arr[mid];
    int start = low;
    int end = high;

    while (start <= end) {
        while (arr[start] < pivot && start <= high) {
            start++;
        }

        while (arr[end] > pivot && end >= low) {
            end--;
        }

        if (start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    return start - 1;
    // return start;

}

void quickSort (int arr[], int low, int high) {
    if (low >= high) return;
    int pIndex = partition(arr, low, high);
    quickSort(arr, low,  pIndex - 1);
    quickSort(arr, pIndex + 1, high);
}

void print(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

int main () {

    int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array:\n";
    print(arr, n);

    quickSort(arr, 0, n-1);

    cout<<"Sorted Array:\n";
    print(arr, n);
}