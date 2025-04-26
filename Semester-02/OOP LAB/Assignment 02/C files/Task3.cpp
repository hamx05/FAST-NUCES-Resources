#include <iostream>
using namespace std;

int calcMCQs(int marksMCQs) {
	cout<<"Enter the marks in the MCQS: "; cin>>marksMCQs;
	if (marksMCQs<0 || marksMCQs> 50) {
		cout<<"Invalid request. The marks needs to be between 1 and 50.\n";
		calcMCQs(marksMCQs);
	}
}

int calcEssay(int marksEssay) {
	cout<<"Enter the marks in the essay: "; cin>>marksEssay;
	if (marksEssay<0 || marksEssay> 50) {
		cout<<"Invalid request. The marks needs to be between 1 and 50.\n";
		calcEssay(marksEssay);
	}
}

int calcViva(int marksViva) {
	cout<<"Enter the marks in the viva: "; cin>>marksViva;
	if (marksViva<0 || marksViva> 50) {
		cout<<"Invalid request. The marks needs to be between 1 and 50.\n";
		calcViva(marksViva);
	}
}

int main () {
	
	int marksMCQs, marksEssay, marksViva;
	int totalMarks = calcMCQs(marksMCQs) + calcEssay(marksEssay) + calcViva(marksViva);
	cout<<"Total marks: " << totalMarks << "\n";
	if (totalMarks < 75) {
		cout<<"Oops! You have failed the test.";
	}
	else {
		cout<<"Congratulations! You have passed the test.";
	}
	
	return 0;
}
