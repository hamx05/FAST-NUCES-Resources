#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {

    int output[n];
    int i, count[10] = {0,0,0,0,0,0,0,0,0,0};

    // finding out k kitne digits ka number ha
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // bas ye karna ha, part of algo
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n, char choice) {

    if (choice != 'a' && choice != 'd') {
        cout<<"Invalid choice\n";
        return;
    }

    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }

    // if descending, then reverse the ascending ordered array
    if (choice == 'd') {
        for (int i = 0; i < n / 2; i++) {
            swap(arr[i], arr[n - i - 1]);
        }
    }
    
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl << endl;
}

int main () {
    int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Original Array:\n";
    print(arr, n);

    // take input of choice and send it as parameter
    char choice = 'a';
    radixSort(arr, n, choice);
    cout<<"Sorted in Ascending Order:\n";
    print(arr, n);
    
    radixSort(arr, n, 'd');
    cout<<"Sorted in Descending Order:\n";
    print(arr, n);
    return 0;
}
