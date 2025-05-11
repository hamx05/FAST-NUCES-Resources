#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

// Convert the input string to lowercase
string convertToLowerCase(const string& str) {
    string lowerCaseString;
    for (char c : str) {
        lowerCaseString += tolower(c);
    }
    return lowerCaseString;
}

// Load the dictionary from a file and store it in a vector
vector<string> setDictionary(const string& filename) {
    vector<string> dictionary;
    ifstream dictionaryFile(filename);
    if (!dictionaryFile) {
        cerr << "Error opening the dictionary file!" << endl;
        return dictionary;
    }
    string word;
    while (dictionaryFile >> word) {
        dictionary.push_back(convertToLowerCase(word)); // Convert words into lowercase for consistency
    }
    return dictionary;
}

// Check if a word exists in the dictionary
bool isWordInDictionary(const string& word, const vector<string>& dictionary) {
    return find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

// Attempt to tokenize the decrypted text to form valid words using stringstream
vector<string> tokenizeText(const string& text, const vector<string>& dictionary) {
    vector<string> tokens;
    string currentToken;
    stringstream ss(text);

    // Extract characters one by one and form tokens
    char ch;
    while (ss >> noskipws >> ch) { // Read each character, including whitespace
        currentToken += ch; // Add current character to the token
        
        // Check if the current token is a valid word
        if (isWordInDictionary(currentToken, dictionary)) {
            tokens.push_back(currentToken); // Add valid word to tokens
            currentToken.clear(); // Start a new token
        }
    }

    // Add any remaining part of the text as a token
    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }
    return tokens;
}

// Count the number of matched words from the dictionary in the tokenized text
int countMatchedWords(const vector<string>& tokens, const vector<string>& dictionary) {
    int count = 0;
    for (const string& token : tokens) {
        if (isWordInDictionary(token, dictionary)) {
            count++;
        }
    }
    return count;
}

int main() {
    string cypherText;
    vector<string> convertedTexts(26);
    cout << "Enter the cipher text: ";
    getline(cin, cypherText);

    // Convert the ciphertext to lowercase and remove non-alphabetic characters
    cypherText = convertToLowerCase(cypherText);
    cypherText.erase(remove_if(cypherText.begin(), cypherText.end(), [](char c) { return !isalpha(c); }), cypherText.end());

    char smallLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char capitalLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // Decrypt the ciphertext for all possible keys
    for (int key = 0; key < 26; key++) {
        for (int i = 0; i < cypherText.length(); i++) {
            char currentChar = cypherText[i];
            bool found = false;

            for (int p = 0; p < 26; p++) {
                if (currentChar == smallLetters[p]) {
                    convertedTexts[key] += smallLetters[(p - key + 26) % 26];
                    found = true;
                    break;
                } else if (currentChar == capitalLetters[p]) {
                    convertedTexts[key] += capitalLetters[(p - key + 26) % 26];
                    found = true;
                    break;
                }
            }

            if (!found) {
                convertedTexts[key] += currentChar;
            }
        }
    }

    vector<string> dictionary = setDictionary("dictionary.txt");

    int maxMatchedWords = 0;
    int bestKey = -1;

    // Evaluate all possible decryptions by tokenizing and counting matched words
    for (int key = 0; key < 26; key++) {
        vector<string> tokens = tokenizeText(convertedTexts[key], dictionary); // Tokenize the decrypted text using stringstream
        int matchedWords = countMatchedWords(tokens, dictionary); // Count matched words from the dictionary

        if (matchedWords > maxMatchedWords) {
            maxMatchedWords = matchedWords;
            bestKey = key;
        }
    }

    // Reconstruct the plaintext
    if (bestKey != -1) {
        cout << "The most likely correct decryption is given below, as this combination matched " << maxMatchedWords << " words from the dictionary.\n";
        cout << convertedTexts[bestKey] << endl << endl;
        cout << "<plaintext>\n" << convertedTexts[bestKey] << "\n</plaintext>\n";
        cout << "<key>\n" << bestKey << "\n</key>\n";
    } else {
        cout << "<plaintext>\nUnable to decrypt ciphertext\n</plaintext>\n";
        cout << "<key>\nUnable to determine the key\n</key>\n";
    }

    return 0;
}
