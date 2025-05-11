#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

string takeInput () {
    string text;
    cout << "Enter the key: ";
    getline(cin, text);
    return text; 
}

// Step 01
pair<bool, vector<string>> convertTextToBinary(const string &text) {
    vector<string> binaryText;
    for (size_t i = 0; i < text.size(); ++i) {
        bitset<8> binary(text[i]);
        binaryText.push_back(binary.to_string());
    }

    if (text.size() != 8) { // fixed here: should check text size, not binaryText size
        return make_pair(false, vector<string>());
    }

    return make_pair(true, binaryText);
}

// Step 02
vector<string> parityDrop (vector<string> binaryText) {
    int parityTable[7][8]= {{57, 49, 41, 33, 25, 17, 9, 1},
                            {58, 50, 42, 34, 26, 18, 10, 2},
                            {59, 51, 43, 35, 27, 19, 11, 3},
                            {60, 52, 44, 36, 63, 55, 47, 39},
                            {31, 23, 15, 7, 62, 54, 46, 38},
                            {30, 22, 14, 6, 61, 53, 45, 37},
                            {29, 21, 13, 5, 28, 20, 12, 4}};

    vector<string> binaryTextAfterParityDrop(56); // 56 bits
    int currIndex = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            int targetIndex = parityTable[i][j];
            int bitIndex = (targetIndex - 1) % 8; // fixed here: get bit index within the binary string
            int charIndex = (targetIndex - 1) / 8; // fixed here: get character index in binaryText
            binaryTextAfterParityDrop[currIndex] = binaryText[charIndex].substr(bitIndex, 1); // fixed here: copy the specific bit
            currIndex++;
        }
    }
    return binaryTextAfterParityDrop;
}

// Step 03
pair<vector<string>, vector<string>> break56BitsBinaryTextIntoTwo (vector<string> FiftySixBitsBinaryText) {
    vector<string> Left28Bits(FiftySixBitsBinaryText.begin(), FiftySixBitsBinaryText.begin()+28);
    vector<string> Right28Bits(FiftySixBitsBinaryText.begin()+28, FiftySixBitsBinaryText.end());

    return make_pair(Left28Bits, Right28Bits);
}

// Step 04
vector<string> shiftLeft (vector<string> binaryBitsBlock, int numOfShifts) {
    vector<string> shiftedBlock = binaryBitsBlock;
    for (int shift = 0; shift < numOfShifts; shift++) {
        char firstBit = shiftedBlock[0][0]; // fixed here: Get first bit of first string
        for (int i = 0; i < 27; i++) {
            shiftedBlock[i] = shiftedBlock[i].substr(1) + shiftedBlock[i+1][0]; // fixed here: Shift each bit
        }
        shiftedBlock[27] = shiftedBlock[27].substr(1) + firstBit; // fixed here: Complete the shift with the first bit
    }
    return shiftedBlock;
}

// Step 05
vector<string> compressionBox (vector<string> Left28Bits, vector<string> Right28Bits) {
    int compressionTable[6][8]={{14, 17, 11, 24, 1, 5, 3, 28},
                                {15, 6, 21, 10, 23, 19, 12, 4},
                                {26, 8, 16, 7, 27, 20, 13, 2},
                                {41, 52, 31, 37, 47, 55, 30, 40},
                                {51, 45, 33, 48, 44, 49, 39, 56},
                                {34, 53, 46, 42, 50, 36, 29, 32}};
    vector<string> combinedBinaryBits(56);
    int currIndex = 0;

    for (int i = 0; i < 28; i++) {
        combinedBinaryBits[i] = Left28Bits[i];
    }
    for (int i = 0; i < 28; i++) {
        combinedBinaryBits[28 + i] = Right28Bits[i];
    }

    vector<string> binaryTextAfterCompression(48); // 48 bits
    for (int i=0; i<6; i++) {
        for (int j=0; j<8; j++) {
            int targetIndex = compressionTable[i][j];
            binaryTextAfterCompression[currIndex] = combinedBinaryBits[targetIndex-1];
            currIndex++;
        }
    }
    return binaryTextAfterCompression;
}

vector<vector<string>> keyGeneration (vector<string> binaryText) {

    // step 02
    vector<string> FiftySixBitsKey = parityDrop(binaryText);
    
    // step 03
    pair<vector<string>, vector<string>> result56Bits = break56BitsBinaryTextIntoTwo(FiftySixBitsKey);
    vector<string> Left28Bits = result56Bits.first;
    vector<string> Right28Bits = result56Bits.second;

    int roundShifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    vector<vector<string>> keys(16);

    for (int round=0; round<16; round++) {
        // step 04
        Left28Bits = shiftLeft(Left28Bits, roundShifts[round]); // fixed here: Update Left28Bits after shift
        Right28Bits = shiftLeft(Right28Bits, roundShifts[round]); // fixed here: Update Right28Bits after shift

        // step 05
        vector<string> binaryTextAfterCompression = compressionBox(Left28Bits, Right28Bits);

        keys[round] = binaryTextAfterCompression;
    }
    return keys;
}

int main () {

    string text = takeInput();

    // convert text to binary
    pair<bool, vector<string>> result = convertTextToBinary(text);

    // if text is not 64 bits, return
    if (!result.first) {
        cout<<"The text is not 64 bit. Try again.";
        return 1;
    }

    // store the binary conversion into binaryText
    vector<string>binaryText = result.second;

    vector<vector<string>> keys = keyGeneration(binaryText);

    for (int i = 0; i < keys.size(); i++) {
        cout << "Key " << i + 1 << ": ";
        for (const string &keyPart : keys[i]) {
            cout << keyPart;
        }
        cout << endl;
    }
    return 0;
}
