#include <iostream>
using namespace std;

int fib (int n) {
    if (n==0 || n==1) return n;
    return fib(n-2) + fib(n-1);
}

int main() {
    
    int n;
    cout<<"Enter nth term of fibonacci series you want to print: ";
    cin>>n;

    cout<<"Nth fibonacci term is: " << fib(n);

    return 0;
}