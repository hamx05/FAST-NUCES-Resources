#include <iostream>
using namespace std;

void B(int, int);

void A (int n, int limit) {
    if (n > limit) return;

    if (n%2 == 0) {
        cout<< n << " ";
        B(n+1, limit);
    } else {
        B(n, limit);
    }
}

void B (int n, int limit) {
    if (n > limit) return;
   
    if (n%2 != 0) {
        cout<< n << " ";
        A(n+1, limit);
    } else {
        A(n, limit);
    }
}

int main () {

    A(1, 30);

    return 0;
}