#include <iostream>
using namespace std;

class Medicine {
    protected:
        string name, formula, manufactureDate, expiryDate;
        int retailPrice;

    public:
        // Constructor
        Medicine (string name, string formula, string manufactureDate, string expiryDate, int retailPrice) {
            this->name = name;
            this->formula = formula;
            this->manufactureDate = manufactureDate;
            this->expiryDate = expiryDate;
            this->retailPrice = retailPrice;
        }

        // Setters
        void setName () {
            
        }
        void setFormula () {
            
        }
        void setManuFactureDate () {
            
        }
        void setExpiryDate () {
            
        }
        void setRetailPrice () {
            
        }

        // Getters
        const getName () {
            return name;
        }
        const getFormula () {
            return formula;
        }
        const getManuFactureDate () {
            return manufactureDate;
        }
        const getExpiryDate () {
            return expiryDate;
        }
        const int getRetailPrice () {
            return retailPrice;
        }

        // Friend Class
        friend class Pharmacist;

};

class Tablet : public Medicine {
    protected:
        int sucroseLevel; // 0 to 1
    
    public:
        Tablet (string name, string formula, string manufactureDate, string expiryDate, int retailPrice, int sucroseLevel) 
        : Medicine (name, formula, manufactureDate, expiryDate, retailPrice) {
            this->sucroseLevel = sucroseLevel;
        }

        // Add Overridden function for printing tablet details.


};

class Capsule : public Medicine {
    protected:
        float absorptionPercentage; // 1 to 100

    public:
        Capsule (string name, string formula, string manufactureDate, string expiryDate, int retailPrice, int absorptionPercentage) 
        : Medicine (name, formula, manufactureDate, expiryDate, retailPrice) {
            this->absorptionPercentage = absorptionPercentage;
        }

        // Add Overridden function for printing capsule details.
};

class Syrup : public Medicine {
    protected:
        int ML;

    public:
        Syrup (string name, string formula, string manufactureDate, string expiryDate, int retailPrice, int ML) 
        : Medicine (name, formula, manufactureDate, expiryDate, retailPrice) {
            this->ML = ML;
        }
};

class Pharmacist {
    protected:

    public:
        void searchMedicine () {
            string medicineToFind;
            cout<<"Enter the name of medicine you want to find: ";
            getline(cin, medicineToFind);

            if (medicineToFind == ) {

            }
        }

    
};

class Counter {
    protected:
    

    public:

        void searchMedicine () {
            // search based on name
        }

        void updateRevenue () {

        }
};

int main() {
    
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"Name: Muhammad Hammad" << endl;
    cout<<"Roll No: 23K-2005" << endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;



    return 0;
}