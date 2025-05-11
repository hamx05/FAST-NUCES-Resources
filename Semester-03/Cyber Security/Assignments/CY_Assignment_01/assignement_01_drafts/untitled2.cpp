#include <iostream>
#include <vector>
using namespace std;

/* my logic: check for small and capital letters simultanouesly, if currentChar is found in the alphabets array,
then use the decryption formula. if currentChar is still not found, then it must be a special character or numeric digit so ignore it. */

int main() {
    string cypherText;
    vector<string> convertedTexts(26);
    cout << "Enter the cipher text: ";
    getline(cin, cypherText);
    
    char smallLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char capitalLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int key=0; key<26; key++) {
        for (int i=0; i<cypherText.length(); i++) {
            char currentChar = cypherText[i];
            bool found = false;

            for (int p=0; p<26; p++) { // check for alphabets
                if (currentChar == smallLetters[p]) {
                    convertedTexts[key].push_back(smallLetters[(p - key + 26) % 26]);
                    found = true;
                    break;
                }

                else if (currentChar == capitalLetters[p]) {
                    convertedTexts[key].push_back(capitalLetters[(p - key + 26) % 26]);
                    found = true;
                    break;
                }
            }
            
            if (!found) { // ignore special characters or numbers
                convertedTexts[key].push_back(currentChar);
            }
        }
    }

    for (int key=0; key<26; key++) {
        cout<<"Key " << key << ": ";
        for (int j=0; j<cypherText.size(); j++) {
            cout<<convertedTexts[key][j];
        }
        cout<<endl;
    }

    return 0;
}
