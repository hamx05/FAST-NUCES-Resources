#include <iostream>
using namespace std;

template <typename T>
class Pet {
    protected:
        string name;
        int age;

    public:
        Pet (string name, int age) {
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

class Cat : public Pet <Cat> {
    public:
        Cat (string name, int age) : Pet (name, age) {}

        void makeSound () const {
            cout<<"The cat says Moew!" << endl;
        }
};

class Dog : public Pet <Dog> {
    public:
        Dog (string name, int age) : Pet (name, age) {}

        void makeSound () const {
            cout<<"The dog says Woof!" << endl;
        }
};

class Bird : public Pet <Bird> {
    public:
        Bird (string name, int age) : Pet (name, age) {}

        void makeSound () const {
            cout<<"The bird chirps!" << endl;
        }
};

int main() {

    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"Name: Muhammad Hammad" << endl;
    cout<<"Roll No: 23K-2005" << endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;

    Pet<Cat>* cat1 = new Cat("Billi", 2);
    Pet<Dog>* dog1 = new Dog("Kutta", 5);
    Pet<Bird>* bird1 = new Bird("Chirya", 1);

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