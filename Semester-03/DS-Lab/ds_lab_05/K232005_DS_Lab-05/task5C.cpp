#include <iostream>
using namespace std;

int fibB(int);

int fibA(int n) {
    if (n == 0 || n == 1) return n;
    return fibB(n-1);
}

// fibB logic explanation taken from gpt
int fibB(int n) {
    if (n == 0 || n == 1) return n;
    return fibA(n-2) + fibB(n-1);
}

int main() {

    int n;
    cout<<"Enter the number of terms you wanna print: ";
    cin>> n;

    for (int i=0; i<n; i++) {
        cout<< fibA(i) << " ";
        
    }

    return 0;
}
