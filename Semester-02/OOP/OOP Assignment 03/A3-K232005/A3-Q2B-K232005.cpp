#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pet {
    protected:
        T1 name;
        T2 age;

    public:
        Pet (T1 name, T2 age) {
            this->name = name;
            this->age = age;
        }
        
        // pure virtual func
        virtual void makeSound() const = 0;

        void displayPetInfo () {
            cout<<"Name: " << name << endl;
            cout<<"Age: " << age << " year(s)" << endl;
        } 
};

template <typename T1, typename T2>
class Cat : public Pet<T1, T2> {
    public:
        Cat (T1 name, T2 age) : Pet<T1, T2> (name, age) {}

        void makeSound () const {
            cout<<"The cat says Moew!" << endl;
        }
};

template <typename T1, typename T2>
class Dog : public Pet<T1, T2> {
    public:
        Dog (T1 name, T2 age) : Pet<T1, T2> (name, age) {}

        void makeSound () const {
            cout<<"The dog says Woof!" << endl;
        }
};

template <typename T1, typename T2>
class Bird : public Pet<T1, T2> {
    public:
        Bird (T1 name, T2 age) : Pet<T1, T2> (name, age) {}

        void makeSound () const {
            cout<<"The bird chirps!" << endl;
        }
};

int main() {

    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"Name: Muhammad Hammad" << endl;
    cout<<"Roll No: 23K-2005" << endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;

    Pet<string, int>* cat1 = new Cat<string, int>("Billi", 2);
    Pet<int, float>* dog1 = new Dog<int, float>(27, 5.5);
    Pet<char, string>* bird1 = new Bird<char, string>('C', "1");

    cout<<"---------------------------------------" << endl;
    cout<<"\tInstances of Cat Class" << endl;    
    cat1->displayPetInfo();
    cat1->makeSound();
    
    cout<< endl << "---------------------------------------" << endl;
    cout<<"\tInstances of Dog Class" << endl;
    dog1->displayPetInfo();
    dog1->makeSound();
    
    cout<< endl << "---------------------------------------" << endl;
    cout<<"\tInstances of Bird Class" << endl;
    bird1->displayPetInfo();
    bird1->makeSound();

    return 0;
}