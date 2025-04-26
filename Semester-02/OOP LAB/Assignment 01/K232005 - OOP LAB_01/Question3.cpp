#include <iostream>
using namespace std;

int main () {

    int size = 4; 
    int data[size] = {2,7,11,15};
    int target;

    cout<<"enter the target: ";
    cin>>target;

    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (data[i] + data[j] == target) {
                cout<<i<<", "<<j<<endl;
            }
        }
    }
    
    return 0;
}