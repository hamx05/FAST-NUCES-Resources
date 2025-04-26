#include <iostream>
using namespace std;
int func(int n) {
    if (n == 0) {
        cout << "The value is zero "<<endl;
        return 10;
    }
    if (n > 0) {
        cout << "The value is greater than zero "<<endl;
        throw 'e';
    }
    if (n < 0) {
        cout << "The value is less than zero "<<endl;
        throw 9.9f;
    }
}

int main() {
    try {
        func(0);
        func(10);
        func(-10);
    }
    catch (int x) {
        cout << "Catching Integer\n";
        func(10);
    }
    catch (float f) {
        cout << "Catching Float\n";
        func(10);
    }
    catch (char c) {
        cout << "Catching Character\n";
        func(10);
    }
}
