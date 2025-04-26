#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open file in ate mode
    ofstream file("FILE_ATE.txt", ios::trunc);

    // Write data at the end of the file
    file << "Trunced";

    // Close the file
    file.close();
    
    return 0;
}
