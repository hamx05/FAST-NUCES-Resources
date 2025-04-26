#include <iostream>
using namespace std;

class DarazPersonData {
    protected:
        string firstName;
        string lastName;
        string address;
        string city;
        string state;
        string zip;
        string phone;
    
    public:
        // Constructors
        DarazPersonData () {}
        DarazPersonData (string firstName, string lastName, string address, string city, string state, string zip, string phone) {
            this->firstName = firstName;
            this->lastName = lastName;
            this->address = address;
            this->city = city;
            this->state = state;
            this->zip = zip;
            this->phone = phone; 
        }

        // Setter functions
        void setFirstName(string firstName) { this->firstName = firstName; }
        void setLastName(string lastName) { this->lastName = lastName; }
        void setAddress(string address) { this->address = address; }
        void setCity(string city) { this->city = city; }
        void setState(string state) { this->state = state; }
        void setZip(string zip) { this->zip = zip; }
        void setPhone(string phone) { this->phone = phone; }

        // Getter functions
        string getFirstName() const { return firstName; }
        string getLastName() const { return lastName; }
        string getAddress() const { return address; }
        string getCity() const { return city; }
        string getState() const { return state; }
        string getZip() const { return zip; }
        string getPhone() const { return phone; }
};

class DarazCustomerData {
    protected:
        int customerNum;
        int loyaltyPoints;
        int purchases;
        int bill;
        static int uniqueCustomerNumber;

    public:
        // Constructors
        DarazCustomerData () {
            bill=0;
            purchases=0;
        }
        DarazCustomerData (int loyaltyPoints) {
            customerNum = generateUniqueCustomerNumber();
            if (loyaltyPoints%10==0) {
                this->loyaltyPoints = loyaltyPoints; 
            }
            else {
                cout<<"Invalid assignment. Loyalty Points can only be in multiple of 10." << endl;
            }
        }

        static int generateUniqueCustomerNumber() {
            return ++uniqueCustomerNumber;
        }

        // Setter functions
        void setCustomerNum(int customerNum) { this->customerNum = customerNum; }
        void setLoyaltyPoints(int loyaltyPoints) { this->loyaltyPoints = loyaltyPoints; }

        // Getter functions
        int getCustomerNum() const { return customerNum; }
        int getLoyaltyPoints() const { return loyaltyPoints; }
};

int DarazCustomerData::uniqueCustomerNumber = 1024;

class DarazLoyaltyProgram : public DarazPersonData, public DarazCustomerData {
    public:
        DarazLoyaltyProgram(string firstName, string lastName, string address, string city, string state, string zip, string phone, int loyaltyPoints)
        : DarazPersonData (firstName, lastName, address, city, state, zip, phone) , DarazCustomerData (loyaltyPoints) { }
        
        void purchaseItems () {
            char choice;
            int numPurchases;

            cout<<"Do you want to purchase an item? (y/n): ";
            cin>> choice;
            if (choice == 'y' || choice == 'Y' ) {
                cout<<"Enter the no. of purchases you want: ";
                cin>> numPurchases;
                bill = numPurchases * 2500; // assuming that every item costs 2500
                cout<<"You have successfully purchased " << numPurchases << " items for Rs " << bill << "." << endl;
                purchases += numPurchases;
                int pointsToBeAdded = numPurchases * 10; // assuming 10 loyalty points for every purchase
                addLoyaltyPoints(pointsToBeAdded);
            }
            else if (choice == 'n' || choice == 'N' ) {
                cout<<"You have prevented yourselves from purchasing an item." << endl;
            }
            else {
                cout<<"Invalid input. Please try again." << endl;
                tryAgain("Purchase");
            }
            
        }

        void addLoyaltyPoints (int pointsToBeAdded) {
            cout<< pointsToBeAdded << " loyalty points have been added to your wallet. Thank you for shopping with us!" << endl;
            loyaltyPoints += pointsToBeAdded;
        }

        void redeemLoyaltyPoints () {
            int pointsToRedeem;
            cout<<"Enter the number of loyalty points (in multiple of 10) you want to redeem: ";
            cin>> pointsToRedeem;
            if (pointsToRedeem<=loyaltyPoints && pointsToRedeem>0) {
                if (pointsToRedeem%10 == 0) {
                    loyaltyPoints -= pointsToRedeem;
                    float discountPerc = pointsToRedeem*0.1;
                    int discountRedeemed = (bill*discountPerc)/100; // Assuming 1% discount for every 10 redeemed loyalty points.
                    bill = bill - discountRedeemed;
                    cout<<"You have sucessfully redeemed " << pointsToRedeem << " points for " << discountPerc << "% discount." << endl;
                    cout<<"Your bill after Rs " << discountRedeemed << " discount is: Rs " << bill << endl;
                }
                else {
                    cout<<"Process failed. You may only redeem loyalty points in multiple of 10." << endl;
                    tryAgain("Redeem");
                }   
            }
            else {
                cout<<"Process failed. You do not have " << pointsToRedeem << " loyalty points in your wallet to redeem." << endl;
                tryAgain("Redeem");
            }
        }

        void displayLoyaltyPoints () {
            cout<<"You have a total of " << loyaltyPoints << " loyalty points in your wallet." << endl;
        }
        
        void tryAgain (string condition) {
            char choice;
            // if (condition=="Add") {
            //     cout<<"Do you want to try again? (y/n): ";
            //     cin>> choice;
            //     if (choice == 'y' || choice ==  'Y' ) {
            //         addLoyaltyPoints();
            //     }
            //     else if (choice == 'n' || 'N' ) {
            //         cout<<"You have prevented yourself from adding loyalty points." << endl;
            //     }
            //     else {
            //         cout<<"Invalid input." << endl;
            //         tryAgain("Add");
            //     }
            // }
            if (condition=="Redeem") {
                cout<<"Do you want to try again? (y/n): ";
                cin>> choice;
                if (choice == 'y' || choice == 'Y' ) {
                    redeemLoyaltyPoints();
                }
                else if (choice == 'n' || choice == 'N' ) {
                    cout<<"You have prevented yourself from redeeming loyalty points." << endl;
                }
                else {
                    cout<<"Invalid input." << endl;
                    tryAgain("Redeem");
                }
            }
            if (condition=="Purchase") {
                cout<<"Do you want to try again? (y/n): ";
                cin>> choice;
                if (choice == 'y' || choice == 'Y' ) {
                    purchaseItems();
                }
                else if (choice == 'n' || choice == 'N' ) {
                    cout<<"You have prevented yourself from purchasing items." << endl;
                }
                else {
                    cout<<"Invalid input." << endl;
                    tryAgain("Purchase");
                }
            }
        }

        // void addLoyaltyPoints () { // The loyalty points should be in multiple of 10 so it is easier to add/remove a specific number of points.
        //     int pointsToBeAdded;
        //     cout<<"Enter the loyalty points to be added (in multiple of 10): ";
        //     cin >> pointsToBeAdded;

        //     if (pointsToBeAdded%10 == 0 && pointsToBeAdded>0) {
        //         loyaltyPoints += pointsToBeAdded;
        //         cout<< pointsToBeAdded << " loyalty points have been successfully added to your wallet." << endl;
        //         cout<< "You now have a total of " << loyaltyPoints << " in your wallet." << endl;
        //     }
        //     else {
        //         cout<<"Process failed. You may only add positive loyalty points in multiple of 10." << endl;
        //         tryAgain("Add");
        //     }
        // }

        // void redeemLoyaltyPoints () {
        //     int pointsToRedeem;
        //     cout<<"Enter the number of loyalty points (in multiple of 10) you want to use: ";
        //     cin>> pointsToRedeem;
        //     if (pointsToRedeem<=loyaltyPoints && pointsToRedeem>0) {
        //         if (pointsToRedeem%10 == 0) {
        //             loyaltyPoints -= pointsToRedeem;
        //             cout<<"You have sucessfully redeemed " << pointsToRedeem << " points for 15 percent discount." << endl;
        //             discountRedeemed = (bill*0.15);
        //             bill = bill - discountRedeemed;
        //             cout<<"Your bill after Rs" << discountRedeemed << " discount is: Rs" << bill << endl;
        //         }
        //         else {
        //             cout<<"Process failed. You may only redeem loyalty points in multiple of 10." << endl;
        //             tryAgain("Redeem");
        //         }   
        //     }
        //     else {
        //         cout<<"Process failed. You do not have " << pointsToRedeem << " loyalty points in your wallet to redeem." << endl;
        //         tryAgain("Redeem");
        //     }
        // }
};


int main() {
    
    cout<<"*************************" << endl;
    cout<<"* Name: Muhammad Hammad *" << endl;
    cout<<"* Roll Number: 23K-2005 *" << endl;
    cout<<"*************************" << endl << endl;

    // DarazPersonData P1("Muhammad", "Hammad", "Gulshan e Hadeed", "Karachi", "Sindh", "Z-12345", "987654321");
    // DarazCustomerData C1(20);
    DarazLoyaltyProgram L1("Muhammad", "Hammad", "Gulshan e Hadeed", "Karachi", "Sindh", "Z-12345", "987654321", 20);
    
    cout<<"-------------------------------------------" << endl;
    cout<<"\tPurchasing and Adding Loyalty Points" << endl;
    L1.purchaseItems(); // will call addLoyaltyPoints()

    cout<<"-------------------------------------------" << endl;
    cout<<"\tRedeeming Loyalty Points" << endl;
    L1.redeemLoyaltyPoints();

    cout<<"-------------------------------------------" << endl;
    cout<<"\tDisplaying Loyalty Points" << endl;
    L1.displayLoyaltyPoints();

    return 0;
}