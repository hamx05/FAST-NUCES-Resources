#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int get_int() {
    int n;
    for (;;) {
        if (cin >> n) {
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry. Please re-enter: ";
    }
}

class Medicine {
    protected:
        vector <string> name;
        vector <string> formula;
        vector <string> manufactureDate;
        vector <string> expiryDate;
        vector <int> retailPrice;

    public:
        // Constructor
        Medicine () {
            name = {"Aspirin","Panadol","Zyrtec"};
            formula = {"C9H8O4","C8H9NO2","C21H25CIN2O3"};
            manufactureDate = {"30June2023","30July2023","30Aug2023"};
            expiryDate = {"30June2024","30July2024","30Aug2024"};
            retailPrice = {200, 350, 400};
        }
        
        // Setters
        bool isInIndex(int index) {
            if (index >=0 && index<name.size()) {
                return true;
            }
            return false;
        }
        void setName (int index) {
            if (isInIndex(index)) {
                string newName;
                cout<<"Enter new Medicine Name for index "<<index<<": ";
                getline(cin, newName);
                name[index] = newName;
            }
            else {
                cout<<"Invalid index number." << endl;
            }
        }
        void setFormula (int index) {
            if (isInIndex(index)) {
                string newFormula;
                cout<<"Enter new Medicine Formula for index "<<index<<": ";
                getline(cin, newFormula);
                formula[index] = newFormula;
            }
            else {
                cout<<"Invalid index number." << endl;
            }
        }
        void setManuFactureDate (int index) {
            if (isInIndex(index)) {
                string newManufactureDate;
                cout<<"Enter new Medicine ManuFacture Date for index "<<index<<": ";
                getline(cin, newManufactureDate);
                manufactureDate[index] = newManufactureDate;
            }
            else {
                cout<<"Invalid index number." << endl;
            }
        }
        void setExpiryDate (int index) {
            if (isInIndex(index)) {
                string newExpiryDate;
                cout<<"Enter new Medicine Expiry Date for index "<<index<<": ";
                getline(cin, newExpiryDate);
                expiryDate[index] = newExpiryDate;
            }
            else {
                cout<<"Invalid index number." << endl;
            }
        }
        void setRetailPrice (int index) {
            if (isInIndex(index)) {
                int newRetailPrice;
                cout<<"Enter new Medicine Retail Price for index "<<index<<": ";
                cin>>newRetailPrice;
                retailPrice[index] = newRetailPrice;
            }
            else {
                cout<<"Invalid index number." << endl;
            }
        }

        // Getters
        const string getName (int index) {
            return name[index];
        }
        const int getNameSize () {
            return name.size();
        }
        const string getFormula (int index) {
            return formula[index];
        }
        const string getManufactureDate (int index) {
            return manufactureDate[index];
        }
        const string getExpiryDate (int index) {
            return expiryDate[index];
        }
        const int getRetailPrice (int index) {
            return retailPrice[index];
        }
        
        // Display Function for All Medicines
        virtual void displayInfo () {
            for (int i=0; i<name.size(); i++) {
                cout<<"Details for Medicine #" << i+1 << endl;
                cout<<"Name: " << name[i] << endl;
                cout<<"Formula: " << formula[i] << endl;
                cout<<"Manufature Date: " << manufactureDate[i] << endl;
                cout<<"Expiry Date: " << expiryDate[i] << endl;
                cout<<endl;
            }
        }

        // Display Function for a Specified Medicine
        virtual void displayInfo (int index) {
            if (index >=0 && index<name.size()) {
                cout<<"Details for Medicine #" << index+1 << endl;
                cout<<"Name: " << name[index] << endl;
                cout<<"Formula: " << formula[index] << endl;
                cout<<"Manufature Date: " << manufactureDate[index] << endl;
                cout<<"Expiry Date: " << expiryDate[index] << endl;
            }
            else {
                cout<<"Invalid index number. Medicine not found." << endl;
            }
        }

        // Operator Overloading
        bool operator==(Medicine &other) {
            return expiryDate == other.expiryDate;
        }
        
        // Friend Classes
        friend class Pharmacist;
        friend class Counter;

};

class Tablet : public Medicine {
    protected:
        vector <int> sucroseLevel; // 0 to 1
    
    public:
        Tablet () : Medicine () {
            sucroseLevel = {5, 6, 8};
        }

        // Display Function for All Medicines
        void displayInfo () {
            for (int i=0; i<name.size(); i++) {
                cout<<"Details for Tablet #" << i+1 << endl;
                cout<<"Name: " << name[i] << endl;
                cout<<"Formula: " << formula[i] << endl;
                cout<<"Sucrose Level: " << sucroseLevel[i] << endl;
                cout<<"Manufature Date: " << manufactureDate[i] << endl;
                cout<<"Expiry Date: " << expiryDate[i] << endl;
            }
        }

        // Display Function for a specified medicine
        void displayInfo (int index) {
            if (index >=0 && index<name.size()) {
                cout<<"Details for Tablet #" << index+1 << endl;
                cout<<"Name: " << name[index] << endl;
                cout<<"Formula: " << formula[index] << endl;
                cout<<"Sucrose Level: " << sucroseLevel[index] << endl;
                cout<<"Manufature Date: " << manufactureDate[index] << endl;
                cout<<"Expiry Date: " << expiryDate[index] << endl;
            }
            else {
                cout<<"Invalid index number. Tablet not found." << endl;
            }
        }

};

class Capsule : public Medicine {
    protected:
        vector <float> absorptionPercentage; // 1 to 100

    public:
        Capsule () : Medicine () {
            absorptionPercentage = {65.3, 84.4, 87.5};
        }

        // Display Function for a All Medicine
        void displayInfo () {
            for (int i=0; i<name.size(); i++) {
                cout<<"Details for Tablet #" << i+1 << endl;
                cout<<"Name: " << name[i] << endl;
                cout<<"Formula: " << formula[i] << endl;
                cout<<"Absorption Percentage: " << absorptionPercentage[i] << endl;
                cout<<"Manufature Date: " << manufactureDate[i] << endl;
                cout<<"Expiry Date: " << expiryDate[i] << endl;
            }
            cout<<endl;
        }

        // Display Function for a Specific Medicine
        void displayInfo (int index) {
            if (index >=0 && index<name.size()) {
                cout<<"Details for Tablet #" << index+1 << endl;
                cout<<"Name: " << name[index] << endl;
                cout<<"Formula: " << formula[index] << endl;
                cout<<"Absorption Percentage: " << absorptionPercentage[index] << endl;
                cout<<"Manufature Date: " << manufactureDate[index] << endl;
                cout<<"Expiry Date: " << expiryDate[index] << endl;
            }
            else {
                cout<<"Invalid index number. Tablet not found." << endl;
            }
        }
};

class Syrup : public Medicine {
    protected:
        vector <int> quantityML;

    public:
        Syrup () : Medicine () {
            quantityML = {250, 120, 500};
        }

        // Display Function for All Medicines
        void displayInfo () {
            for (int i=0; i<name.size(); i++) {
                cout<<"Details for Tablet #" << i+1 << endl;
                cout<<"Name: " << name[i] << endl;
                cout<<"Formula: " << formula[i] << endl;
                cout<<"Quantity (ML): " << quantityML[i] << endl;
                cout<<"Manufature Date: " << manufactureDate[i] << endl;
                cout<<"Expiry Date: " << expiryDate[i] << endl;
            }
        }

        // Display Function for a Specific Medicine
        void displayInfo (int index) {
            if (index >=0 && index<name.size()) {
                cout<<"Details for Tablet #" << index+1 << endl;
                cout<<"Name: " << name[index] << endl;
                cout<<"Formula: " << formula[index] << endl;
                cout<<"Quantity (ML): " << quantityML[index] << endl;
                cout<<"Manufature Date: " << manufactureDate[index] << endl;
                cout<<"Expiry Date: " << expiryDate[index] << endl;
            }
            else {
                cout<<"Invalid index number. Tablet not found." << endl;
            }
        }
};

class Pharmacist {
    protected:
        Medicine medicine;

    public:
        void searchMedicine () {
            bool found=false;
            string formulaToFind;
            cout<<"Enter the formula of medicine you want to find: ";
            getline(cin, formulaToFind);

            for (int i=0; i<medicine.getNameSize(); i++) {
                if (formulaToFind == medicine.getFormula(i)) {
                    found=true;
                    cout<<"Medicine with formula '" << formulaToFind << "' is found." << endl;
                    cout<<"Medicine Name: " << medicine.getName(i) << endl;
                    cout<<"Medicine Formula: " << medicine.getFormula(i) << endl;
                    cout<<"Medicine Manufature Date: " << medicine.getManufactureDate(i) << endl;
                    cout<<"Medicine Expiry Date: " << medicine.getExpiryDate(i) << endl;
                }
            }
            if (!found) {
                cout<<"Medicine with formula '" << formulaToFind << "' not found." << endl;
            }
        }
        

        int recommendMedicine () {
            int choice;
            cout<<"1. Fever\n2. Headache\n3. Flu\nChoose one from the above list: ";
            choice=get_int();
            cout<<"The counter has noted the syptoms/prescription and it has been forwarded to the pharmacist." << endl;

            switch (choice) {
                case 1:
                    cout<<"The pharmacist has recommended Aspirin for fever to the counter." << endl;
                    return 0;
                    break;
                case 2:
                    cout<<"The pharmacist has recommended Panadol for headache to the counter." << endl;
                    return 1;
                    break;
                case 3:
                    cout<<"The pharmacist has recommended Zyrtec for flu to the counter." << endl;
                    break;
                    return 2;
                default:
                    cout<<"Sorry, we don't have medicines other than for these symptoms." << endl;
                    return 5;
                    break;
            }
            return 5;
        }
};

class Counter {
    protected:
        Medicine medicine;
        Pharmacist pharma;
        vector <string> soldMedicineName;
        int totalRevenue=0;
    public:

        void searchMedicine () {
            bool found=false;
            string medicineToFind;
            cout<<"Enter the name of medicine you want to find: ";
            getline(cin, medicineToFind);

            for (int i=0; i<medicine.getNameSize(); i++) {
                if (medicineToFind == medicine.getName(i)) {
                    found=true;
                    cout<<"Medicine with name '" << medicineToFind << "' is found." << endl;
                    cout<<"Medicine Name: " << medicine.getName(i) << endl;
                    cout<<"Medicine Formula: " << medicine.getFormula(i) << endl;
                    cout<<"Medicine Manufature Date: " << medicine.getManufactureDate(i) << endl;
                    cout<<"Medicine Expiry Date: " << medicine.getExpiryDate(i) << endl;
                }
            }
            if (!found) {
                cout<<"Medicine with name '" << medicineToFind << "' not found." << endl;
            }
        }

        void updateRevenue (int indexToBuy) {
            totalRevenue += medicine.getRetailPrice(indexToBuy);
        }

        void sellMedicine () {
            // medicine.displayInfo();
            bool flag = true;
            int numToBuy, indexToBuy;
            indexToBuy = pharma.recommendMedicine();
            cin.ignore();

            if (indexToBuy==5) {
                flag = false;
            }
            // cout<<"Enter the number of medicine from the list that you want to buy: ";
            // cin>>numToBuy;
            
            // indexToBuy = numToBuy-1;
            if (flag) {
                if (medicine.isInIndex(indexToBuy)) {
                    updateRevenue(indexToBuy);
                    cout<<"The counter has sold '" << medicine.getName(indexToBuy) << "' for Rs "<<medicine.getRetailPrice(indexToBuy)<<" to the customer." << endl;
                    soldMedicineName.push_back(medicine.getName(indexToBuy));
                    cout<<"The total revenue of today is now Rs " << totalRevenue <<"." << endl;
                }
                else {
                    cout<<"Invalid index number." << endl;
                }
            }
        }
};
// int Counter::totalRevenue=0;

int main() {
    
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"Name: Muhammad Hammad" << endl;
    cout<<"Roll No: 23K-2005" << endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;

    Medicine m1;
    Medicine m2;
    Pharmacist p1;
    Counter c1;

    c1.sellMedicine();

    cout<<endl<<"------- Operator Overloading -------" << endl;
    if (m1 == m2) {
        cout<<"The two medicines have the same expiry date." << endl << endl;
    } else {
        cout<<"The two medicines do not have the same expiry date." << endl<< endl;
    }

    /*
    As required in the question, the counter collects the prescription from the customer.
    Counter then forwards the prescription to Pharmacist and Pharmacist suggests a medicine based on the prescription.
    The Counter then sells the medicine recommended by the Pharmacist and collects the money.
    Once the medicine is sold and payment is received, the total Revenue is updated.
    */

    // p1.searchMedicine(); -- Working fine
    // c1.searchMedicine(); -- Working fine

    return 0;
}