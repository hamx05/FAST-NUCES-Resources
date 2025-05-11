#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Task {
public:
    string name;
    int priority;

    Task(string name, int priority) : name(name), priority(priority) {}

    bool operator>(const Task &other) const {
        // For MaxHeap, higher priority (larger value) should be placed before
        return priority > other.priority;
    }

    bool operator<(const Task &other) const {
        // For MinHeap, lower priority (smaller value) should be placed before
        return priority < other.priority;
    }

    void printTask() const {
        cout << name << " (Priority: " << priority << ")";
    }
};

class MaxHeap {
public:
    int capacity;
    int size;
    Task **arr;

    MaxHeap(int c) : size(0), capacity(c) {
        arr = new Task*[capacity];
    }

    ~MaxHeap() {
        delete[] arr;
    }

    void heapify(int i) {
        int largest = i;
        int leftChild = (2 * i) + 1;
        int rightChild = (2 * i) + 2;

        if (leftChild < size && *arr[leftChild] > *arr[largest]) {
            largest = leftChild;
        }

        if (rightChild < size && *arr[rightChild] > *arr[largest]) {
            largest = rightChild;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(largest);
        }
    }

    void insert(Task *task) {
        if (size == capacity) {
            cout << "Heap is full." << endl;
            return;
        }

        int i = size;
        arr[i] = task;
        size++;

        while (i != 0 && *arr[(i - 1) / 2] < *arr[i]) {
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }
    }

    Task* extractMax() {
        if (size == 0) {
            cout << "Heap is empty. Cannot extract maximum task." << endl;
            return nullptr;
        }

        Task* max = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapify(0);
        return max;
    }

    void deleteMax() {
        Task* task = extractMax();
        if (task) {
            delete task;
        }
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            arr[i]->printTask();
            cout << endl;
        }
    }
};

int main() {
    srand(time(0));

    MaxHeap taskHeap(10);
    
    // Insert some tasks with random priorities
    taskHeap.insert(new Task("Task 1", rand() % 10 + 1));
    taskHeap.insert(new Task("Task 2", rand() % 10 + 1));
    taskHeap.insert(new Task("Task 3", rand() % 10 + 1));
    taskHeap.insert(new Task("Task 4", rand() % 10 + 1));
    taskHeap.insert(new Task("Task 5", rand() % 10 + 1));
    
    cout << "------ Scheduled Tasks (Max Priority First) ------" << endl;
    taskHeap.printArray();
    
    // Process tasks in order of priority
    cout << "\nScheduling tasks..." << endl;
    while (true) {
        Task* task = taskHeap.extractMax();
        if (!task) break;
        cout << "Scheduled: ";
        task->printTask();
        cout << endl;
        delete task;  // Free memory after task is scheduled
    }

    return 0;
}
