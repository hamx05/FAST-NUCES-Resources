#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Function to split a string into words
vector<string> splitString(const string& str) {
    vector<string> words;
    istringstream iss(str);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

// Function to compare all words in a string with a specified word
void compareWords(vector <string> str, vector <string> wordToCompare) {
    

    for (int i=0; i<words.size(); i++) {
        vector<string> words = splitString(str[i]);
        if (words[i] == wordToCompare) {
            cout << "Word matched: " << words[i];
        }
    }
}

int main() {
    vector <string> inputString = {"breakthrough drug schizophrenia drug released July",
                            "new schizophrenia drug breakthrough drug",
                            "new approach treatment schizophrenia",
                            "new hopes schizophrenia patients schizophrenia cure"};
    vector <string> wordToCompare = {"breakthrough", " drug", "schizophrenia,", "released", "july", "new", "approach", " treatment", "hopes", "patients", "cure"};
    
    compareWords(inputString, wordToCompare);
    
    return 0;
}
