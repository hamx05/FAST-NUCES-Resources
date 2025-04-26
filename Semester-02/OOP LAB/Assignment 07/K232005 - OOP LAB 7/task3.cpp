#include <iostream>
using namespace std;

class Animal {
    protected:
        string name;
        int age;
        static int ID;
    
    public:
        Animal () {
            name = "Default name";
            age = 5; // assuming a default age
            ID++;
        }

        void setName () {
            cout<<"Enter the name ";
            cin >> name;
        }
        void setAge () {
            cout<<"Enter the age ";
            cin >> age;
        }

        void printData() {
            cout<< "ID: " << ID << endl;
            cout<< "Name: " << name << endl;
            cout<< "Age: " << age << endl;
        }
};

int Animal :: ID = 0;

class Lion : public Animal {
    private:
        int teeth;
    public:
        void setData() {
            Animal::setName();
            Animal::setAge();
            cout << "Enter the number of teeth: ";
            cin >> teeth;
        }
        void printData() {
            Animal::printData();
            cout << "Teeth: " << teeth << endl;
        }

};

class Eagle : public Animal {
    private:
        int wings;
        int head;
    public:
        void setData() {
            Animal::setName();
            Animal::setAge();
            cout << "Enter the number of wings: ";
            cin >> wings;
            cout << "Enter the number of heads: ";
            cin >> head;
        }
        void printData() {
            Animal::printData();
            cout << "Wings: " << wings << endl;
            cout << "Head: " << head << endl;
        }   

};

class Griffin : public Lion, public Eagle {
    public:
        void setData() {
            Lion::setData();
            Eagle::setData();
        }

        void printData() {
            cout << "Griffin's Data:" << endl;
            Lion::printData();
            Eagle::printData();
        }
};

int main () {
    
    cout<<"--------------------" << endl;
    cout<<"Enter data for Lion:" << endl;
    Lion lion1;
    lion1.setData();
    lion1.printData();

    cout<<"--------------------" << endl;
    cout<<"Enter data for Eagle:" << endl;
    Eagle eagle1;
    eagle1.setData();
    eagle1.printData();

    cout<<"--------------------" << endl;
    cout<<"Enter data for Griffin:" << endl;
    Griffin griffin1;
    griffin1.setData();
    griffin1.printData();
    return 0;
}