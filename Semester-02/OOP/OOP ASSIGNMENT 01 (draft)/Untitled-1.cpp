#include <iostream>
#include <list>
using namespace std;

#define N 3 // Number of pets
#define n 3 // No of special skills

class Pet {
    private:
        string name;
        string species;
        string healthStatus; // Healthy or Sick
        string specialSkills[n]; // Any 3 (Assuming)
        int hungerLevel; // Max 5 (Assuming)
        int happinessLevel; // Max 10, Min 1
        bool status; // 1 -> Available for Adoption, 0 for Not Available
        

    public:
        Pet () : specialSkills{"ABC", "PQR", "XYZ"} { // Default constructor
            name = "Default";
            species = "Default";            
            healthStatus = "Healthy";
            hungerLevel = 0;
            happinessLevel = 0;
            status = 1;
        }


        Pet (string a, string b, string c, int d, int e, int f) : name(a), species(b), healthStatus(c), hungerLevel(d), happinessLevel(e), status(f) {
            for (int i = 0; i < n; ++i) {
                specialSkills[i] = "Default"; 
            }
        }

        void displayPetDetails() {
            cout<<"Name: " << name << endl;
            cout<<"Specie: " << species << endl;
            cout<<"Health Status: " << healthStatus << endl;
            cout<<"Hunger Level: " << hungerLevel << endl;
            cout<<"Happiness Level: " << happinessLevel << endl;
            cout<<"Special skills: " << specialSkills << endl;
            cout<<"Adoption status: " << status << endl;
        }

        string getName() const { return name; }
        string getSpecies() const { return species; }
        string getHealthStatus() const { return healthStatus; }
        string getSpecialSkill(int index) const { return (index >= 0 && index < 3) ? specialSkills[index] : ""; }
        int getHungerLevel() const { return hungerLevel; }
        int getHappinessLevel() const { return happinessLevel; }

        void updateHappiness () {
            int choice, tempHappinessLevel, updatedHappiness;

            if (happinessLevel >=1 && happinessLevel< 10) {
                cout<<"Choose one of the following: "  <<endl << "1. Play with the pet\n2. Cuddle the pet\n3. Take them for a walk\n4. Feed the pet\n5. Exit program";
                cin>> choice;

                switch (choice) {
                    case 1: // Base case lagani ha k agar 10 se zyada hua to kia karenge
                        if (happinessLevel+3 > 10) {
                            tempHappinessLevel = happinessLevel;
                            happinessLevel = 10 % (happinessLevel+3);
                            updatedHappiness = happinessLevel - tempHappinessLevel;
                        }
                        else {
                            tempHappinessLevel = happinessLevel;
                            happinessLevel = happinessLevel + 3;
                            updatedHappiness = happinessLevel - tempHappinessLevel;
                        }
                        cout<<"The pet is happy to play with you and its happiness level is increased by " << updatedHappiness <<endl;
                    break;

                    case 2:
                        if (happinessLevel+3 > 10) {
                            tempHappinessLevel = happinessLevel;
                            happinessLevel = 10 % (happinessLevel+3);
                            updatedHappiness = happinessLevel - tempHappinessLevel;
                        }
                        else {
                            tempHappinessLevel = happinessLevel;
                            happinessLevel = happinessLevel + 3;
                            updatedHappiness = happinessLevel - tempHappinessLevel;
                        }
                        cout<<"The pet enjoyed the cuddle and its happiness level is increased by " << updatedHappiness <<endl;
                    break;

                    case 3:
                        if (happinessLevel+3 > 10) {
                            tempHappinessLevel = happinessLevel;
                            happinessLevel = 10 % (happinessLevel+3);
                            updatedHappiness = happinessLevel - tempHappinessLevel;
                        }
                        else {
                            tempHappinessLevel = happinessLevel;
                            happinessLevel = happinessLevel + 3;
                            updatedHappiness = happinessLevel - tempHappinessLevel;
                        }
                        cout<<"The pet enjoyed the walk and its happiness level is increased by " << updatedHappiness <<endl;
                    break;

                    case 4:
                        updateHealth();
                    break;
                    
                    case 5:
                        cout<<"The program has been closed." << endl;
                        exit(1);
                    break;
                }
            }
            else {
                cout<<"The pet is already fully happy!" <<endl;
            }
        }

        void updateHealth () {
            char choice;

            cout<<"Is the pet running around and playing energetically? (y or n): ";
            cin>>choice;
            
            if (choice == 'y' || choice == 'Y') {
                cout<<"The pet is healthy!" << endl;
                healthStatus = "Healthy";
            }
            else if (choice=='n' || choice == 'N') {
                cout<<"The pet must be sick!" << endl;
                healthStatus = "Sick";
            }
            else {
                cout<<"Invalid choice." << endl;
            }
        }
        void updateHunger () {
            char choice;

            if (hungerLevel >= 0 && hungerLevel <=4) {
                cout<<"The pet is hungry! Do you want to feed the pet? ";
                cin>> choice;

                if (choice == 'y' || choice == 'Y') {
                    hungerLevel = 5% (hungerLevel + 3);

                    if (happinessLevel < 10) {
                         happinessLevel = happinessLevel + 1;
                         cout<<"The pet is now feeded and happiness level is increased by 1!" << endl;
                    }
                    else {
                        cout<<"The pet is now feeded and happiness level is already maximum!" << endl;
                    }
                    
                }

                else if (choice=='n' || choice == 'N') {
                    if (happinessLevel >= 1 && happinessLevel <= 10)
                        happinessLevel = happinessLevel - 1;
                    cout<<"No food given, the pet will remain hungry and its happiness level is decreased by 1!" << endl;
                }

                else {
                    cout<<"Invalid choice." << endl;
                }
            }
            else {
                cout<<"The pet is full already and does not want to be feeded!";
            }
        }

        friend void adoptPet();
};

class Adopter {
    private:
        string adopterName; 
        int adopterMobileNum;
        Pet pet[N];
        string adoptedPetRecords[N];
        string pets[3] = {"Cat", "Dog", "Parrot"};

    public:

        void adoptPet() {
            int i, choice;

            for (i=0; i<N; i++) {
                cout<<"\tDetails for Pet " << i+1 << endl;
                pet[i].displayPetDetails();
            }
            //adoptedPetRecords[0] = pet[i].getName();

            cout<<"Enter your name: ";
            getline(cin, adopterName);
            cout<<"Enter your cell phone number: ";
            cin>>adopterMobileNum;
            cout<<"Enter the number of the pet you want to adopt: ";
            cin >> choice;
            //adoptedPetRecords[0] = pets[choice - 1];
            adoptedPetRecords[0] = pet[i].getName();
            //cout<<"You have selected " << pets[choice-1] << endl;
            cout<<"You have selected " << pet[i].getName() << endl;
        }

        void returnPet() {
            int choice;
            cout<<"Enter the number of the pet you want to return: ";
            cin >> choice;
            adoptedPetRecords[choice-1] = "";
            cout<<"The pet has been returned and your adoption list has been successfully updated." << endl;
            displayAdoptedPets();
        }


        void displayAdoptedPets() {
        cout << "Actively Adopted Pets:" << endl;
        cout << "Adopter Name: " << adopterName << endl;
        cout << "Mobile Number: " << adopterMobileNum << endl;
        cout << "Adopted Pets:" << endl;
        for (int i = 0; i < N; ++i) {
            if (!adoptedPetRecords[i].empty()) {
                cout << "Pet " << i + 1 << ": " << adoptedPetRecords[i] << " (Index: " << i << ")" << endl;
            }
        }
    }

};

// int main () {

//     Pet P1 ("Thomas", "GermanShephard", "Sick", 3, 5, 1);

//     Adopter adopter;
//     adopter.adoptPet();
//     adopter.displayAdoptedPets();



//     return 0;
// }

int main() {
    // Create pets using default and parameterized constructors
    Pet defaultPet; // Using default constructor
    Pet parameterizedPet("Buddy", "Dog", "Healthy", 2, 8, 1); // Using parameterized constructor

    // Display details of pets
    cout << "Details of Default Pet:" << endl;
    defaultPet.displayPetDetails();
    cout << endl;

    cout << "Details of Parameterized Pet:" << endl;
    parameterizedPet.displayPetDetails();
    cout << endl;

    Adopter adopter;
    adopter.adoptPet();
    adopter.displayAdoptedPets();
    adopter.returnPet();

    // Interact with pets
    // defaultPet.updateHappiness(); // Update happiness of default pet
    // defaultPet.updateHealth(); // Update health of default pet
    // defaultPet.updateHunger(); // Update hunger of default pet

    // parameterizedPet.updateHappiness(); // Update happiness of parameterized pet
    // parameterizedPet.updateHealth(); // Update health of parameterized pet
    // parameterizedPet.updateHunger(); // Update hunger of parameterized pet

    return 0;
}