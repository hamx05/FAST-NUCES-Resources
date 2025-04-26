#include <iostream>
using namespace std;

int main() {
    int n, count= 0;
    
    cout<<"Enter any number n: ";
    cin>>n;
    
    for (int i=2; i<=n; i++) {
        if (n % i == 0) {
           count++;
        }
    }

    if (count == 1) {
       cout<<n<<" is a prime number"<< endl;
    } else {
         cout<<n<<" is not a prime number"<< endl; 
    }

    return 0;    
}