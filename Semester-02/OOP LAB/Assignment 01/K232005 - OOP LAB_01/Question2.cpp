#include <iostream>
using namespace std;

int main () {
    float marks1, marks2, marks3, avgMarks, totalMarks, percentage;
    int i;
    char grade;

    cout<<"Hello! Welcome to the program.\n";
    
    // Input 
    cout<<"Enter the marks for Mathematics: ";
    cin>>marks1;
    cout<<"Enter the marks for English: ";
    cin>>marks2;
    cout<<"Enter the marks for Science: ";
    cin>>marks3;

    // Calculating total and average marks
    totalMarks = marks1 + marks2 + marks3;
    avgMarks = totalMarks / 3;

    percentage = totalMarks / 300 * 100;
    // Finding Percentage:
    if (percentage>90)
        grade = 'A';
    else if (percentage>=80 && percentage<90)
        grade = 'B';
    else if (percentage>=70 && percentage<80)
        grade = 'C';
    else if (percentage>=60 && percentage<70)
        grade = 'D';
    else 
        grade = 'F';

    cout<<"-------------------------------------------";
    cout<<"\nTotal marks obtained: "<<totalMarks<<endl;
    cout<<"Percentage: "<<percentage<<endl;
    cout<<"Average marks: "<<avgMarks<<endl;
    cout<<"Grade: "<<grade<<endl;
    cout<<"-------------------------------------------";
    
    return 0;
}