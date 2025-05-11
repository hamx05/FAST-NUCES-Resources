#include <iostream>
using namespace std;

static int count = 0;
void sort (int arr[], int size, int currIndex, int comparingIndex) {
    if (currIndex == size || comparingIndex == size) {
        return;
    }
        // cout << "count: " << count << endl;
        // count++;
        
    if (arr[currIndex] < arr[comparingIndex]) {
        int temp = arr[currIndex];
        arr[currIndex] = arr[comparingIndex];
        arr[comparingIndex] = temp;
    }

    sort(arr, size, currIndex, comparingIndex+1);
    sort(arr, size, currIndex+1, comparingIndex+2);

}

int main () {

    int arr[5] = {12, 11, 13, 5, 6};
    sort(arr, 5, 0, 1);

    for (int i=0; i<5; i++) {
        cout<<arr[i] << " ";
    }

    return 0;
}