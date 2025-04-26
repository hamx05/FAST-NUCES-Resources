#include <iostream>
using namespace std;
/*
Players -> name, age, amount
Batsmen -> role
Bowler -> bowling type
Batsmen and Bowler -> All rounder 

        Players
       /       \
    Batsmen     Bowler
        \      /
       All Rounder

*/

class Players {
    protected:
        string name;
        int age;
        int amount; // jitne me sign huye

    public:
        Players () {
            name = "Default name";
            age = 20;
            amount = 100000;
        }
        
        void setName () {
            cout<<"Enter the name of the player: ";
            cin>> name;
        }
        void setAge () {
            cout<<"Enter the age of the player: ";
            cin>> age;
        }
        void setAmount () {
            cout<<"Enter the amount in which the player has been signed: ";
            cin>> amount;
        }

        void displayPlayerData () {
            cout<<"-----------------------------------------" << endl;
            cout<<"\tPlayer's Personal Info:" << endl;
            cout<<"Name: " << name << endl;
            cout<<"Age: " << age << endl;
            cout<<"Amount paid: " << amount << endl;
        }
};

class Batsmen : public Players {
    protected:
        string role; // (opener, middle order, hard hitter)
    public:
        Batsmen () {}

        void setBatsmenData () {
            cout<<"Enter the role of the batsman: ";
            cin>> role;
        }
        void displayBatsmenData () {
            displayPlayerData();
            cout<<"Role: " << role << endl;
        }
};

class Bowler : public Players {
    protected:
        string bowlingType; // (Fast, Spin or other)
    public:
        Bowler () {}
        void setBowlerData () {
            cout<<"Enter the role of the bowler: ";
            cin>> bowlingType;
        }
        void displayBowlerData () {
            displayPlayerData();
            cout<<"Bowling type: " << bowlingType << endl;
        }
};

class AllRounder : public Batsmen, public Bowler {
    public:
        AllRounder () {}

        void displayAllRounderData () {
            displayBatsmenData();
            displayBowlerData();
        }
};

int main() {

    AllRounder AR;

    AR.setBatsmenData();
    AR.setBowlerData();
    cout<<"-----------------------------------------" << endl;
    cout<<"\tDisplaying Role for Batsman" << endl;
    AR.displayBatsmenData();
    cout<<"-----------------------------------------" << endl;
    cout<<"\tDisplaying Role for Bowler" << endl;
    AR.displayBowlerData();
    cout<<"-----------------------------------------" << endl;
    cout<<"\tDisplaying Data for All-Rounder Player" << endl;
    AR.displayAllRounderData();

    return 0;
}
