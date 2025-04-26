#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

class PoliceDept {
    protected:
        int totalRecords=0;
        static int PRid;
        ifstream Record_in;
        ofstream Record_out;

    public:
        PoliceDept() {}

        void viewPersonnelRecord() {
            if (totalRecords==0) {
                cout<<"\nThere is no personnel record in database." << endl;
            }
        	string nameFromFile, PRidFromFile,DepartmentFromFile, rankFromFile, salaryFromFile;
            for (int i = 1; i <= totalRecords; i++) {
            	string fileName = "Record" + to_string(i) + ".txt";
                Record_in.open(fileName);
                // if (!Record_in) {
                //     cout<<"Error opening file: " << fileName << endl;
                //     continue;
                // }
            	getline(Record_in, nameFromFile);
                getline(Record_in, PRidFromFile);
                getline(Record_in, DepartmentFromFile);
                getline(Record_in, rankFromFile);
                getline(Record_in, salaryFromFile);
                cout<<"\n\tAuthorized Personnel " << i << ": " << endl;
                cout<<"Full Name: " <<nameFromFile<< endl;
                cout<<"Personnel ID: " <<PRidFromFile<< endl;
                cout<<"Department: " <<DepartmentFromFile<< endl;
                cout<<"Rank: " <<rankFromFile<< endl;
                cout<<"Salary: " <<salaryFromFile<< endl;
                Record_in.close();
                Record_in.clear();
            }
        }
        
        void addPersonnelRecord() {
            int numStaff;
            cout<<"\nHow many Personnel Staff(s) do you want to add: ";
            numStaff = get_int();
            cin.ignore();

            for (int i=0; i<numStaff; i++) {
                string fullName, department, rank, salary;
                cout << "Enter Full Name of Personnel " << i + 1 << ": ";
                getline(cin, fullName);
                cout << "Enter Department of Personnel " << i + 1 << ": ";
                getline(cin, department);
                cout << "Enter Rank of Personnel " << i + 1 << ": ";
                getline(cin, rank);
                cout << "Enter Salary of Personnel " << i + 1 << ": ";
                getline(cin, salary);
                
                PRid=totalRecords+1;
                totalRecords++;
                string fileName = "Record" + to_string(PRid) + ".txt";
                Record_out.open(fileName);
                Record_out<<fullName<<endl;
                Record_out<<PRid<<endl;
                Record_out<<department<<endl;
                Record_out<<rank<<endl;
                Record_out<<salary<<endl;
                Record_out.close();
                cout<<"Personnel Record with '"<<fullName<<"' added with Personnel ID: "<<PRid<<endl;
                cout<<endl;
            }
		}

        void searchPersonnelRecord() {
            string nameToFind,nameFromFile, PRidFromFile,DepartmentFromFile, rankFromFile, salaryFromFile;
            bool found = false;
            cout<<"\nEnter the name of Personnel you want to find: ";
            getline(cin, nameToFind);
            
            for (int i=1; i<=totalRecords; i++) {
                string fileName = "Record" + to_string(i) + ".txt";
                Record_in.open(fileName);
                getline(Record_in, nameFromFile);

                if (nameToFind == nameFromFile) {
                    found = true;
                    getline(Record_in, PRidFromFile);
                    getline(Record_in, DepartmentFromFile);
                    getline(Record_in, rankFromFile);
                    getline(Record_in, salaryFromFile);
                    cout<<"\tPersonnel " << i << ": " << endl;
                    cout<<"Full Name: " <<nameFromFile<< endl;
                    cout<<"Personnel ID: " <<PRidFromFile<< endl;
                    cout<<"Department: " <<DepartmentFromFile<< endl;
                    cout<<"Rank: " <<rankFromFile<< endl;
                    cout<<"Salary: " <<salaryFromFile<< endl;
                }
                Record_in.close();
                Record_in.clear();
            }
            if (!found) {
                cout<<"Personnel with name '" << nameToFind << "' not found." << endl;
            }
        }

        void removePersonnelRecord() {
		    char choice;
            cout<<"\nDo you want to view all Personnel Records first before removing? (y/n): ";
            cin>> choice;
            if (choice == 'Y' || choice == 'y') {
                viewPersonnelRecord();
            }
            else if (choice=='N' || choice == 'n') {
                cout<<"You have skipped viewing the list of authorized personnels." << endl;
            }
            else {
                cout<< "Invalid input. ";
                tryAgainPersonnel("remove");
                return;
            }

            int numToRemove;
            cout << "Enter the chronological number of Personnel Record you want to remove: ";
            numToRemove = get_int();

            if (numToRemove >= 1 && numToRemove <= totalRecords) {
                string fileName = "Record" + to_string(numToRemove) + ".txt";
                if (remove(fileName.c_str()) != 0) {
                    cout << "Error deleting file: " << fileName << endl;
                } else {
                    cout << "Personnel Record file " << fileName << " has been removed successfully." << endl;
                }
                for (int i = numToRemove + 1; i <= totalRecords; i++) {
                    string oldFileName = "Record" + to_string(i) + ".txt";
                    string newFileName = "Record" + to_string(i - 1) + ".txt";
                    if (rename(oldFileName.c_str(), newFileName.c_str()) != 0) {
                        cout<<"Error renaming file: " << oldFileName << endl;
                    }
                }
                totalRecords--;
            }
            else {
                cout<<"Invalid Personnel Record number. No Personnel Record removed." << endl;
            }
        }
	
        void tryAgainPersonnel(string condition) {
            char choice;
            cout << "\nDo you want to try again? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                if (condition == "remove") {
                    removePersonnelRecord();
                }
            }
            else if (choice == 'n' || choice == 'N') {
                cout << "You have prevented yourself from ";
                if (condition == "remove") {
                    cout << "removing a personnel record." << endl;
                }
            }
            else {
                cout << "Invalid input. ";
                tryAgainPersonnel(condition);
            }
        }
};
int PoliceDept::PRid=0;

class FIR : public PoliceDept {
    protected:
        int totalFirs=0;
        static int FirID;
        vector<vector<string>> FIR;
        ifstream FIR_in;
        ofstream FIR_out;
    public:
        void viewFIR() {
            string nameToFind, nameFromFile, registeredByFromFile, reasonFromFile, FirIDFromFile;
            
            if (totalFirs==0) {
                cout<<"\nThere is no FIRs registered in the database." << endl;
            }

            for (int i = 1; i <= totalFirs; i++) {
                string fileName = "FIR" + to_string(i) + ".txt";
                FIR_in.open(fileName);
                getline(FIR_in, nameFromFile);
                getline(FIR_in, FirIDFromFile );
                getline(FIR_in, registeredByFromFile);
                getline(FIR_in, reasonFromFile);
                cout<<"\n\tData for FIR " << i << endl;
                cout<<"Name: " << nameFromFile << endl;
                cout<<"Registered By: " << registeredByFromFile << endl;
                cout<<"FIR ID: " << FirIDFromFile << endl;
                cout<<"Reason: " << reasonFromFile << endl;
                FIR_in.close();
                FIR_in.clear();
                FIR_in.seekg(0, ios::beg);
            }
        }
        
        
        void addFIR () { // For Police
			int numAddFir;
			cout<<"\nHow many FIR(s) do you want add: ";
			numAddFir = get_int();
            cin.ignore();

			for (int i=0; i<numAddFir; i++) {
				string person, registeredBy, reason;
				cout<<"Enter name of the person for FIR #" << i + 1 << ": ";
				getline(cin, person);
                cout<<"Enter name of the registerer for FIR #" << i + 1 << ": ";
				getline(cin, registeredBy);
				cout<<"Enter reason for FIR #" << i + 1 << ": ";
				getline(cin, reason);
                
                FirID = totalFirs+1;
                totalFirs++;
                string fileName = "FIR" + to_string(FirID) + ".txt";
                FIR_out.open(fileName);
                FIR_out<< person<< endl;
                FIR_out<< FirID<< endl;
                FIR_out<< registeredBy<< endl;
                FIR_out<< reason<< endl;
                FIR_out.close();
                cout<<"FIR added against '" << person << "' with FIR ID: " << FirID << endl;
                cout<<endl;
            }
		}

        void searchFIR() {
            string nameToFind, nameFromFile, registeredByFromFile, reasonFromFile, FirIDFromFile;
            bool found = false;
            cout << "\nEnter the name of FIR you want to find: ";
            getline(cin, nameToFind);

            for (int i = 0; i < totalFirs; i++) {
                string fileName = "FIR" + to_string(i+1) + ".txt";
                FIR_in.open(fileName);
                getline(FIR_in, nameFromFile);
                
                if (nameToFind==nameFromFile) {
                    found=true;
                    getline(FIR_in,registeredByFromFile);
                    getline(FIR_in,FirIDFromFile);
                    getline(FIR_in, reasonFromFile);
                    cout<<"Name: " << nameFromFile << endl;
                    cout<<"Registered By: " << registeredByFromFile << endl;
                    cout<<"FIR ID: " << FirIDFromFile << endl;
                    cout<<"Reason: " << reasonFromFile << endl;
                }
                FIR_in.close();
                FIR_in.clear();
            }
            if (!found) {
                cout << "FIR for person '" << nameToFind << "' not found." << endl;
            }
        }

        void removeFIR() {
            char choice;
            cout << "\nDo you want to view all FIRs first before removing? (y/n): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                viewFIR();
            }
            else if (choice=='N' || choice == 'n') {
                cout<<"You have skipped viewing the list of all FIRs." << endl;
            }
            else {
                cout << "Invalid input. "<<endl;
                tryAgainFIR("remove");
            }

            int numToRemove;
            cout << "Enter the chronological number of FIR you want to remove: ";
            numToRemove = get_int();

            
            if (numToRemove >= 1 && numToRemove <= totalFirs) {
                string fileName = "fir" + to_string(numToRemove) + ".txt";
                if (remove(fileName.c_str()) != 0) {
                    cout << "Error deleting file: " << fileName << endl;
                } else {
                    cout << "FIR file " << fileName << " has been removed successfully." << endl;
                }
                for (int i = numToRemove + 1; i <= totalFirs; i++) {
                string oldFileName = "FIR" + to_string(i) + ".txt";
                string newFileName = "FIR" + to_string(i - 1) + ".txt";
                if (rename(oldFileName.c_str(), newFileName.c_str()) != 0) {
                    cout << "Error renaming file: " << oldFileName << endl;
                }
            }
            totalFirs--;

            }
            else {
                cout<<"Invalid FIR number. No FIR removed." << endl;
            }
        }
        void tryAgainFIR(string condition) {
            char choice;
            cout << "\nDo you want to try again? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                if (condition == "remove") {
                    removeFIR();
                }
            }
            else if (choice == 'n' || choice == 'N') {
                cout << "You have prevented yourself from ";
                if (condition == "remove") {
                    cout << "removing an FIR." << endl;
                }
            }
            else {
                cout << "Invalid input. ";
                tryAgainFIR(condition);
            }
        }
};

int FIR::FirID=0;

class Criminal : public PoliceDept {
    protected:
        int totalCriminals=0;
        static int CriminalID;
        vector<vector<string>> Criminal;
        ifstream Criminal_in;
        ofstream Criminal_out;
    public:
        void viewCriminal() {
            string nameToFind, criminalNameFromFile, isArrestedFromFile, crimesFromFile, CriminalIDFromFile;
            
            if (totalCriminals==0) {
                cout<<"\nThere are no Criminals registered in the MDC Database." << endl;
            }

            for (int i = 1; i <= totalCriminals; i++) {
                string fileName = "Criminal" + to_string(i) + ".txt";
                Criminal_in.open(fileName);
                getline(Criminal_in, criminalNameFromFile);
                getline(Criminal_in, CriminalIDFromFile );
                getline(Criminal_in, crimesFromFile);
                getline(Criminal_in, isArrestedFromFile);
                cout<<"\n\tData for Criminal " << i << endl;
                cout<<"Criminal Name: " << criminalNameFromFile << endl;
                cout<<"Criminal ID: " << CriminalIDFromFile << endl;
                cout<<"Crimes Committed: " << crimesFromFile << endl;
                cout<<"Arrest status: " << isArrestedFromFile << endl;
                Criminal_in.close();
                Criminal_in.clear();
                Criminal_in.seekg(0, ios::beg);
            }
        }
        
        
        void addCriminal () { // For Police
			int numAddCriminal;
			cout<<"\nHow many Criminal(s) do you want add: ";
			numAddCriminal = get_int();
            cin.ignore();

			for (int i=0; i<numAddCriminal; i++) {
				string criminalName, isArrested, crimes;
				cout<<"Enter name of Criminal #" << i + 1 << ": ";
				getline(cin, criminalName);
                cout<<"Enter crimes for Criminal #" << i + 1 << ": ";
				getline(cin, crimes);
                cout<<"Enter status if Criminal #"<< i + 1 <<" is arrested or not: ";
				getline(cin, isArrested);
				                
                CriminalID = totalCriminals+1;
                totalCriminals++;
                string fileName = "Criminal" + to_string(CriminalID) + ".txt";
                Criminal_out.open(fileName);
                Criminal_out<< criminalName<< endl;
                Criminal_out<< CriminalID<< endl;
                Criminal_out<< crimes<< endl;
                Criminal_out<< isArrested<< endl;
                Criminal_out.close();
                cout<<"Criminal '" << criminalName << "' is added to MDC database with Criminal ID: " << CriminalID << endl;
                cout<<endl;
            }
		}

        void searchCriminal() {
            string nameToFind, criminalNameFromFile, isArrestedFromFile, crimesFromFile, CriminalIDFromFile;
            bool found = false;
            cout << "\nEnter the name of Criminal you want to find: ";
            getline(cin, nameToFind);

            for (int i = 0; i < totalCriminals; i++) {
                string fileName = "Criminal" + to_string(i+1) + ".txt";
                Criminal_in.open(fileName);
                getline(Criminal_in, criminalNameFromFile);
                
                if (nameToFind==criminalNameFromFile) {
                    found=true;
                    getline(Criminal_in,CriminalIDFromFile);
                    getline(Criminal_in, crimesFromFile);
                    getline(Criminal_in,isArrestedFromFile);
                    cout<<"\n\tResult Found" << endl;
                    cout<<"Criminal Name: " << criminalNameFromFile << endl;
                    cout<<"Registered By: " << isArrestedFromFile << endl;
                    cout<<"Criminal ID: " << CriminalIDFromFile << endl;
                    cout<<"Crimes Committed: " << crimesFromFile << endl;
                }
                Criminal_in.close();
                Criminal_in.clear();
            }
            if (!found) {
                cout << "Criminal '" << nameToFind << "' not found in the MDC Database." << endl;
            }
        }

       
        void removeCriminal() {
            char choice;
            cout << "\nDo you want to view the list of Criminals first before removing? (y/n): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                viewCriminal();
            }
            else if (choice=='N' || choice == 'n') {
                cout<<"You have skipped viewing the list of all Criminals." << endl;
            }
            else {
                cout << "Invalid input. "<<endl;
                tryAgainCriminal("remove");
            }

            int numToRemove;
            cout << "Enter the chronological number of Criminal you want to remove: ";
            numToRemove = get_int();

            
            if (numToRemove >= 1 && numToRemove <= totalCriminals) {
                string fileName = "Criminal" + to_string(numToRemove) + ".txt";
                if (remove(fileName.c_str()) != 0) {
                    cout << "Error deleting file: " << fileName << endl;
                } else {
                    cout << "Criminal file " << fileName << " has been removed successfully." << endl;
                }
                for (int i = numToRemove + 1; i <= totalCriminals; i++) {
                string oldFileName = "Criminal" + to_string(i) + ".txt";
                string newFileName = "Criminal" + to_string(i - 1) + ".txt";
                if (rename(oldFileName.c_str(), newFileName.c_str()) != 0) {
                    cout << "Error renaming file: " << oldFileName << endl;
                }
            }
            
            totalCriminals--;
            }
            else {
                cout<<"Invalid Criminal number. No Criminal removed." << endl;
            }
        }
        void tryAgainCriminal(string condition) {
            char choice;
            cout << "\nDo you want to try again? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                if (condition == "remove") {
                    removeCriminal();
                }
            }
            else if (choice == 'n' || choice == 'N') {
                cout << "You have prevented yourself from ";
                if (condition == "remove") {
                    cout << "removing a Criminal." << endl;
                }
            }
            else {
                cout << "Invalid input. ";
                tryAgainCriminal(condition);
            }
        }
        
};

int Criminal::CriminalID=0;


class LostItems : public PoliceDept {
	protected:
			vector<vector<string>> lostItems;
		 int totalLostItems = 0;
		 static int LostitemID;
		  ifstream lost_in;
		   ofstream lost_out; 
	public:
		void viewLostItems() {
            if (totalLostItems==0) {
                cout<<"\nThere are no lost items registered in the database." << endl;
            }
        	string itemName, description, itemID, reportedBy, location;
            for (int i=1; i<=totalLostItems; i++) {
                string fileName = "LostItem" + to_string(i) + ".txt";
                lost_in.open(fileName);
                getline(lost_in, itemName);
                getline(lost_in, description);
                getline(lost_in, itemID);
                getline(lost_in, reportedBy);
                getline(lost_in, location);
                cout<<"\n\tItem #"<<i<<":"<<endl;
                cout<<"Item Name: " << itemName << endl;
                cout<<"Description of the item: " << description << endl;
                cout<<"Item ID: " <<itemID  << endl;
                cout<<"Reported by: " << reportedBy << endl;
                cout<<"Location where lost: " << location << endl;
                lost_in.close();
                lost_in.clear();
                lost_in.seekg(0, ios::beg);
                cout<<endl;
            }
        }
		
	    void addLostItem() {
            int numItems;
            cout<< "\nHow many Lost item(s) do you want to add: ";
            numItems = get_int();
            cin.ignore();

            for (int i=0; i<numItems; i++) {
                string itemName, description, location, reportedBy;
                cout<<"Enter item name for lost item: " << i + 1 << ": ";
                getline(cin, itemName);
                cout<<"Enter description for lost item: " << i + 1 << ": ";
                getline(cin, description);
                cout<<"Enter the name of the submitter: ";
                getline(cin, reportedBy);
                cout<<"Enter location where the item was lost: ";
                getline(cin, location);
        
                LostitemID=totalLostItems+1;
                totalLostItems++;
                string fileName = "LostItem" + to_string(LostitemID) + ".txt";
                lost_out.open(fileName);
                lost_out<<itemName<<endl;
                lost_out<<description<<endl;
                lost_out<<LostitemID<<endl;
                lost_out<<reportedBy<<endl;
                lost_out<<location<<endl;
                lost_out.close();
                cout<<"Lost item a" << itemName << "a added successfully with ID: " << LostitemID << endl;
                cout<<endl;
            }
        }

		void searchLostItems() {
		   string itemToFind, itemNameFromFile, descriptionFromFile, itemIDFromFile, submitterFromFile, locationFromFile;
            bool found = false;
            cout<< "\nEnter the name of the found item you want to search: ";
            getline(cin, itemToFind);

            for (int i=0; i<totalLostItems; i++) {
                string fileName = "LostItem" + to_string(i+1) + ".txt";
                lost_in.open(fileName);
                getline(lost_in, itemNameFromFile);
                if (itemToFind==itemNameFromFile) {
                    found=true;
                    getline(lost_in,descriptionFromFile);
                    getline(lost_in,itemIDFromFile);
                    getline(lost_in,submitterFromFile);
                    getline(lost_in, locationFromFile);
                    cout<<"\tResult matched"<<endl;
                    cout<<"Item: " << itemNameFromFile << endl;
                    cout<<"Description of the item: " << descriptionFromFile << endl;
                    cout<<"Item ID: " << itemIDFromFile << endl;
                    cout<<"Reported By: " << submitterFromFile << endl;
                    cout<<"Location where lost: " << locationFromFile << endl;
                }
                lost_in.close();
            }
            if (!found) {
            cout<<"Item '" << itemToFind << "' not found." << endl;
            }
		}

		void removeLostItem() {
		    char choice;
            cout<< "\nDo you want to view all lost items first before removing? (y/n): ";
            cin>> choice;
            if (choice == 'Y' || choice == 'y') {
                viewLostItems();
            }
            else if (choice=='N' || choice == 'n') {
                cout<<"You have skipped viewing the list of lost items." << endl;
            }
            else {
                cout<< "Invalid input. ";
                tryAgainLostItems("remove");
            }

            int numToRemove;
            cout<< "Enter the chronological number of the lost item you want to remove: ";
            numToRemove = get_int();

            if (numToRemove >= 1 && numToRemove <= totalLostItems) {
                string fileName = "LostItem" + to_string(numToRemove) + ".txt";
                if (remove(fileName.c_str()) != 0) {
                    cout << "Error deleting file: " << fileName << endl;
                } else {
                    cout << "Lost item file " << fileName << " has been removed successfully." << endl;
                }
                for (int i = numToRemove + 1; i <= totalLostItems; i++) {
                    string oldFileName = "LostItem" + to_string(i) + ".txt";
                    string newFileName = "LostItem" + to_string(i - 1) + ".txt";
                    if (rename(oldFileName.c_str(), newFileName.c_str()) != 0) {
                        cout << "Error renaming file: " << oldFileName << endl;
                    }
                }
                totalLostItems--;
            } else {
                cout<<"Invalid lost item number. No item removed." << endl;
            }
		}

		void tryAgainLostItems(string condition) {
			char choice;
			cout<<"\nDo you want to try again? (y/n): ";
			cin>>choice;

			if (choice == 'y' || choice == 'Y') {
				if (condition == "remove") {
					removeLostItem();
				}
			} else if (choice == 'n' || choice == 'N') {
				cout<< "You have prevented yourself from ";
				if (condition == "remove") {
					cout<< "removing a Lost Item." << endl;
				}
			} else {
				cout<<"Invalid input. ";
				tryAgainLostItems(condition);
			}
		}
};
int LostItems :: LostitemID=0;

class FoundItems : public PoliceDept {
	protected:
		vector<vector<string>> foundItems;  
		int totalFoundItems = 0;
		static int FounditemID;
		ifstream found_in;
		ofstream found_out;
		 
	public:
    	void viewFoundItems() {
            if (totalFoundItems==0) {
                cout<<"\nThere are no found items registered in the database." << endl;
            }
        	string itemName, description, itemID, submittedBy, location;
            for (int i = 1; i <= totalFoundItems; i++) {
                string fileName = "FoundItem" + to_string(i) + ".txt";
                found_in.open(fileName);
                getline(found_in, itemName);
                getline(found_in, description);
                getline(found_in, itemID);
                getline(found_in, submittedBy);
                getline(found_in, location);
                cout<<"\n\tItem #"<<i<<":"<<endl;
                cout<<"Item Name: " << itemName << endl;
                cout<<"Description of the item: " << description << endl;
                cout<<"Item ID: " <<itemID  << endl;
                cout<<"Submitted By: " << submittedBy << endl;
                cout<<"Location: " << location << endl;
                found_in.close();
                found_in.clear();
                found_in.seekg(0, ios::beg);
                cout<<endl;
            }
        }

        void addFoundItem() {
            int numItems;
            cout<<"\nHow many Found item(s) do you want to add: ";
            numItems = get_int();;
            cin.ignore();

            for (int i = 0; i < numItems; i++) {
                string itemName, description, location, submittedBy;
                cout<<"Enter item name for found item: " << i + 1 << ": ";
                getline(cin, itemName);
                cout<<"Enter description for found item: " << i + 1 << ": ";
                getline(cin, description);
                cout<<"Enter the name of the submitter: ";
                getline(cin, submittedBy);
                cout<<"Enter location where the item was found: ";
                getline(cin, location);
        
                FounditemID=totalFoundItems+1;
                totalFoundItems++;
                string fileName = "FoundItem" + to_string(FounditemID) + ".txt";
                found_out.open(fileName);
                found_out<<itemName<<endl;
                found_out<<description<<endl;
                found_out<<FounditemID<<endl;
                found_out<<submittedBy<<endl;
                found_out<<location<<endl;
                found_out.close();
                cout<<"Found item a" << itemName << "a added successfully with ID: " << FounditemID << endl;
                cout<<endl;
            }
        }

		void searchFoundItems() {
		   string itemToFind, itemNameFromFile, descriptionFromFile, itemIDFromFile, submitterFromFile, locationFromFile;
            bool found = false;
            cout<< "\nEnter the name of the found item you want to search: ";
            getline(cin, itemToFind);

            for (int i=0; i<totalFoundItems; i++) {
                string fileName = "FoundItem" + to_string(i+1) + ".txt";
                found_in.open(fileName);
                getline(found_in, itemNameFromFile);
                if (itemToFind==itemNameFromFile) {
                    found=true;
                    getline(found_in,descriptionFromFile);
                    getline(found_in,itemIDFromFile);
                    getline(found_in,submitterFromFile);
                    getline(found_in, locationFromFile);
                    cout<<"\tResult matched"<<endl;
                    cout<<"Item: " << itemNameFromFile << endl;
                    cout<<"Description of the item: " << descriptionFromFile << endl;
                    cout<<"Item ID: " << itemIDFromFile << endl;
                    cout<<"Submitted By: " << submitterFromFile << endl;
                    cout<<"Location where found: " << locationFromFile << endl;
                }
                found_in.close();
            }
            if (!found) {
            cout<<"Item '" << itemToFind << "' not found." << endl;
            }
		}

        void removeFoundItem(int fileNum) {
            if (fileNum>=1 && fileNum<=totalFoundItems) {
                string fileName = "FoundItem" + to_string(fileNum) + ".txt";
                if (remove(fileName.c_str()) != 0) {
                        cout<<"\nError deleting file: " << fileName << endl;
                } else {
                        cout<<"\nFound item file " << fileName << " has been removed successfully." << endl;
                    }
                    for (int i = fileNum + 1; i <= totalFoundItems; i++) {
                        string oldFileName = "FoundItem" + to_string(i) + ".txt";
                        string newFileName = "FoundItem" + to_string(i - 1) + ".txt";
                        if (rename(oldFileName.c_str(), newFileName.c_str()) != 0) {
                            cout << "Error renaming file: " << oldFileName << endl;
                        }
                    }
                    totalFoundItems--;
            } else {
                cout<<"Invalid found item number. No item removed." << endl;
            }
        }

		void removeFoundItem() {
			char choice;
            cout << "\nDo you want to view all found items first before removing? (y/n): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                viewFoundItems();
            } 
            else if (choice=='N' || choice == 'n') {
                cout<<"You have skipped viewing the list of found items." << endl;
            }
            else {
                cout << "Invalid input. ";
                tryAgainFoundItems("remove");
            }

            int numToRemove;
            cout << "Enter the chronological number of the found item you want to remove: ";
            numToRemove = get_int();

            if (numToRemove>=1 && numToRemove<=totalFoundItems) {
                string fileName = "FoundItem" + to_string(numToRemove) + ".txt";
                if (remove(fileName.c_str()) != 0) {
                    cout<<"Error deleting file: " << fileName << endl;
                } else {
                    cout<<"Found item file " << fileName << " has been removed successfully." << endl;
                }
                for (int i = numToRemove + 1; i <= totalFoundItems; i++) {
                    string oldFileName = "FoundItem" + to_string(i) + ".txt";
                    string newFileName = "FoundItem" + to_string(i - 1) + ".txt";
                    if (rename(oldFileName.c_str(), newFileName.c_str()) != 0) {
                        cout << "Error renaming file: " << oldFileName << endl;
                    }
                }
                totalFoundItems--;
            } else {
                cout<<"Invalid found item number. No item removed." << endl;
            }
		}

		void tryAgainFoundItems(string condition) {
			char choice;
			cout<<"\nDo you want to try again? (y/n): ";
			cin>>choice;

			if (choice == 'y' || choice == 'Y') {
				if (condition == "remove") {
					removeFoundItem();
				}
			} else if (choice == 'n' || choice == 'N') {
				cout<< "You have prevented yourself from ";
				if (condition == "remove") {
					cout<< "removing a found Item." << endl;
				}
			} else {
				cout<<"Invalid input. ";
				tryAgainFoundItems(condition);
			}
		}
};
int FoundItems :: FounditemID=0;

class Login {
    protected:
        int totalAdmins = 3; // We are assuming there are 3 Admin acounts
        int loginChoice;
        string nameEntered, passwordEntered, cnicEntered;
        string nameFromFile, passwordFromFile, cnicFromFile;
        ifstream in;
        ofstream out;
        bool loginSuccess = false;
    public:
        bool loginAdmin () {
            cout<<"Enter admin account name: ";
            getline(cin, nameEntered);
            cout<<"Enter password: ";
            getline(cin, passwordEntered);

            for (int adminID=1; adminID<=totalAdmins; adminID++) {
                string fileName = "adminData" + to_string(adminID) + ".txt";
                in.open(fileName);
                getline(in, nameFromFile);
                getline(in, passwordFromFile);
                if (nameEntered==nameFromFile && passwordEntered==passwordFromFile) {
                    loginSuccess = true;
                    cout<<"Login Successful." << endl;
                    cout<<"Welcome to the Official Admin Portal of the Police Department!" << endl;
                    break;
                }
            }
            if (!loginSuccess) {
                cout<<"Login failed. Credientials did not match." << endl;
            }
            in.close();
            return loginSuccess;
        }

        void createAccount () {
            cout<<"Enter new admin name: ";
            getline(cin, nameEntered);
            cout<<"Enter a strong password: ";
            getline(cin, passwordEntered);

            int newAdminID = totalAdmins + 1;
            string fileName = "adminData" + to_string(newAdminID) + ".txt";

            out.open(fileName);
            out<< nameEntered<< endl;
            out<< passwordEntered<< endl;
            out.close();
            cout<<"Account created successfully! Admin ID: " << newAdminID << endl;
        }     

        void welcomeMsg () {
            cout<<"\t\t\t======================================"<<endl;
            cout<<"\t\t\t Welcome to Virtual Police Department"<<endl;
            cout<<"\t\t\t======================================"<<endl;
        }

        int mainMenu () {
            int choice;
            cout<<"\nSelect what you want to manage: "<<endl;
            cout<<"1. Personal Records."<<endl;
            cout<<"2. FIR."<<endl;
            cout<<"3. Criminal Record."<<endl;
            cout<<"4. Lost Items."<<endl;
            cout<<"5. Found Items."<<endl;
            cout<<"6. Exit."<<endl;
            cout<<"Enter your Choice: ";
            choice= get_int();
            cin.ignore();
            return choice;
        }

        int firMenu () {
            int choice;
            cout<<"\n1. View FIR."<<endl;
			cout<<"2. Add FIR."<<endl;
			cout<<"3. Search FIR"<<endl;
			cout<<"4. Remove FIR"<<endl;
            cout<<"5. Go back"<<endl;
			cout<<"6. Exit Program."<<endl;
			cout<<"Enter your Choice: ";
			choice= get_int();
            cin.ignore();
            return choice;
        }

        int PRMenu () {
            int choice;
            cout<<"\n1. View Personal Record."<<endl;
			cout<<"2. Add Personal Record."<<endl;
			cout<<"3. Search Personal Record."<<endl;
			cout<<"4. Remove Personal Record."<<endl;
			cout<<"5. Go back"<<endl;
			cout<<"6. Exit Program."<<endl;
			cout<<"Enter your Choice: ";
			choice =get_int();
            cin.ignore();
            return choice;
        }
         
        int lostMenu (){
        	int choice;
        	cout<<"\n1. View Lost Items."<<endl;
			cout<<"2. Add Lost Items."<<endl;
			cout<<"3. Search Lost Items."<<endl;
			cout<<"4. Remove Lost Items."<<endl;
			cout<<"5. Go back"<<endl;
			cout<<"6. Exit Program."<<endl;
			cout<<"Enter your Choice: ";
			choice= get_int();
            cin.ignore();
            return choice;
		}
		
		int foundMenu (){
			int choice;
        	cout<<"\n1. View Found Items."<<endl;
			cout<<"2. Add Found Items."<<endl;
			cout<<"3. Search Found Items."<<endl;
			cout<<"4. Remove Found Items."<<endl;
			cout<<"5. Go back"<<endl;
			cout<<"6. Exit Program."<<endl;
			cout<<"Enter your Choice: ";
			choice= get_int();
            cin.ignore();
            return choice;
		}

        int CriminalMenu () {
            int choice;
            cout<<"\n1. View Criminal."<<endl;
			cout<<"2. Add Criminal."<<endl;
			cout<<"3. Search Criminal"<<endl;
			cout<<"4. Remove Criminal"<<endl;
            cout<<"5. Go back"<<endl;
			cout<<"6. Exit Program."<<endl;
			cout<<"Enter your Choice: ";
			choice= get_int();
            cin.ignore();
            return choice;
        }
		 
        void simulation(PoliceDept &o1, FIR &o2, Criminal &o3, LostItems &o4, FoundItems &o5) {
            int choiceLogin;
            cout<<"1. Log in to your account.\n2. Create an account\nChoose from (1-2): ";
            choiceLogin = get_int();
            cin.ignore();

            if (choiceLogin==1) {
                do {
                loginSuccess = loginAdmin();
                if (loginSuccess) {
                    break;
                }
                if (!loginSuccess) {
                    cout<< "Would you like to exit the program? (Y/N): ";
                    char choice;
                    cin>> choice;
                    if (choice == 'Y' || choice == 'y') {
                        cout << "Exiting the program..." << endl;
                        exit(1);
                    }
                    cin.ignore();
                }
            } while (!loginSuccess);
            }
            else if (choiceLogin==2) {
                createAccount();
                // add code for create account
            }
            else {
                cout<<"Invalid input. Selection can only be from 1-2" << endl;
            }
            
            int choice;
            do {
                choice = mainMenu();
                switch (choice) {
                    case 1: // Personnel Record
                        int choicePR;
                        do {
                            choicePR = PRMenu();
                            switch (choicePR) {
                                case 1:
						  			o1.viewPersonnelRecord();
						  			break;
						  		case 2:
						  			o1.addPersonnelRecord();
						  			break;
						  		case 3:
						  			o1.searchPersonnelRecord();
						  			break;
						  		case 4:
						  			o1.removePersonnelRecord();
						  			break;
                                case 5:
                                    break;
						  		case 6:
						  			cout<<"Exiting the program...";
                                    exit(1);
						  			break;
						  		default:
						  			cout<<"Invalid choice. Please choose from (1-6)";
						  			break;
                            }
                        } while (choicePR != 5);
                        break;
                    case 2: // FIR
                        int choiceFIR;
                        do {
                            choiceFIR = firMenu();
                            switch (choiceFIR) {
                                case 1:
						  		    o2.viewFIR();
						  		    break;
                                case 2:
                                    o2.addFIR();
                                    break;
                                case 3:
                                    o2.searchFIR();
                                    break;
                                case 4:
                                    o2.removeFIR();
                                    break;
                                case 5:
                                    break;
						  		case 6:
						  			cout<<"Exiting the program...";
                                    exit(1);
						  			break;
                                default:
                                    cout<<"Invalid choice. Please choose from (1-6)";
                                    break;
						    }
                        } while (choiceFIR != 5);
                        break;
                    case 3: // Criminal
                        int choiceCriminal;
                        do {
                            choiceCriminal = CriminalMenu();
                            switch (choiceCriminal) {
                                case 1:
						  		    o3.viewCriminal();
						  		    break;
                                case 2:
                                    o3.addCriminal();
                                    break;
                                case 3:
                                    o3.searchCriminal();
                                    break;
                                case 4:
                                    o3.removeCriminal();
                                    break;
                                case 5:
                                    break;
						  		case 6:
						  			cout<<"Exiting the program...";
                                    exit(1);
						  			break;
                                default:
                                    cout<<"Invalid choice. Please choose from (1-6)";
                                    break;
						    }
                        } while (choiceCriminal != 5);
                        break;
                    case 4: // Lostitems
                        int choiceLost;
                        do {
                            choiceLost = lostMenu();
                            switch (choiceLost) {
                                case 1:
						  		    o4.viewLostItems();
						  		    break;
                                case 2:
                                    o4.addLostItem();
                                    break;
                                case 3:
                                    o4.searchLostItems();
                                    break;
                                case 4:
                                    o4.removeLostItem();
                                    break;
                                case 5:
                                    break;
						  		case 6:
						  			cout<<"Exiting the program...";
                                    exit(1);
						  			break;
                                default:
                                    cout<<"Invalid choice. Please choose from (1-6)";
                                    break;
						    }
                        } while (choiceLost != 5);
                        break; 
					case 5: // Founditems
                        int choiceFound;
                        do {
                            choiceFound = foundMenu ();
                            switch (choiceFound) {
                                case 1:
						  		    o5.viewFoundItems();
						  		    break;
                                case 2:
                                    o5.addFoundItem();
                                    break;
                                case 3:
                                    o5.searchFoundItems();
                                    break;
                                case 4:
                                    o5.removeFoundItem();
                                    break;
                                case 5:
                                    break;
						  		case 6:
						  			cout<<"Exiting the program...";
                                    exit(1);
						  			break;
                                default:
                                    cout<<"Invalid choice. Please choose from (1-6)";
                                    break;
						    }
                        } while (choiceFound != 5);
                        break;

                    
                    case 6:    
                        	cout<<"Exiting the program...";
                            exit(1);
						  	break;
                    default:
                        cout<<"Invalid choice. Please choose from (1-6)";
                        break;
                }
            } while (choice != 6);
    }
};

int main() {
    
    FIR fir1;
    PoliceDept pd1;
    LostItems li;
    FoundItems fi;
    Criminal c1;
    Login l;
    
    l.welcomeMsg();
    l.simulation(pd1,fir1,c1, li, fi);
    
    return 0;
}

