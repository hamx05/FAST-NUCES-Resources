#include <iostream>
using namespace std;

class MaxHeap {
    public:
        int capacity;
        int size;
        int *arr;

        MaxHeap (int c) : size(0), capacity(c) {
            arr = new int[capacity];
        }

        ~MaxHeap () {
            delete[] arr;
        }
                
        void heapify(int i) {
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
                swap(arr[largest], arr[i]);
                heapify(largest);
            }
        }

        void insert(int value) {
            if (size == capacity) {
                cout << "The array is full beta." << endl;
                return;
            }

            int i = size;
            arr[i] = value;
            size++;

            while (i != 0 && arr[(i-1)/2] < arr[i]) {
                swap(arr[(i-1)/2], arr[i]);
                i = (i - 1) / 2;
            }
        }

        int extractMax() {
            if (size == 0) {
                cout << "Heap is empty. Cannot extract maximum element.";
            return -1;
            }
            
            int max = arr[0];

            arr[0] = arr[size - 1];
            size--;

            heapify(0);
            return max;
        }

        void deleteMax() {
            extractMax();
        }

        void printArray() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

        }
};



class MinHeap {
    public:
        int capacity;
        int size;
        int *arr;

        MinHeap (int c) : size(0), capacity(c) {
            arr = new int[capacity];
        }

        ~MinHeap () {
            delete[] arr;
        }
                
        void heapify(int i) {
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
                swap(arr[smallest], arr[i]);
                heapify(smallest);
            }
        }

        void insert(int value) {
            if (size == capacity) {
                cout << "The array is full beta." << endl;
                return;
            }

            int i = size;
            arr[i] = value;
            size++;

            while (i != 0 && arr[(i-1)/2] > arr[i]) {
                swap(arr[(i-1)/2], arr[i]);
                i = (i - 1) / 2;
            }
        }

        int extractMin() {
            if (size == 0) {
                cout << "Heap is empty. Cannot extract minimum element.";
            return -1;
            }
            
            // Store the root element
            int min = arr[0];

            // Replace the root with the last element
            arr[0] = arr[size - 1];
            size--;

            // Heapify the root
            heapify(0);
            return min;
        }

        void deleteMin() {
            extractMin();
        }

        void printArray() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main () {

    MaxHeap h1(10);
    h1.insert(7);
    h1.insert(1);
    h1.insert(6);
    h1.insert(2);
    h1.insert(5);
    h1.insert(9);
    h1.insert(10);
    h1.insert(2);
    cout << "------- Max Heap -------" << endl;
    h1.printArray();
    cout << "Inserting 99.." << endl;
    h1.insert(99);
    h1.printArray();
    cout << "Delete Max" << endl;
    h1.deleteMax();
    h1.printArray();

    MinHeap h2(10);
    h2.insert(7);
    h2.insert(1);
    h2.insert(6);
    h2.insert(2);
    h2.insert(5);
    h2.insert(9);
    h2.insert(10);
    h2.insert(2);
    cout << "\n------- Min Heap -------" << endl;
    h2.printArray();
    cout << "Inserting 99.." << endl;
    h2.insert(99);
    h2.printArray();
    cout << "Delete Min" << endl;
    h2.deleteMin();
    h2.printArray();

    return 0;
}