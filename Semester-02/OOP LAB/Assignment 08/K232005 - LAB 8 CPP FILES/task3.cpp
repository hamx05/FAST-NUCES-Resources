#include <iostream>
using namespace std;

class ColdDrink {
    protected:
        string drinkName;
        string companyName;
        int rate;
        int price;
        int quantity;

    public:
        ColdDrink (string drinkName, string companyName, int rate, int price, int quantity) {
            this->drinkName = drinkName;
            this->companyName = companyName;
            this->rate = rate;
            this->price = price;
            this->quantity = quantity;
        }

        virtual void calcPrice () {}
        virtual void displayDetails () {}
};

class Soda : public ColdDrink {
    public:
        Soda (string drinkName, string companyName, int rate, int price, int quanity) : ColdDrink (drinkName, companyName, rate, price, quanity) {}

        void calcPrice () {   
            cout << "The price of " << drinkName << " is: Rs " << price << endl;
        }

        void displayDetails () {
            cout << "Company Name: " << companyName << endl;
            cout << "Drink name: " << drinkName << endl;
            cout << "Rate per bottle: " << rate << endl;
            cout << "Quanity: " << quantity << endl;
            cout << "Total price: " << price << endl;
        }
};

class Juice : public ColdDrink {   
    public:
        Juice (string drinkName, string companyName, int rate, int price, int quanity) : ColdDrink (drinkName, companyName, rate, price, quanity) {}

        void calcPrice () {
            cout << "The price of " << drinkName << " is: Rs " << price << endl;
        }

        void displayDetails () {
            cout << "Company Name: " << companyName << endl;
            cout << "Drink name: " << drinkName << endl;
            cout << "Rate per bottle: " << rate << endl;
            cout << "Quanity: " << quantity << endl;
            cout << "Total price: " << price << endl;
        }
};

class EnergyDrink : public ColdDrink {
    public:
        EnergyDrink (string drinkName, string companyName, int rate, int price, int quanity) : ColdDrink (drinkName, companyName, rate, price, quanity) {}

        void calcPrice () {
            cout << "The price of " << drinkName << " is: Rs " << price << endl;
        }

        void displayDetails () {
            cout << "Company Name: " << companyName << endl;
            cout << "Drink name: " << drinkName << endl;
            cout << "Rate per bottle: " << rate << endl;
            cout << "Quanity: " << quantity << endl;
            cout << "Total price: " << price << endl;
        }
};

int main() {
    ColdDrink *d1,*d2,*d3;
    Soda s1("Lemonade", "ABC", 100, 150, 200);
    Juice j1("Slice", "Nestle", 30, 50, 100);
    EnergyDrink e1("Coke", "Coca Cola", 70, 100, 500);

    cout<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Price of Soda" << endl;
    d1 = &s1;
    d1->calcPrice();

    cout<< endl<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Price of Juice" << endl;
    d2 = &j1;
    d2->calcPrice();

    cout<< endl<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Price of Energy Drink" << endl;
    d3 = &e1;
    d3->calcPrice();

    cout<< endl<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Details of Soda" << endl;
    d1->displayDetails();

    cout<< endl<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Details of Juice" << endl;
    d2->displayDetails();

    cout<< endl<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Details of Energy Drink" << endl;
    d3->displayDetails();

    return 0;
}