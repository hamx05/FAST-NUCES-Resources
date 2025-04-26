#include <iostream>
using namespace std;

class Restaurant {
    private:
        string restaurantName[2];
        string location[2];
        string menuList_FoodHaven[3];
        string menuList_PixelBites[3];
        int priceList_FoodHaven[3];
        int priceList_PixelBites[3];
        string validCouponCodesList[2];
        static int CouponsRedeamed;
    
    public:
        
        Restaurant() : restaurantName{"Food Haven", "Pixel Bites"},
                    location{"City Center", "Cyber Street"}, 
                    menuList_FoodHaven{"Sushi", "Pad Thai", "Mango Tango"}, 
                    menuList_PixelBites{"Binary Burger","Quantum Quinoa","Data Donuts"}, 
                    priceList_FoodHaven{2000, 3000, 4000}, 
                    priceList_PixelBites{1000, 1200, 1400},
                    validCouponCodesList{"FH-BOGO-12345", "PB-BOGO67890"} {}

        void displayMenu_FoodHaven() {
            cout<<"Menu of Food Haven Restaurant:" << endl;
            for (int i=0; i<3; i++) {
                cout<< i+1 << ". " << menuList_FoodHaven[i] << endl;
            }
        }

        void displayMenu_PixelBites() {
            cout<<"Menu of Pixel Bites Restaurant:" << endl;
            for (int i=0; i<3; i++) {
                cout<< i+1 << ". " << menuList_PixelBites[i] << endl;
            }
        }

        void generateBill () {

        }
        
        void applyDiscount () {

        }
};

class BOGOCoupon {
    private:
        string couponCode[2];
        string validFrom;
        string validUntil;
        string restaurantCode;
    public:
        BOGOCoupon () {
            couponCode[0] = "FH-BOGO-12345";
            couponCode[1] = "PB-BOGO67890";            
        }

        void is_valid () {

        }
};

class User {
    private:
        string name;
        int age;
        int phoneNumber;
        int couponsList;
    
    public:
        void Accumulate_coupon() {

        }

        void Has_valid_coupon() {

        }
        void redeem_coupon() {

        }
};


int main () {


    return 0;
}