#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

float getFloat () {
    float n;
    for (;;) {
        if (cin>>n) {
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Invalid entry. Please re-enter: ";
    }
}

float takeInput() {
    float number;
    cout<<"Enter a number: ";
    number=getFloat();
    return number;
}

float check_SqRoot(float number) {
    if (number < 0) {
        throw "Cannot calculate square root of a negative number!";
    }
    return sqrt(number);
}

int main() {
    float number = takeInput();
      
    try {
        float result = check_SqRoot(number);
        cout<<"Square root: " << result << endl;
    }
    catch (const char* error) {
        cout<<"Error: " << error << endl;
    }

    return 0;
}
