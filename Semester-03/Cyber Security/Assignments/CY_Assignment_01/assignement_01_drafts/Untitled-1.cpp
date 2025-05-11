#include <iostream>
#include <vector>
using namespace std;

/* The program takes a Caesar Cipher ciphertext as input and returns the correct plaintext and key. */

int main() {
    string cypherText;
    vector<vector<char>> convertedTexts(26, vector<char>(0)); // Initialize the 2D vector

    cout << "Enter the cipher text: ";
    getline(cin, cypherText);
    
    char smallLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char capitalLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int key = 0; key < 26; key++) { // Loop for key (0 to 25)
        for (int i = 0; i < cypherText.length(); i++) {
            char currentChar = cypherText[i];
            if (isalpha(currentChar)) { // Only process letters
                if (islower(currentChar)) {
                    int originalPos = currentChar - 'a'; // Get 0-based index
                    int newPos = (originalPos - key + 26) % 26; // Calculate shifted position
                    convertedTexts[key].push_back(smallLetters[newPos]);
                } else if (isupper(currentChar)) {
                    int originalPos = currentChar - 'A';
                    int newPos = (originalPos - key + 26) % 26;
                    convertedTexts[key].push_back(capitalLetters[newPos]);
                }
            } else { // For non-alphabetic characters, keep them unchanged
                convertedTexts[key].push_back(currentChar);
            }
        }
    }

    for (int key = 0; key < 26; key++) {
        cout << "\tCombination " << key + 1 << ": ";
        for (char c : convertedTexts[key]) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
