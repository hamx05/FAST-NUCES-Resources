#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector <string> splitStrings (string str) {
    vector <string> words;
    string word;
    istringstream iss(str);

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}


int main() {
       

    return 0;
}