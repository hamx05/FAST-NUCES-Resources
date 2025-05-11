#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

string convertToLowerCase(const string& str) {
    string lowerCaseString;
    for (char c : str) {
        lowerCaseString += tolower(c);
    }
    return lowerCaseString;
}

vector<string> setDictionary(const string& filename) {
    vector<string> dictionary;
    ifstream dictionaryFile(filename);
    if (!dictionaryFile) {
        cerr << "Error opening the dictionary file!" << endl;
        return dictionary;
    }
    string word;
    while (dictionaryFile >> word) {
        dictionary.push_back(convertToLowerCase(word)); // converting words into lower case because dictionary has words in lowercase.
    }
    return dictionary;
}

int countMatchedWords(const string& text, const vector<string>& dictionary) {
    int count = 0;
    stringstream ss(text);
    string word;
    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end()); // this line is taken from gpt >_>
        if (find(dictionary.begin(), dictionary.end(), convertToLowerCase(word)) != dictionary.end()) {
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

    for (int key = 0; key < 26; key++) {
        int matchedWords = countMatchedWords(convertedTexts[key], dictionary);
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
