#include <iostream>
#include <ctime>
using namespace std;

#define MAX 7

class Queue {
    public:
        int arr[MAX];
        int front;
        int rear;
        int size;

        Queue () : front(0), rear(-1), size(0) {}

        bool isFull() {
            return (size == MAX);
        }
        
        bool isEmpty() {
            return (size == 0);
        }

        void enqueue (int x) {
            if (isFull()) {
                cout<<"The checkout queue has maximum number of customers waiting. Customer ID " << x << " cannot be added." << endl;
                return;
            }
            else {
                rear = (rear + 1) % MAX;
                size++;
                arr[rear] = x;
                cout<< "Enqueued Customer ID: " << arr[rear] << endl;
            }
        }

        void dequeue () {
            if (isEmpty()) {
                cout<<"The checkout queue is already empty, no customers needed to check out." << endl;
                return;
            }
            else {
                cout<< "Dequeued Customer ID: " << arr[front] << endl;
                arr[front] = 0;
                size--;
                front = (front + 1) % MAX;
            }
        }

        void print() {
            cout<<"No. of customers in the checkout queue = " << size << endl;
             if (isEmpty()) {
                return;
            }
            for (int i=0; i<size; i++) {
                cout<<arr[(front + i) % MAX] << " ";
            }
            cout<<endl;
        }

        void checkout () {
            int bill = rand() % 10001;

            cout<<"Customer ID " << arr[front] << " has paid their bill of Rs " << bill << " and left the queue." << endl;
            dequeue();
        }


};

int main () {

    srand(time(0));
    int arr[MAX] = {13, 7, 4, 1, 6, 8, 10};

    Queue q;
    cout<<"------------------------------" << endl;
    cout<<"Adding customers to the queue:" << endl;
    cout<<"------------------------------" << endl;
    for (int i=0; i<MAX; i++) {
        q.enqueue(arr[i]);
    }

    cout<<"\n-------------------------------" << endl;
    cout<<"Checking out first 3 customers:" << endl;
    cout<<"-------------------------------" << endl;
    for (int i=0; i<3; i++) {
        q.checkout();
        cout<<endl;
        
    }

    cout<<"\n------------------------------------" << endl;
    cout<<"Adding more customers to the queue:" << endl;
    cout<<"------------------------------------" << endl;
    q.enqueue(21);
    q.enqueue(22);
    q.enqueue(23);
    q.enqueue(24);
    q.enqueue(25);
    q.print();

    cout<<"\n-------------------------------------" << endl;
    cout<<"Checking out the remaining customers:" << endl;
    cout<<"-------------------------------------" << endl;
    int csize = q.size;
    for (int i=0; i<csize; i++) {
        q.checkout();
        cout<<endl;
    }

    cout<<"\n-----------------------------" << endl;
    cout<<"Status of the checkout queue:" << endl;
    cout<<"-----------------------------" << endl;
    q.print();

    return 0;
}