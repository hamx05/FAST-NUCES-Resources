#include <iostream>
using namespace std;

int main () {

    int nums[] = {0,1,0,0,1,1,1,0,1,0};
    int n=10;

    cout << "\nOrig array: ";
    for (int i=0; i<n; i++) {
        printf("%d", nums[i]);
    }

    processNums(nums,n);
    cout << "\nProcessed array: ";

    for (int i=0; i<n; i++) {
        cout << nums[i] << "";
    }

    return 0;
}

void processNums (int nums[], int n) {
    
    int i=-1, j=0;

    for (;j<n; j++) {
        if (nums[j]==1) {
            swap(nums[i+1],nums[j]);
            i++;
        }
    }
}