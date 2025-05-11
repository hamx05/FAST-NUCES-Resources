#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high, char choice) {
    if (choice != 'a' && choice != 'd') { // return any other choice
        cout<<"Invalid choice\n";
        return;
    }

    int left = low;
    int right = mid + 1;
    int temp[high - low + 1];
    int currIndex = 0;

    while (left <= mid && right <= high) {
        // ascending order
        if (choice == 'a') {
            if (arr[left] < arr[right]) {
                temp[currIndex] = arr[left];
                left++;
            }
            else {
                temp[currIndex] = arr[right];
                right++;
            }
        }
        // descending
        else if (choice == 'd') {
            if (arr[left] > arr[right]) {
                temp[currIndex] = arr[left];
                left++;
            }
            else {
                temp[currIndex] = arr[right];
                right++;
            }
        }
        currIndex++;
    }

    while (left <= mid) {
        temp[currIndex] = arr[left];
        left++;
        currIndex++;
    }

    while (right <= high) {
        temp[currIndex] = arr[right];
        right++;
        currIndex++;
    }

    for (int i=0; i<currIndex; i++) {
        arr[i + low] = temp[i];
    }
}

void mergeSort (int arr[], int low, int high, char choice) {
    if (low >= high) return;
    
    int mid = low + ((high-low)/2);
    mergeSort(arr, low,  mid, choice);
    mergeSort(arr, mid + 1, high, choice);
    merge(arr, low, mid, high, choice);
}

void print(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl<<endl;
}

int main () {

    int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array:\n";
    print(arr, n);

    // take input of choice and send it as parameter
    mergeSort(arr, 0, n-1, 'a');
    cout<<"Sorted in Ascending Order:\n";
    print(arr, n);
    
    mergeSort(arr, 0, n-1, 'd');
    cout<<"Sorted in Descending Order:\n";
    print(arr, n);

    return 0;
}