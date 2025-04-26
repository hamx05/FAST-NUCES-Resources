#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class UberRide {
    private:
        string riderName;
        string driverName;
        float distance;
        int fare;
        string location;
    public:
        void setData (string a, string b, float c, int d, string e) {
            riderName = a;
            driverName = b;
            distance = c;
            fare = d;
            location = e;
        }
        void displayAll () {
            cout<<"Dear " << riderName << ", Your ride has been successfully booked. Below are the details for the ride.\n";
            cout<<"Customer's name: " << riderName << endl;
            cout<<"Driver's name: " << driverName << endl;
            cout<<"Distance: " << distance << " km" << endl;
            cout<<"Fare: Rs " << fare << endl; 
            cout<<"Location: " << location << endl;
            cout<<"We wish you a happy and safe journey. Take care!";
        }
};

int main () {

    int randomNum, start, end, diff;
    string a, b, e;

    UberRide R1;

    string location[5] = {"Hadeed", "Shah Latif", "Quaidabad", "Malir", "Saddar"};
    string driver[5] = {"Mike Bishop", "Adam Walsh", "Jane Anne", "Eliza Carson", "Haytam Rosseli"};
    
    cout<<"Enter your name: ";
    getline(cin, a);

    std::srand(std::time(nullptr));
    randomNum = (rand() % 6);
    b = driver[randomNum];

    cout<<"Enter pickup location: [1. Hadeed ~ 2. Shah Latif ~ 3. Quaidabad ~ 4. Malir ~ 5. Saddar]: ";
    cin>> start;
   
    cout<<"Enter dropoff location: [1. Hadeed ~ 2. Shah Latif ~ 3. Quaidabad ~ 4. Malir ~ 5. Saddar]: ";
    cin>> end;

    diff = end - start;
    int fare[5] = {150, 250, 600, 1000, 1200};
    int distance[5] = {0, 10, 18, 25, 35};
    e = location[end-1];

    R1.setData(a, b, distance[diff], fare[diff], e);
    R1.displayAll();

    return 0;
}