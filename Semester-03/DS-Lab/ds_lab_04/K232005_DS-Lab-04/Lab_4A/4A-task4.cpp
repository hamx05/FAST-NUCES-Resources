#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int rank = arr[i];
       int j = i - 1;
        while (j >= 0 && arr[j] > rank){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = rank;
    }
}

int saveByPriority (string designation) {
    if (designation == "CEO") return 1;
    if (designation == "CTO") return 2;
    if (designation == "CFO") return 3;
    if (designation == "VP") return 4;
    if (designation == "MGR") return 5;
    if (designation == "EMP") return 6;
    return -1; // if none of the roles
}

string restoreStaff (int rank) {
    if (rank == 1) return "CEO";
    if (rank == 2) return "CTO";
    if (rank == 3) return "CFO";
    if (rank == 4) return "VP";
    if (rank == 5) return "MGR";
    if (rank == 6) return "EMP";
    return "Other"; // must be -1.
}

void print (string arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " - ";
    }
}

int main () {

    string arr[7] = {"EMP", "EMP", "MGR", "CFO", "CEO", "CTO", "CFO"};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array: " << endl;
    print(arr, n);
   
    int staff[n];
    for (int i=0; i<n; i++) {
        staff[i] = saveByPriority(arr[i]);
    }

    insertionSort(staff, n);
   
    for (int i=0; i<n; i++) {
        arr[i] = restoreStaff(staff[i]);
    }

    cout<<"\n\nSorted Array: " << endl;
    print(arr, n);

    return 0;
}