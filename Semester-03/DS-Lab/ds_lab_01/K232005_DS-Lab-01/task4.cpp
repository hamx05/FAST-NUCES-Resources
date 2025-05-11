#include <iostream>
#include <cstring>
using namespace std;

class Document {
    private:
        char* text;

    public:
        Document (const char* newText) {
            text = new char[strlen(newText)+1];
            strcpy(text, newText);
        }

        ~Document () {
            delete[] text;
        }

        Document (Document &obj) { // copy constructor
            text = new char[strlen(obj.text) + 1];
            strcpy(text, obj.text);
        }

        void setText(const char* newText) {
            strcpy(text, newText);
        }

        void display () {
            cout<<text<<endl;
        }

};

int main () {

    Document d1("This is a sample sentence."); // intiliazing a text
    Document d2(d1); // copy constructor called
    Document d3 = d1; // copy assignment operator called
    
    cout<<"Object 1: "; d1.display();
    cout<<"Object 2: "; d2.display();
    cout<<"Object 3: "; d3.display();
    d1.setText("This is new text.");
    cout<<"Object 1 again: "; d1.display();
    cout<<"Object 2 again: "; d2.display();
    cout<<"Object 3 again: "; d3.display();

    return 0;
}