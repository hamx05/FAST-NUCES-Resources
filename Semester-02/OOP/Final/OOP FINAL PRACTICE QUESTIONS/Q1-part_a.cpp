#include <iostream>
using namespace std;


class Point {
private:
    int x, y;

public:
    
    // Point(int i, int j);
    // Point(const Point &t);
    void printX();
    void printXY () {
        cout<<"X: " << x << endl;
        cout<<"Y: " << y << endl;
    }
    
    Point() {
        Point (1,1);
    }

    Point(int i, int j) {
        x = i;
        y = j;
        cout << x << " " << y << "Normal Constructor called\n ";
    }
    Point(const Point &t) {
        y = t.y;
        cout << y << " " << "Copy Constructor called\n ";
    }
};

void Point::printX() {
    cout<<"X: " << x << endl;
}



int main() {

    Point *t1, *t2;
    t1 = new Point(10, 15);
    t2 = new Point(*t1);
    Point t3 = *t1;
    Point t4;
    cout<<"Value of t4 with default parameters: " << endl;
    t4.printXY();

    cout<<"Value of t4 after deep copy: " << endl;
    t4 = t3;
    t4.printXY();
    
    cout<<"Here\n";
    t1->printX();

    return 0;
}
