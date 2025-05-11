#include <iostream>
#include <algorithm>
using namespace std;

class Heap {
    public:
        int *arr;
        int size;

        Heap(int arr[], int size) {
            this->arr = arr;
            this->size = size;
        }

        void minHeapify(int i) {
                int smallest = i;
                int leftChild = (2 * i) + 1;
                int rightChild = (2 * i) + 2;

                if (leftChild < size && arr[leftChild] < arr[smallest]) {
                    smallest = leftChild;
                }
                if (rightChild < size && arr[rightChild] < arr[smallest]) {
                    smallest = rightChild;
                }

                if (smallest != i) {
                    swap(arr[i], arr[smallest]);
                    minHeapify(smallest);
                }
            }

        void buildMinHeap() {
                for (int i = (size / 2) - 1; i >= 0; i--) {
                    minHeapify(i);
                }
            }

        void minHeapSort() {
                buildMinHeap();

                int heapSize = size;

                for (int i = heapSize - 1; i > 0; i--) {
                    swap(arr[0], arr[i]);
                    heapSize--;
                    minHeapify(0);
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
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Heap heap(arr, n);

    cout << "Original Array:" << endl;
    heap.printArray();

    heap.minHeapSort();

    cout << "\nSorted Array:" << endl;
    heap.printArray();

    return 0;
}
