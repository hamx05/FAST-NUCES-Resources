#include <iostream>
#include <algorithm>
using namespace std;

class Heap {
    public:
        int *arr;
        int size;

        Heap (int arr[], int size) {
            this->arr = arr;
            this->size = size;
        }

        void maxHeapify(int i) {
            int largest = i;
            int leftChild = (2 * i) + 1;
            int rightChild = (2 * i) + 2;

            if (leftChild < size && arr[leftChild] > arr[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && arr[rightChild] > arr[largest]) {
                largest = rightChild;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                maxHeapify(largest);
            }
        }

        void buildMaxHeap() {
            for (int i = (size / 2) - 1; i >= 0; i--) {
                maxHeapify(i);
            }
        }

        void maxHeapSort() {
            buildMaxHeap();

            int heapSize = size;
            for (int i = heapSize - 1; i > 0; i--) {
                swap(arr[0], arr[i]);
                heapSize--;
                maxHeapify(0);
            }
        }

        void printArray() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {

    int arr[] = {1, 2, 10, 3, 5, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Heap heap(arr, n);

    cout << "Original Array:" << endl;
    heap.printArray();

    heap.maxHeapSort();

    cout << "\nSorted Array:" << endl;
    heap.printArray();
    

    return 0;
}
