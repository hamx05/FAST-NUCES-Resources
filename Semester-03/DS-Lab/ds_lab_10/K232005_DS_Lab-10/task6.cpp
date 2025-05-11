#include <iostream>
using namespace std;

class MaxHeap {
    public:
        int *arr;
        int size;
        int capacity;

        MaxHeap(int cap) {
            size = 0;
            capacity = cap;
            arr = new int[capacity];
        }

        ~MaxHeap() {
            delete[] arr;
        }

        void heapify(int i) {
            int largest = i;
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;

            if (leftChild < size && arr[leftChild] > arr[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && arr[rightChild] > arr[largest]) {
                largest = rightChild;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapify(largest);
            }
        }

        void insert(int value) {
            if (size == capacity) {
                cout << "Heap is full!" << endl;
                return;
            }

            arr[size] = value;
            size++;

            int i = size - 1;
            while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
                swap(arr[(i - 1) / 2], arr[i]);
                i = (i - 1) / 2;
            }
        }

        int extractMax() {
            if (size <= 0) {
                return -1;
            }

            int max = arr[0];
            arr[0] = arr[size - 1];
            size--;

            heapify(0);

            return max;
        }

        int getSize() {
            return size;
        }
};

int minOperationsToMakeNonIncreasing(int* a, int n) {
    int operations = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            operations += a[i] - a[i - 1];
            a[i] = a[i - 1];
        }
    }

    return operations;
}

int main() {
    int N = 4;
    int array[] = {3, 1, 2, 1};

    int result = minOperationsToMakeNonIncreasing(array, N);
    
    cout << "Minimum operations required: " << result << endl;

    return 0;
}
