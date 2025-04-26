#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    // Concatenation
    // string str1 = "Hello";
    // string str2 = "World";
    // string concatenated = str1 + str2;
    // cout<<concatenated;

    // Converting a character into upper or lower case
    // char ch1 = toupper('a');
    // cout<< "To upper: " << ch1 << endl;
    // char ch2 = tolower('A');
    // cout<< "To upper: " << ch2 << endl;

    string myString = "Hello, World!";
    size_t pos = myString.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    } else {
        cout << "'World' not found" << endl;
    }
    
    return 0;
}