#include <iostream>
#include <cstring>
using namespace std;

#define N 3 // Number of pets

class Pet {
    private:
        string name;
        string species;
        string healthStatus; // Healthy or Sick
        string specialSkill; // Any 1 special skill
        int hungerLevel; // Max 5 (Assuming)
        int happinessLevel; // Max 10, Min 1
        bool status; // 1 -> Available for Adoption, 0 for Not Available

    public:
        Pet () { // Default constructor
            name = "Default pet name";
            species = "Default pet specie";           
            healthStatus = "Healthy";
            hungerLevel = 0;
            happinessLevel = 0;
            status = 1;
            specialSkill = "Default special skill";
        }


        Pet (string a, string b, string c, int d, int e, int f, string g) : name(a), species(b), healthStatus(c), hungerLevel(d), happinessLevel(e), status(f), specialSkill(g) { }
        
        void setName () {
        	string x;
        	cout<<"Enter Name: ";
        	//cin.ignore();
    		getline(cin, x);
    		name = x;
		}
		void setSpecies () {
			string x;
			cout<<"Enter Specie: ";
			//cin.ignore();
    		getline(cin, x);
    		species = x;
		}
		void setSpecialSkill () {
            string x;
   			cout<<"Enter a Special skill :";
   			getline(cin, x);
			specialSkill = x;
        }
		void setHealthStatus () {
			string x;
			cout<<"Enter Health Status : ";
			//cin.ignore();
    		getline(cin, x);
			healthStatus = x;;
		}		
		void setHungerLevel () {
			int x;
			cout<<"Enter Hunger level (1-5) : ";
    		cin>> x;
    		hungerLevel = x;
		}
		void setHappinessLevel () {
			int x;
			cout<<"Enter Happiness level (1-10): ";
    		cin>> x;
    		happinessLevel = x;
		}
		void setStatus () {
			bool x;
			cout<<"Enter Adoption status (1 for Available & 0 for Not available): ";
			cin>> x;
    		status =x;
    		cin.ignore();
		}

        void displayPetDetails() {
            cout<<"Name: " << name << endl;
            cout<<"Specie: " << species << endl;
            cout<<"Health Status: " << healthStatus << endl;
            cout<<"Hunger Level: " << hungerLevel << endl;
            cout<<"Happiness Level: " << happinessLevel << endl;
            cout<<"Special skill: " << specialSkill << endl;
            cout<<"Adoption status: " << status << endl;
        }

        string getName() const { return name; }
        string getSpecies() const { return species; }
        string getHealthStatus() const { return healthStatus; }
        string getSpecialSkill() const { return specialSkill; }
        int getHungerLevel() const { return hungerLevel; }
        int getHappinessLevel() const { return happinessLevel; }
        bool getStatus() const { return status; }

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

        //friend void adoptPet();
};

int numOfPetsToAdopt = 0, numOfPetsToReturn = 0;
int totalNumOfPets = numOfPetsToAdopt - numOfPetsToReturn; // numOfPetsToAdopt = number of pets user wants to adopt

class Adopter {
    private:
        string adopterName; 
        int adopterMobileNum;
        Pet pet[N];
        string adoptedPetRecords[N][7]; // 2D array to store pet number in columns and their corresponding data in the rows. 7 because Pet class k 7 attributes hain

    public:
    	
    	// Setter function to populate the Pet's Object Array.
		// Uske bad jab user pet adopt ya return krega to us index ka corresponding data adoptedPetRecords wali string me copy/remove kr denge.
    	void setPetArray () {
    		for (int i=0; i<N; i++) {
    			cout<<"\tEnter the details for pet " << i+1 << endl;
    			pet[i].setName ();
    			pet[i].setSpecies();
				pet[i].setSpecialSkill();
    			pet[i].setHealthStatus();
    			pet[i].setHungerLevel();
    			pet[i].setHappinessLevel();
    			pet[i].setStatus();
			}
		}

        int adoptPet() {
            int i, j;
            int petSelection[N];

            for (i=0; i<N; i++) { // 3 baar chalega kyuke assuming 3 pets
                cout<<"\tDetails for Pet " << i+1 << endl;
                pet[i].displayPetDetails();
            }

            cout<<"\n\nEnter your name: ";
            //cin.ignore();
            getline(cin, adopterName);
            cout<<"Enter your cell phone number: ";
            cin>>adopterMobileNum;
            cout<<"How many pets do you want to adopt?: ";
            cin >> numOfPetsToAdopt;
            
            if (numOfPetsToAdopt==0) {
            	cout<<"You have chosen to not adopt any pet." << endl;
            	return 0;
			}
			
			int *ArrOfPetsToAdopt = new int(numOfPetsToAdopt); // Wo pet number, jo user ko adopt krna ha
			
			for (i=0; i<numOfPetsToAdopt; i++) {
				cout<<"Enter the pet number which you want to adopt: ";
				cin >> ArrOfPetsToAdopt[i];
			}
			
			for (i=0; i<numOfPetsToAdopt; i++) {
				cout<<"Storing the records for Pet " << i+1 << endl;
					int petIndex = ArrOfPetsToAdopt[i] - 1; // Subtracting 1 to obtain the index of the pet number that user wants to adopt.
					adoptedPetRecords[i][0] = pet[petIndex].getName(); 
					adoptedPetRecords[i][1] = pet[petIndex].getSpecies();
					adoptedPetRecords[i][2] = pet[petIndex].getSpecialSkill();
					adoptedPetRecords[i][3] = pet[petIndex].getHealthStatus();
					adoptedPetRecords[i][4] = to_string(pet[petIndex].getHungerLevel());
					adoptedPetRecords[i][5] = to_string(pet[petIndex].getHappinessLevel());
			}
			return 0;
        }

        int returnPet() {
            int i, j;
			cout<<"How many pets do you want to return?: ";
            cin >> numOfPetsToReturn;
            
            if (numOfPetsToReturn==0) {
            	cout<<"You have chosen to not return any pet." << endl;
            	return 0;
			}
			
			int *petsToReturn = new int(numOfPetsToReturn); // Wo pet number, jo user ko return krna ha
			
			for (i=0; i<numOfPetsToReturn; i++) {
				cout<<"Enter the pet number which you want to return: ";
				cin >> petsToReturn[i];
			}
			
			for (i = 0; i < numOfPetsToReturn; i++) {
    			cout << "Deleting the records for Pet " << petsToReturn[i] << endl;

			    // yahan par subtracting 1 to obtain the index of the pet number that user wants to delete.
			    int petIndex = petsToReturn[i] - 1;
			
			    for (int j = petIndex; j < numOfPetsToReturn - 1; j++) {
			        adoptedPetRecords[j][0] = adoptedPetRecords[j + 1][0];
			        adoptedPetRecords[j][1] = adoptedPetRecords[j + 1][1];
			        adoptedPetRecords[j][2] = adoptedPetRecords[j + 1][2];
			        adoptedPetRecords[j][3] = adoptedPetRecords[j + 1][3];
			        adoptedPetRecords[j][4] = adoptedPetRecords[j + 1][4];
                    adoptedPetRecords[j][5] = adoptedPetRecords[j + 1][5];
			    }
			
			    adoptedPetRecords[numOfPetsToReturn - 1][0] = "";
			    adoptedPetRecords[numOfPetsToReturn - 1][1] = "";
			    adoptedPetRecords[numOfPetsToReturn - 1][2] = "";
			    adoptedPetRecords[numOfPetsToReturn - 1][3] = "";
			    adoptedPetRecords[numOfPetsToReturn - 1][4] = "";
                adoptedPetRecords[numOfPetsToReturn - 1][5] = "";
			
			    numOfPetsToReturn--;
		}
            cout<<"The pet has been returned and your adoption list has been successfully updated." << endl;
            displayAdoptedPets();
        }


        void displayAdopterDetails() {
	        cout << "\tctively Adopted Pets:" << endl;
	        cout << "Adopter Name: " << adopterName << endl;
	        cout << "Mobile Number: " << adopterMobileNum << endl;
	        cout << "Adopted Pets:" << endl;
    	}
    	
    	void displayAdoptedPets () {	
	        for (int i = 0; i < totalNumOfPets; ++i) {
		        cout<<"Pet's Name: " << adoptedPetRecords[i][0] << endl;
                cout<<"Pet's Species: " << adoptedPetRecords[i][1] << endl;
                cout<<"Pet's special skill: " << adoptedPetRecords[i][2] << endl;
                cout<<"Pet's Health Status: " << adoptedPetRecords[i][3] << endl;
                cout<<"Pet's Hunger Level: " << adoptedPetRecords[i][4] << endl;
                cout<<"Pet's Happiness Level: " << adoptedPetRecords[i][5] << endl;
	        }
    	}
};

int main() {
    cout<<"********************"<<endl;
    cout<<"Name: Muhammad Hammad"<<endl;
    cout<<"Roll no: 23K-2005"<<endl;
    cout<<"********************"<<endl;
    
    // Create pets using default and parameterized constructors
    Pet Pet1; // Using default constructor
    Pet Pet2("Buddy", "Dog", "Healthy", 2, 8, 1, "Catch a ball"); // Using parameterized constructor

    // Displaying details of pets
    cout << "Details of Default Pet:" << endl;
    Pet1.displayPetDetails();
    cout << endl;

    cout << "Details of Parameterized Pet:" << endl;
    Pet2.displayPetDetails();
    cout << endl;

    // Adopter object bana rahe hain aur usse pets adopt/return krwa rahe hain
    Adopter adopter;
    adopter.setPetArray();
    
    adopter.adoptPet();
    adopter.displayAdopterDetails();
    adopter.displayAdoptedPets();
    adopter.returnPet();

    // Interact with pets
    Pet2.updateHappiness();
    Pet2.updateHealth();
    Pet2.updateHunger();

    return 0;
}
