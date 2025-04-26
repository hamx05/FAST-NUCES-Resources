#include <iostream>
using namespace std;

struct Airplane {
    string model;
    string role;
    string origin;
    string manufacturer;
    bool status;
};

void AirplaneInfo(int n, Airplane* airplanes) {
    for (int i = 0; i < n; i++) {
        cout<<"Enter the info for airplane " << i + 1 << endl;
        cout<<"Model of the airplane: "; cin >> airplanes[i].model;
        cout<<"Role of the airplane: "; cin >> airplanes[i].role;
        cout<<"Origin of the airplane: "; cin >> airplanes[i].origin;
        cout<<"Manufacturer of the airplane: "; cin >> airplanes[i].manufacturer;
        cout<<"Status of the airplane: "; cin >> airplanes[i].status;
        cout<<"\n";
    }
}

int main() {
    int n;

    cout<<"Enter the number of airplanes you want to add the info for: "; cin >> n;
    Airplane* airplanes = new Airplane[n];
    AirplaneInfo(n, airplanes);

    delete[] airplanes;

    return 0;
}
