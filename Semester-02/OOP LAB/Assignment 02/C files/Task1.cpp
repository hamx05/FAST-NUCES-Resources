#include <iostream>
using namespace std;

void RoboHammad() {
    string firstName, lastName, location;
    
    cout<<"Enter your full name: "; cin>>firstName; cin>>lastName;
    cout<<"Okay, " << firstName << " "<< lastName <<" enter the place where you live: "; cin>>location;
    cout<<"Oh nice! " << location << " is a great place to live!";

}

int main () {
    RoboHammad();
    return 0;
}

