#include <iostream>
using namespace std;

int gcdTailRecursive(int a, int b) {
    if (b == 0) return a;

    return gcdTailRecursive(b, a%b);
}

int main () {
    
    int n, m;
    cout<<"enter first number: ";
    cin >> n;
    cout<<"enter second number: ";
    cin >> m;
    
    int res = gcdTailRecursive(n, m);
    cout<<"Answer: " << res;

    return 0;
}