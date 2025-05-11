#include <iostream>
using namespace std;

void printArray (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
}

void shellSort(int arr[], int n) {
    for (int gap=n/2; gap>=1; gap /= 2) {
        for (int j=gap; j<n; j++) {
            for (int i=j-gap; i>=0; i -= gap) {
                if (arr[i+gap] < arr[i]) {
                    int temp = arr[i];
                    arr[i] = arr[i+gap];
                    arr[i+gap] = temp;
                } else {
                    break;
                }
            }
        }
    }

    cout<<"Sorted Array: " << endl;
    printArray(arr, n);
}

bool isSameDifference (int arr[], int n) {
    int difference = arr[1] - arr[0];
    for (int i=1; i<n-1; i++) {
        if (arr[i+1] - arr[i] != difference) {
            return false;
        } 
    }
    return true;
}

int interpolationSearch (int arr[], int n, int target) {

    shellSort(arr, n);

    if (!isSameDifference(arr, n)) return -2;

    int low = 0;
    int high = n-1;

    while (low<=high && target>=arr[low] && target<=arr[high]) {
        int mid = low + (((high - low)*(target - arr[low])) / (arr[high] - arr[low]));

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) { // ignore elements at left side
            low = mid+1;
        }
        else { // ignore elements at right side
            high = mid-1;
        }
    }
    return -1;
}

int main () {
    
    int arr[7] = {10000, 30000, 20000, 50000, 70000, 40000, 60000};
    int n = sizeof(arr)/sizeof(int);

    cout<<"\nOriginal Array: " << endl;
    printArray(arr,  n);
    cout<<endl;

    int target = 50000;
    int index = interpolationSearch(arr, n, target);

    if (index == -1) {
        cout<<"\nTarget '"<< target << "' not found in the array." <<endl;
    }
    else if (index == -2) {
        cout<<"\nERROR: Array is not uniformly distributed." << endl;
    }
    else {
        cout<<"\nTarget '"<< target << "' found at position: " << index+1 << endl;
    }

    return 0;

}