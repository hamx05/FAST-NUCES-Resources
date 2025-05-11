#include <iostream>
using namespace std;

class MaxHeapSort {
    public:
        int *arr;
        int size;

        MaxHeapSort (int arr[], int size) {
            this->arr = arr;
            this->size = size;
        }

        void heapify (int i, int heapSize) {
            int largest = i;
            int leftChild = (2 * i) + 1;
            int rightChild = (2 * i) + 2;

            if (leftChild < heapSize && arr[leftChild] > arr[largest]) {
                largest = leftChild;
            }

            if (rightChild < heapSize && arr[rightChild] > arr[largest]) {
                largest = rightChild;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapify(largest, heapSize);
            }
        }

        void buildMaxHeap() {
            for (int i = (size/2)-1; i>=0; i--) {
                heapify(i, size);
            }
        }

        void heapSort() {
            buildMaxHeap();

            int heapSize = size;

            for (int i = heapSize - 1; i > 0; i--) {
                swap(arr[0], arr[i]);
                heapSize--;
                heapify(0, heapSize);
            }
        }
    
        void printSortedArray() {
            cout << "Sorted array: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};


class MinHeapSort {
    public:
        int *arr;
        int size;

        MinHeapSort (int arr[], int size) {
            this->arr = arr;
            this->size = size;
        }

        void heapify (int i, int heapSize) {
            int smallest = i;
            int leftChild = (2 * i) + 1;
            int rightChild = (2 * i) + 2;

            if (leftChild < heapSize && arr[leftChild] < arr[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < heapSize && arr[rightChild] < arr[smallest]) {
                smallest = rightChild;
            }

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                heapify(smallest, heapSize);
            }
        }

        void buildMinHeap() {
            for (int i = (size/2)-1; i>=0; i--) {
                heapify(i, size);
            }
        }

        void heapSort() {
            buildMinHeap();

            int heapSize = size;

            for (int i = heapSize - 1; i > 0; i--) {
                swap(arr[0], arr[i]);
                heapSize--;
                heapify(0, heapSize);
            }
        }
    
        void printSortedArray() {
            cout << "Sorted array: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};



int main () {

    int arr[] = {4, 10, 3, 5, 1};
    
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    MaxHeapSort hp1(arr, arrSize);
    hp1.heapSort();
    hp1.printSortedArray();

    MinHeapSort hp2(arr, arrSize);
    hp2.heapSort();
    hp2.printSortedArray();

    return 0;
}