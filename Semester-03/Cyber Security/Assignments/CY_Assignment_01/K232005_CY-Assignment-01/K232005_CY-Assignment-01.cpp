#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // find()
using namespace std;

string convertToLowerCase(string str) {
    string lowerCaseString;
    for (char c : str) {
        lowerCaseString += tolower(c);
    }
    return lowerCaseString;
}

vector<string> setDictionary(const string filename) {
    vector<string> dictionary;
    ifstream dictionaryFile(filename);
    if (!dictionaryFile) {
        cout<<"Error opening the dictionary file!" << endl;
        return dictionary;
    }
    string word;
    while (dictionaryFile >> word) {
        dictionary.push_back(convertToLowerCase(word)); // converting all words into lowercase because dictionary has words stored in lowercase
    }
    return dictionary;
}

bool flagToken = true;
vector<string> getTokens(string text, vector<string> dictionary) {
    vector<string> tokens;
    int length = text.length();
    if (flagToken) {
        cout<<"Obtaining multiple tokens of decrypted text..." <<endl;
    }
    flagToken = false;

    for (int start=0; start<length; start++) {
        for (int end=start+1; end<=length; end++) {
            string substring = text.substr(start, end - start);
            if (find(dictionary.begin(), dictionary.end(), convertToLowerCase(substring)) != dictionary.end()) {
                tokens.push_back(substring);
            }
        }
    }
    return tokens;
}

bool flagMatched = true;
int countMatchedWords(string text, vector<string> dictionary) {
    vector<string> tokens = getTokens(text, dictionary);
    int count = 0;
    if (flagMatched) {
        cout<<"Matching the tokens with dictionary... This may take a while." << endl;
    }
    flagMatched = false;
    for (string token : tokens) {
        if (find(dictionary.begin(), dictionary.end(), convertToLowerCase(token)) != dictionary.end()) {
            count++;
        }
    }
    return count;
}

vector<string> decryption(string cypherText) {
    cout<<"\nDecrypting cypher text..." << endl; 
    char alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<string> convertedTexts(26);

    for (int key=0; key<26; key++) {
        for (int i=0; i<cypherText.length(); i++) {
            char currentChar = cypherText[i];
            bool found = false;

            for (int p=0; p<26; p++) {
                if (currentChar == alphabets[p]) {
                    convertedTexts[key].push_back(alphabets[(p-key+26)%26]);
                    found = true;
                    break;
                } else if (currentChar == toupper(alphabets[p])) {
                    convertedTexts[key].push_back(toupper(alphabets[(p-key+26)%26]));
                    found = true;
                    break;
                }
            }
            if (!found) {
                convertedTexts[key].push_back(currentChar); // must be a special character or numeric digit
            }
        }
    }

    return convertedTexts;
}

pair<int, int> getFinalKey (vector<string> convertedTexts, vector<string> dictionary) {
    int maxMatchedWords = 0;
    int finalKey = -1;

    for (int key=0; key<26; key++) {
        int matchedWords = countMatchedWords(convertedTexts[key], dictionary);
        if (matchedWords > maxMatchedWords) {
            maxMatchedWords = matchedWords;
            finalKey = key;
        }
    }
    return make_pair(finalKey, maxMatchedWords);
}

int main() {
    
    string cypherText;
    cout<<"Welcome to the Decryption Program!\n";
    char choice;
    
    do {
        cout<<"Enter the cipher text: ";
        getline(cin, cypherText);
        vector<string> convertedTexts = decryption(cypherText);
        vector<string> dictionary = setDictionary("dictionary.txt");
        auto result = getFinalKey(convertedTexts, dictionary);
        int finalKey = result.first;
        int maxMatchedWords = result.second;

        if (finalKey != -1) {
            cout<<"\nAfter analyzing all possible keys, the following decryption appears to be the most accurate.\n";
            cout<<"Plain Text: " << convertedTexts[finalKey] << endl;
            cout<<"Key: " << finalKey << endl;
            cout<<"Distinct combations of words matched from Dictionary: " << maxMatchedWords << endl;

        } else {
            cout<<"\nNo sensible plaintext found. None of the 26 combinations matched enough words from the dictionary to be considered valid English text.\n";
        }

        cout<<"\nDo you want to decrypt again? (y/n): ";
        cin>>choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    cout<<"Thank you for using my program! :)" << endl;

    return 0;
}
 