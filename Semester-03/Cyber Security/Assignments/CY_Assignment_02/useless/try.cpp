#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

// Function to convert text to binary and ensure it's 64 bits (8 characters)
pair<bool, vector<string>> convertTextToBinary(const string& text) {
    vector<string> binaryText;
    for (size_t i = 0; i < text.size(); ++i) {
        bitset<8> binary(text[i]);
        binaryText.push_back(binary.to_string());
    }

    // Check if the text represents exactly 64 bits (8 characters)
    if (binaryText.size() != 8) {
        cout << "The text is not 64 bits (must be 8 characters). Try again." << endl;
        return make_pair(false, vector<string>());
    }

    return make_pair(true, binaryText);
}

int main() {
    string text;
    cout << "Enter the text: ";
    getline(cin, text);

    // Get the pair containing the success flag and binary vector
    pair<bool, vector<string>> result = convertTextToBinary(text);

    // Check if the conversion was successful
    if (!result.first) {
        // If conversion failed (text wasn't 64 bits), exit the program
        return 1;
    }

    // If successful, print the binary values stored in the vector
    cout << "\nBinary values stored in vector:" << endl;
    for (const string &binary : result.second) {
        cout << binary << " ";
    }
    cout << endl;

    return 0;
}
