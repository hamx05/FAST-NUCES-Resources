#include <iostream>
using namespace std;

class Parent {
    private:
        int x;
    public:
        virtual void printX() {
            cout<<"X (from Parent): " << endl;
        }
};

class Child : public Parent {
    public:
        void printX() {
            cout<<"X (from Child): " << endl;
            Parent::printX();
        }
};

int main() {

    Parent p;
    Child c;

    c.printX();    

    return 0;
}