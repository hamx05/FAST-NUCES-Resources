#include <iostream>
using namespace std;

class Bike {
    private:
        int price;

    public:
        Bike () {}
        Bike (int price) {
            this-> price = price;
        }
        bool operator> (Bike &b){
            return price>b.price;
        }
        bool operator< (Bike &b){
            return price<b.price;
        }
        bool operator== (Bike &b){
            return b.price==price;
        }
        bool operator!= (Bike &b){
            return b.price!=price;
        }
};
int main () {

    Bike b1(10),b2(10);
    bool result;

    result=b1>b2;
    cout<< "Bike 1 has greater value than Bike 2: " << result << endl;

    result=b1<b2;
    cout<< "Bike 1 has lesser value than Bike 2: " << result << endl;

    result=b1==b2;
    cout<< "Bike 1 has equal value than Bike 2: " << result << endl;

    result=b1!=b2;
    cout<< "Bike 1 has different value than Bike 2: " << result << endl;

    return 0;
}