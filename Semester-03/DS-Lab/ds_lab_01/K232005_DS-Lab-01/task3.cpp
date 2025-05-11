#include <iostream>
#include <cstring>
using namespace std;

class Exam {
    private:
        char* name;
        char* examDate;
        int score;

    public:

        Exam (const char* newName,const char* newExamDate, int score) {
            name = new char[strlen(newName)+1];
            strcpy(name, newName);
            examDate = new char[strlen(newExamDate)+1];
            strcpy(examDate, newExamDate);
            this->score=score;
        }

        void setName (const char* newName) {
            delete[] name;
            strcpy(name, newName);
        }

        void setExamDate (const char* newExamDate) {
            delete[] examDate;
            strcpy(examDate, newExamDate);
        }

        void setScore (int score) {
            this->score=score;
        }

        void displayExamDetails () {
            cout<< "Student Name: " << name << endl;
            cout<< "Exam Date: " << examDate << endl;
            cout<< "Score: " << score << endl;
        }


};

int main () {
    
    Exam e1("Hammad", "01-09-2024", 60);
    cout << "Original Object Details:" << endl;
    e1.displayExamDetails();
    
    Exam e2 = e1;
    cout<<endl<< "Shallow Copy Of Exam Details:" << endl;
    e2.displayExamDetails();

    cout<<endl<<"Details of Shallow Copy Object After Modification:" << endl;
    e2.setName("Scofield");
    e2.setExamDate("01-01-2025");
    e2.setScore(70);
    e2.displayExamDetails();

    cout<<endl<<"Details of Original Object After Modification in Shallow Copy:" << endl;
    e1.displayExamDetails();

    return 0;
}