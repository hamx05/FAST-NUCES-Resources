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

// step 01
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
vector<string> parityDrop(string binaryText) {
    int parityTable[7][8]= {{57, 49, 41, 33, 25, 17, 9, 1},
                            {58, 50, 42, 34, 26, 18, 10, 2},
                            {59, 51, 43, 35, 27, 19, 11, 3},
                            {60, 52, 44, 36, 63, 55, 47, 39},
                            {31, 23, 15, 7, 62, 54, 46, 38},
                            {30, 22, 14, 6, 61, 53, 45, 37},
                            {29, 21, 13, 5, 28, 20, 12, 4}};

    vector<string> binaryTextAfterParityDrop(56); // 56 bits

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
pair<vector<string>, vector<string>> break56BitsBinaryTextIntoTwo(vector<string> FiftySixBitsBinaryText) {
    vector<string> Left28Bits(FiftySixBitsBinaryText.begin(), FiftySixBitsBinaryText.begin() + 28);
    vector<string> Right28Bits(FiftySixBitsBinaryText.begin() + 28, FiftySixBitsBinaryText.end());
    return make_pair(Left28Bits, Right28Bits);
}

// step 04
vector<string> shiftLeft(vector<string> binaryBitsBlock, int numOfShifts) {
    int size = binaryBitsBlock.size();
    numOfShifts = numOfShifts % size;

    vector<string> shifted(size);
    for (int i=0; i<size; i++) {
        shifted[i] = binaryBitsBlock[(i + numOfShifts) % size]; // logic taken from gpt
    }
    return shifted;
}

// step 05
string compressionBox(vector<string> Left28Bits, vector<string> Right28Bits) {
    int compressionTable[6][8] = {
        {14, 17, 11, 24, 1, 5, 3, 28},
        {15, 6, 21, 10, 23, 19, 12, 4},
        {26, 8, 16, 7, 27, 20, 13, 2},
        {41, 52, 31, 37, 47, 55, 30, 40},
        {51, 45, 33, 48, 44, 49, 39, 56},
        {34, 53, 46, 42, 50, 36, 29, 32}};

    vector<string> combinedBinaryBits(56);
    for (int i=0; i<28; i++) {
        combinedBinaryBits[i] = Left28Bits[i];
    }
    for (int i=0; i<28; i++) {
        combinedBinaryBits[28 + i] = Right28Bits[i];
    }

    string binaryTextAfterCompression; // 48 bits
    for (int i=0; i<6; i++) {
        for (int j=0; j<8; j++) {
            int targetIndex = compressionTable[i][j];
            binaryTextAfterCompression += combinedBinaryBits[targetIndex - 1];
        }
    }
    return binaryTextAfterCompression;
}

// key generation
vector<string> keyGeneration(string binaryText) {
    // Step 02
    vector<string> FiftySixBitsKey = parityDrop(binaryText);
    
    // Step 03
    pair<vector<string>, vector<string>> result56Bits = break56BitsBinaryTextIntoTwo(FiftySixBitsKey);
    vector<string> Left28Bits = result56Bits.first;
    vector<string> Right28Bits = result56Bits.second;

    int roundShifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    vector<string> keys;
    for (int round=0; round<16; round++) {
        // Step 04
        Left28Bits = shiftLeft(Left28Bits, roundShifts[round]);
        Right28Bits = shiftLeft(Right28Bits, roundShifts[round]);

        // Step 05
        keys.push_back(compressionBox(Left28Bits, Right28Bits));
    }
    return keys;
}

int main() {
    
    string text = takeInput();
    pair<bool, string> result = convertTextToBinary(text);

    // If text is not 64 bits, return
    if (!result.first) {
        cout << "The text is not 64 bits. Please enter 8 characters.";
        return 1;
    }

    string binaryText = result.second;

    vector<string> keys = keyGeneration(binaryText);

    for (int i=0; i<keys.size(); i++) {
        cout<<"Key " << i + 1 << ": " << keys[i] << endl;
    }

    return 0;
}

/* Steps:
✔ 64 bits input
✔ parity drop to 56 bits
✔ divide the bits into right 28 bits and left 28 bits.
✔ shift left, both the right and left side : (in round 1, 2, 9, 16: do 1 bit shifting, in other rounds do 2 bits shifting)
✔ then the shifted right and left side enter compression box
✔ output of compression box is your round key */
