#include <iostream>
using namespace std;

int fact (int n) {
    if (n < 2) {
        return 1;
    }

    return n * fact(n-1);
}

int main () {

    int n;
    cout<<"Enter a number: ";
    cin >> n;

    cout<<"Factorial: " << fact(n);

    return 0;
}