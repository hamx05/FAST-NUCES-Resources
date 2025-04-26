#include <iostream>
using namespace std;

void CheckAttendance() {
	
	string firstName, lastName;
	int attendance;
	
	cout<<"Enter your full name: "; cin>>firstName; cin>>lastName;
	cout<<"Okay " << firstName << " "  << lastName << ", enter your attendance: "; cin>>attendance;
	if (attendance<=80) {
		cout<<"Sorry, " << firstName << " "  << lastName << ". You are not eligible to sit in the exams!";
	}
	else {
		cout<<"Congratulations, " << firstName << " " << lastName << "! You are eligble to sit in the exams!";
	}
}

int main () {
	CheckAttendance();
	
	return 0;
}

