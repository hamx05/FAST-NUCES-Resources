#include <iostream>
using namespace std;

class RealEstateProperty {
    private:
    string address;
    int price;
    int sqFootage;
    bool status; // 1-> Available - 0-> Sold

    public:
    void setProperties(string newAddress, int newPrice, int newSqFootage) {
        address = newAddress;
        price = newPrice;
        sqFootage = newSqFootage;
    }
    
    void displayProperty() {
        cout<<"Address: " << address << endl; 
        cout<<"Price: " << price << endl; 
        cout<<"Square footage: " << sqFootage << endl; 
    }

    void displayStatus(bool newStatus) {
        status = newStatus;
        cout<<"Status: ";
        if (status == 1) {
            cout<<"Available.";
        }
        else {
            cout<<"Sold";
        }
    }
};

int main () {

    RealEstateProperty property1;

    property1.setProperties("Street #10, Gulshan e Hadeed, Karachi", 1000000, 240);
    property1.displayProperty();
    property1.displayStatus(true);
    return 0;
}