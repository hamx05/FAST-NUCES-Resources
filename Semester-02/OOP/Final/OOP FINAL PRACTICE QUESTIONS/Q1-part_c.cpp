#include <iostream>
using namespace std;

class Base {
public:
    static int count;
    Base() { 
        count++;
        cout<<"Base class constructor called" << endl;
    }

    ~Base() {
        count--; 
    }

    static void printCount()
    {
        std::cout << "Count: " << count << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() { 
        count++; 
        cout<<"Child class constructor called" << endl;
    }

    ~Derived() {
        count--;
    }
};
int Base::count = 0;

int main() {

    Base::printCount();
    {
        Base obj1;
        Derived obj2;
        Base::printCount();
    }

    Base::printCount();

    return 0;
}
