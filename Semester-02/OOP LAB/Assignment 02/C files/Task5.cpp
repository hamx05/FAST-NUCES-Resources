#include <iostream>
#include <string>

using namespace std;

void break_string_equally(const string& s) {
    int length = s.length();
    
    int substr_length = length / 4;
    int remainder = length % 4;

    int start = 0;
    for (int i = 0; i < 4; ++i) {
        int current_length = substr_length;
        if (i < remainder) {
            current_length++;
        }
        cout << s.substr(start, current_length) << " ";
        start += current_length;
    }
    cout << endl;
}

int main() {
    string input_string;
    cout << "Enter a string: ";
    getline(cin, input_string);

    cout << "Output: ";
    break_string_equally(input_string);

    return 0;
}
