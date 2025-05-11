#include <iostream>
#include <fstream>
using namespace std;

int main () {
	
	ifstream inputFile;
	ofstream outputFile;
	string data;
	
	inputFile.open("input.txt");
	
	if (inputFile == NULL) {
		cout<<"Error opening the input file!" << endl;
	}
	else {
		
		outputFile.open("output.txt");
		if (!outputFile) {
			cout<<"Error opening the output file!" << endl;
		}
		else {
			char ch;
    		while (inputFile.get(ch)) {
        	outputFile.put(ch);
    	}
			
			cout<<"Task performed successfully.";
			inputFile.close();
    		outputFile.close();
		}
	}
	

    return 0;
}
