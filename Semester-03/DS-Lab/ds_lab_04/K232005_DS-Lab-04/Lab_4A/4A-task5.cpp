#include <iostream>
using namespace std;

#define N 5

class Date {
    private:
        int day[N] = {0, 0, 0, 0, 0};
        int month[N] = {0, 0, 0, 0, 0};
        int year[N] = {0, 0, 0, 0, 0};
       
    public:
       
        Date () {}
        Date (int d, int m, int y, int index) {
            day[index] = d;
            month[index] = m;
            year[index] = y;
        }
       
        void setDay(int index) {
            cout<<"Enter day: ";
            cin >> day[index];
        }
       
        void setMonth(int index) {
            cout<<"Enter month: ";
            cin >> month[index];
        }
       
        void setYear(int index) {
            cout<<"Enter year: ";
            cin >> year[index];
        }
       
        void SelectionSort() {
            for (int i = 0; i < N - 1; i++) {
                int minIndex = i;
       
                for (int j = i + 1; j < N; j++) {
                    if (year[j] < year[minIndex]) {
                        minIndex = j;
                    }
                }
               
                if (minIndex != i) {
                    int temp[3];

                    temp[0] = day[i];
                    day[i] = day[minIndex];
                    day[minIndex] = temp[0];

                    temp[1] = month[i];
                    month[i] = month[minIndex];
                    month[minIndex] = temp[1];

                    temp[2] = year[i];
                    year[i] = year[minIndex];
                    year[minIndex] = temp[2];
                }
            }
        }
       
        void printDate () {
            for (int i=0; i<N; i++) {
                cout << day[i] << "/" << month[i] << "/" << year[i] << endl;
            }
        }
       
};

int main () {
   
    Date d1, d2, d3, d4, d5;
    
    for (int i=0; i<N; i++) {
        cout<<"Enter Details for Date " << i+1 << ": " << endl;
        d1.setDay(i);
        d1.setMonth(i);
        d1.setYear(i);
        cout<<endl;
    }

    d1.SelectionSort();
    d1.printDate();
   
}