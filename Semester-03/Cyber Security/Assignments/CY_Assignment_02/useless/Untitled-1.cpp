#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

string takeInput() {
    string text;
    cout<<"Enter the key: ";
    getline(cin, text);
    return text;
}

// step 01: Convert text to binary
pair<bool, string> convertTextToBinary(const string &text) {
    if (text.size() != 8) {
        return make_pair(false, "");
    }
    
    string binaryText;
    for (size_t i=0; i<text.size(); i++) {
        bitset<8> binary(text[i]);
        binaryText += binary.to_string();
    }

    return make_pair(true, binaryText);
}

// step 02
string parityDrop(const string &binaryText) {
    int parityTable[7][8] = {{57, 49, 41, 33, 25, 17, 9, 1},
                             {58, 50, 42, 34, 26, 18, 10, 2},
                             {59, 51, 43, 35, 27, 19, 11, 3},
                             {60, 52, 44, 36, 63, 55, 47, 39},
                             {31, 23, 15, 7, 62, 54, 46, 38},
                             {30, 22, 14, 6, 61, 53, 45, 37},
                             {29, 21, 13, 5, 28, 20, 12, 4}};

    string binaryTextAfterParityDrop(56, '0'); // 56 bits

    int currIndex = 0;
    for (int i=0; i<7; i++) {
        for (int j=0; j<8; j++) {
            int targetIndex = parityTable[i][j];
            binaryTextAfterParityDrop[currIndex] = binaryText[targetIndex - 1];
            currIndex++;
        }
    }
    return binaryTextAfterParityDrop;
}

// step 03
pair<string, string> break56BitsBinaryTextIntoTwo(const string &FiftySixBitsBinaryText) {
    string Left28Bits = FiftySixBitsBinaryText.substr(0, 28);
    string Right28Bits = FiftySixBitsBinaryText.substr(28, 28);
    return make_pair(Left28Bits, Right28Bits);
}

// step 04: Shift left
string shiftLeft(const string &binaryBitsBlock, int numOfShifts) {
    string shiftedBlock = binaryBitsBlock;
    for (int i=0; i<numOfShifts; i++) {
        shiftedBlock = shiftedBlock.substr(1) + shiftedBlock[0]; // Rotate the string by moving the first bit to the end
    }
    return shiftedBlock;
}

// step 05
string compressionBox(const string &Left28Bits, const string &Right28Bits) {
    int compressionTable[6][8] = {{14, 17, 11, 24, 1, 5, 3, 28},
                                  {15, 6, 21, 10, 23, 19, 12, 4},
                                  {26, 8, 16, 7, 27, 20, 13, 2},
                                  {41, 52, 31, 37, 47, 55, 30, 40},
                                  {51, 45, 33, 48, 44, 49, 39, 56},
                                  {34, 53, 46, 42, 50, 36, 29, 32}};

    string combinedBinaryBits = Left28Bits + Right28Bits;
    string binaryTextAfterCompression(48, '0'); // 48 bits

    int currIndex = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            int targetIndex = compressionTable[i][j];
            binaryTextAfterCompression[currIndex] = combinedBinaryBits[targetIndex - 1];
            currIndex++;
        }
    }
    return binaryTextAfterCompression;
}

// generating key
vector<string> keyGeneration(const string &binaryText) {
    string FiftySixBitsKey = parityDrop(binaryText); // Step 02

    pair<string, string> result56Bits = break56BitsBinaryTextIntoTwo(FiftySixBitsKey); // Step 03
    string Left28Bits = result56Bits.first;
    string Right28Bits = result56Bits.second;

    int roundShifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    vector<string> keys(16);

    for (int round = 0; round < 16; round++) {
        Left28Bits = shiftLeft(Left28Bits, roundShifts[round]);  // Step 04
        Right28Bits = shiftLeft(Right28Bits, roundShifts[round]);
        keys[round] = compressionBox(Left28Bits, Right28Bits); // Step 05
    }

    return keys;
}

int main() {

    string text = takeInput();
    pair<bool, string> output = convertTextToBinary(text);

    if (!output.first) {
        cout<<"The text is not 64 bits. Please enter 8 characters only." << endl;
        return 1;
    }
    string binaryText = output.second;

    vector<string> keys = keyGeneration(binaryText);
    for (int i=0; i<keys.size(); i++) {
        cout<<"Key " << i+1 << ": " << keys[i] << endl;
    }

    return 0;
}
