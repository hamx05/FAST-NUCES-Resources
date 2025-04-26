#include <iostream>
using namespace std;

class HotelService {
    private:
        string serviceName;
        float cost;

    public:
        void setProperties (string a, float b) {
            serviceName = a;
            cost = b;
        }

        void displayService () {
            cout<<"Service: " << serviceName << endl;
            cout<<"Cost: Rs " << cost;
        }
};

int main () {
    
    string x;
    float y;

    HotelService H1;

    // Not mentioned in question, so taking input from user. 

    cout<<"Enter the service name: ";
    getline(cin, x);

    cout<<"Enter the cost: ";
    cin>> y;

    H1.setProperties (x, y);
    H1.displayService();

    return 0;
}