#include <iostream>
#include <string>
using namespace std;

class course {
    int creditHours;

public:
    string courseName;
    string courseCode;
    course(string code, string name, int h) : courseCode(code), courseName(name), creditHours(h) {}
    int credit() const { return creditHours; }
};

class Student {
    string studentID;
    string studentName;
    course *noOfCourses[10];
    int num;

public:
    // Constructor
    Student(string id, string name) : studentID(id), studentName(name), num(0) {}

    void enroll(course *newCourse) {
        if (num > 10) {
            cout << "Maximum number of courses reached." << endl;
        }
        else {
            noOfCourses[num++] = newCourse;
            cout << "You have been enrolled in: " << newCourse->courseName<< endl;
        }
    }

    void drop(course *CourseToBeDropped) {
        for (int i = 0; i < num; i) {
            if (noOfCourses[i] == CourseToBeDropped) {
                for (int j = i; j < num - 1; ++j) {
                    noOfCourses[j] = noOfCourses[j + 1];
                }
                num--;
                cout << "Your course " << CourseToBeDropped->courseName << " has been dropped" << endl;
                return;
            }
        }
        cout << "Course not found." << endl;
    }

    int getTotalCreditHours() {
        int totalCredit = 0;
        for (int i = 0; i < num; ++i) {
            totalCredit += noOfCourses[i]->credit();
        }
        return totalCredit;
    }

    void printEnrolledCourses() {
        cout << "Student ID: " << studentID << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Current enrolled courses:" << endl;
        for (int i = 0; i < num; ++i) {
            cout << "\tCourse " << i + 1 << "  Details: " << endl;
            cout << "Course ID: " << noOfCourses[i]->courseCode << endl;
            cout << "Course Name: " << noOfCourses[i]->courseName << endl;
            cout << "Credit Hours: " << noOfCourses[i]->credit() << endl;
        }
    }
};

int main()
{
    Student std("23K2005", "Muhammad Hammad");
    course course1("CS1002", "OOP", 3);
    course course2("DLD1002", "DLD", 2);
    std.enroll(&course1);
    std.enroll(&course2);
    std.printEnrolledCourses();
    cout << "Total credit hours: " << std.getTotalCreditHours() << endl;
    std.drop(&course2);
    return 0;
}
