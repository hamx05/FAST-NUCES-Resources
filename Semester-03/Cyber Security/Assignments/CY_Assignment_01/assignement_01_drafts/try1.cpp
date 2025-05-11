 #include <iostream>
 #include <vector>
using namespace std;

/* You need to write a computer program in any programming language of your choice, which takes a ciphertext of Caesar Cipher as
input (both with and without spaces) and return ONLY the correct plain text and the correct key. Remember that key is unknown 
to you because you are considered as an attacker who has knowledge of ciphertext and is trying to find the key and plaintext. */


int main () {

    string cypherText;
    vector<vector<string>> convertedTexts; // [26][5]

    cout<<"Enter the cypher text: ";
    getline(cin, cypherText);
    
    char smallLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char capitalLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int k=0;
    for (int i=0; i<cypherText.length(); i++) { // 0-5
        for (int key=0; key<26; key++) { // loop for key, stores 26 combinations of plain text
            for (int k=0; k<26; k++) { // letters array Index number
                if (cypherText[i] == smallLetters[k]) {
                    convertedTexts[key][i] = smallLetters[(k-key)%26];
                }
                else if (cypherText[i] == capitalLetters[k]) {
                    convertedTexts[key][i] = capitalLetters[(k-key)%26];
                }
                else { // ignores anything other than alphabets
                    convertedTexts[key][i] = cypherText[i];
                }
            }
        }
    }

    for (int i=0; i<26; i++) {
        cout<<"/tCombination " << i+1 << ":" << endl;
        for (int j=0; j<cypherText.length(); j++) {
            cout<<convertedTexts[i][j]<<endl;
        }
    }

    return 0;
}