#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <algorithm>
#include "sha1.hpp"
#include "DES.hpp"
using namespace std;

#define numEncryptions 3 // generalising the code for any number of encrypted codes, in our case it's 3 so..

string generateOriginalVirusHash () {

    // fetch the virus from file and store it in a variable
    ifstream inputfromFile;
    inputfromFile.open("virus.txt");

    if (!inputfromFile) {
        cout << "error opening the input file!" << endl;
        return "";
    }

    string data;
    string message = "";

    while (!inputfromFile.eof()) {
        getline(inputfromFile, data);
        message += data;
    }

    // obtain the hash of virus
    SHA1 sha1;
    sha1.update(message);
    string hash = sha1.final();
    
    // store hash of original virus in a file.
    ofstream output;
    output.open("hash_of_original_virus.txt");

    if (!output) {
        cout << "error opening the output file!" << endl;
        return "";
    }

    output << hash;
    output.close();
    cout << "\nHash of original virus has been stored in 'hash_of_original_virus.txt'" << endl;
    return hash;
}

string inputKey(int round) {
    cout << "Enter key for encryption #" << round << ": ";
    string key;
    cin >> key;

    if (key.size() != 8) {
        cout << "The key must be 8 characters or 64 bits. Please enter again." << endl;
        inputKey(round);
    }

    return key;
}

string convertTextToBinary(const string &text) {
    string binaryText;
    for (char c : text) {
        bitset<8> binary(c);
        binaryText += binary.to_string();
    }
    return binaryText;
}

string generateHashOfEncryptedVirus (int round, string key) {

    // fetch the virus from file and store it in a variable
    ifstream inputfromFile;
    inputfromFile.open("virus.txt");

    if (!inputfromFile) {
        cout << "error opening the input file!" << endl;
        return "";
    }

    string data;
    string message = "";

    while (!inputfromFile.eof()) {
        getline(inputfromFile, data);
        message += data;
    }

    // convert the virus into binary
    string binaryMessage = convertTextToBinary(message);
    DES des;
    SHA1 sha1;
    string encryptedMessage;

    // encrypt the message in 64 bits blocks
    for (size_t i = 0; i < binaryMessage.length(); i += 64) {
        string block = binaryMessage.substr(i, i+64);
        
        // fixed by gpt: pad the block with zeros if it’s less than 64 bits
        while (block.length() < 64) {
            block += '0'; // extend the block bits with 0 if less than 64
        }

        bitset<64> inputBinaryMessage(block);
        bitset<64> binaryKey(convertTextToBinary(key));
        
        // encrypt the block
        bitset<64> ciphertext = des.encrypt(inputBinaryMessage, binaryKey);
        encryptedMessage += ciphertext.to_string(); // Append encrypted block
    }

    // store encrypted code
    string filename = "encrypted_virus" + to_string(round) + ".txt"; 
    ofstream output(filename);
    if (!output) {
        cout << "Error opening the encrypted virus output file!" << endl;
        return "";
    }
    output << encryptedMessage;
    output.close();
    cout << "Encrypted Virus #" << round << " has been stored in " << filename <<"." << endl;
    
    // obtain hash of encrypted virus
    sha1.update(encryptedMessage);
    string hash = sha1.final();

    // finally, store hash of encrypted virus in a file
    filename = "hash_of_encrypted_virus" + to_string(round) + ".txt"; 
    output.open(filename);
    if (!output) {
        cout << "Error opening the encrypted virus' hash output file!" << endl;
        return "";
    }
    output << hash;
    output.close();
    cout << "Hash of Encrypted Virus #" << round << " has been stored in " << filename <<"." << endl;
    return hash;
}

void compareHashes (string hashes[]) {
    cout << "\nHash of Original Virus: " << hashes[0] << endl;

    for (int i=1; i<=numEncryptions; i++) {
        cout << "Hash of Encrypted Virus #" << i << ": " << hashes[i] << endl;
    }

    bool collision = false;
    for (int i=0; i<numEncryptions; i++) {
        for (int j=0; j<numEncryptions; j++) {
            if (hashes[j] != hashes[j+1]) {
                collision = false;
            }
            else {
                collision = true;
                break;
            }
        }
    }

    cout << "\nRESULT: ";
    if (!collision) cout << "All the hashes are distinct." << endl;
    else cout << "The hashes have collision." << endl;
}

int get_int() {
    int n;
    for (;;) {
        if (cin >> n) {
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry. Please re-enter: ";
    }
}

void propogateVirus () {
    string hashes[numEncryptions + 1];
    
    hashes[0] = generateOriginalVirusHash();


    for (int i=0; i<numEncryptions; i++) {
        cout << endl;
        string key = inputKey(i+1);
        string hash = generateHashOfEncryptedVirus(i+1, key);
        if (hash != "") hashes[i+1] = hash;
        else generateHashOfEncryptedVirus(i+1, key);
    }
    compareHashes(hashes);
}

int main () {

    int choice;
    bool again = true;

    while (again) {
        cout << "\n------------------ Muhammad Hammad || 23K-2005 -------------------";
        cout << "\n------------------ Virus Propagation Software --------------------\n";
        cout << "1. Propogate Virus\n";
        cout << "2. Exit\n";
        cout << "Choose an option: ";
        choice = get_int();;

        switch (choice) {
            case 1: {
                propogateVirus();
                break;
            }
            case 2: {
                again = false;
                cout << "Exiting program. Ba-bye!\n";
                break;
            }
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}