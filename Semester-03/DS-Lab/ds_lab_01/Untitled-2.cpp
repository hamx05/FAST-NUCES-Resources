#include <iostream>
#include <string> // Use std::string instead of char* for automatic memory management

class Exam {
private:
    std::string studentName;  // Using std::string
    std::string examDate;     // Using std::string
    int score;

public:
    // Constructor
    Exam(const std::string& name, const std::string& date, int score) {
        this->studentName = name;
        this->examDate = date;
        this->score = score;
    }

    // Method to set exam details
    void setExamDetails(const std::string& name, const std::string& date, int score) {
        this->studentName = name;
        this->examDate = date;
        this->score = score;
    }

    // Method to display exam details
    void displayExamDetails() const {
        std::cout << "Student Name: " << studentName << std::endl;
        std::cout << "Exam Date: " << examDate << std::endl;
        std::cout << "Score: " << score << std::endl;
    }
};

int main() {
    // Creating an instance of Exam
    Exam exam1("Alice", "2024-09-01", 85);

    // Displaying the details of exam1
    std::cout << "Original Exam Details (exam1):" << std::endl;
    exam1.displayExamDetails();

    // Creating a shallow copy of exam1
    Exam exam2 = exam1; // This uses the default copy constructor

    // Displaying the details of exam2
    std::cout << "\nShallow Copy Exam Details (exam2):" << std::endl;
    exam2.displayExamDetails();

    // Modifying the details of exam2
    exam2.setExamDetails("Bob", "2024-09-02", 90);

    std::cout << "\nModified Exam Details (exam2):" << std::endl;
    exam2.displayExamDetails();

    // Displaying the details of exam1 again to observe the effect of shallow copy
    std::cout << "\nOriginal Exam Details After Modification (exam1):" << std::endl;
    exam1.displayExamDetails();

    return 0;
}
