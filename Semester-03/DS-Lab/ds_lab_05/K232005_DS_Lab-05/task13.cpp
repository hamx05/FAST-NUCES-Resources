#include <iostream>
using namespace std;

int func (int n) {
    if (n == 0) return 1;
    if (n <= 1) return 1;
    return func(func(n-1));
}

int main () {

    cout<< "f(0) = " << func(0);
    cout<< "\nf(5) = " << func(5);
    cout<< "\nf(10) = " << func(10);

    return 0;
}