#include <iostream>
using namespace std;

class RollerCoaster {
    string name;
    int height;
    int length;
    float speed;
    int capacity; // amount of people that can be seated at once
    int currentNumRiders; // number of passengers/riders currently seated in the roller coaster
    bool RideInProgress;

    public:
        // Default Constructor
        RollerCoaster () { 
            name = "roller coaster";
            height = 500;
            length = 2000;
            capacity = 20;
            currentNumRiders = 0;
            RideInProgress = false;
            speed = 0;
        }

        // Parameterized Constructor
        RollerCoaster (string name, int height, int length, float speed, int capacity) { // Round off wali bhi done
            this->name = name;
            this->height = height;
            this->length = length;
            this->capacity = capacity;
            this->speed = speed;
            currentNumRiders = 0;

            if (capacity <= 3) {
                this->capacity = 4;
            } else {
                if (capacity % 2 == 0 || capacity % 3 == 0) {
                    this->capacity = capacity;
                } else {
                    int nextMultipleOfTwo = ((capacity / 2) + 1) * 2;
                    int nextMultipleOfThree = ((capacity / 3) + 1) * 3;

                    if (abs(nextMultipleOfTwo - capacity) < abs(nextMultipleOfThree - capacity)) {
                        this->capacity = nextMultipleOfTwo;
                    } else {
                        this->capacity = nextMultipleOfThree;
                    }
                }
            }
        }

        // Setter functions
        void setProperties (string name, int height, int length, float speed, int capacity, int currentNumRiders) { // Round off wali bhi done
            this->name = name;
            this->height = height;
            this->length = length;
            this->capacity = capacity;
            this->speed = speed;
            this->currentNumRiders = currentNumRiders;

            if (capacity <= 3) {
                this->capacity = 4;
            } else {
                if (capacity % 2 == 0 || capacity % 3 == 0) {
                    this->capacity = capacity;
                } else {
                    int nextMultipleOfTwo = ((capacity / 2) + 1) * 2;
                    int nextMultipleOfThree = ((capacity / 3) + 1) * 3;

                    if (abs(nextMultipleOfTwo - capacity) < abs(nextMultipleOfThree - capacity)) {
                        this->capacity = nextMultipleOfTwo;
                    } else {
                        this->capacity = nextMultipleOfThree;
                    }
                }
            }
        }
        
        // Getter functions 
        string getName() const { return name; }
        int getHeight() const { return height; }
        int getLength() const { return length; }
        float getSpeed() const { return speed; }
        int getCapacity() const { return capacity; }
        int getCurrentNumRiders() const { return currentNumRiders; }
        bool isRideInProgress() const { return RideInProgress; }

        void displayRideDetails () { // Extra function, to display details
            cout<<"--------- Details of the ride --------- " << endl;
            cout<<"Name: " << name << endl;
            cout<<"Height: " << height << " meters" << endl;
            cout<<"Length: " << length << " meters" << endl;
            cout<<"Speed: " << speed << " m/s" << endl;
            cout<<"Capacity: " << capacity << " passengers" << endl;
            cout<<"Current passengers/riders: " << currentNumRiders << endl;
            cout<<"---------------------------------------" << endl<<endl;
        }

        int loadPassengers (int passengersToLoad) {
            int excessPassengers = 0;
            if (!RideInProgress) {
                if (capacity<=passengersToLoad) {
                    currentNumRiders = capacity;
                    excessPassengers = passengersToLoad - currentNumRiders;
                    cout<< currentNumRiders << " passenger(s) have been loaded in the roller coaster!" << endl;
                        if (excessPassengers != 0) {
                            cout<<"But " << excessPassengers << " passenger(s) were not seated due to insufficient space!" << endl;
                        }
                    return  excessPassengers;// returning excess number of passengers
                }
                else if (capacity>passengersToLoad) {
                    currentNumRiders = passengersToLoad;
                    cout<< currentNumRiders << " passengers have been loaded in the roller coaster!" << endl;
                    return 0;
                }
                else {
                    cout<<"Invalid passenger number." << endl;
                }
            }
            else {
                cout<<"The rider is in progress. People cannot be loaded right now." << endl;
                return 0;
            }
        }

        int startRide () {
            char choice;

            if (!RideInProgress) {
                if (capacity == currentNumRiders) {
                    cout<<"All the seats have been occupied and the ride is ready to start." << endl;
                    RideInProgress = true;
                    return 0;
                }
                else if (currentNumRiders < capacity) {
                    RideInProgress = false;
                    int emptySeats = capacity - currentNumRiders;
                    cout<< emptySeats << " seats are still vacant. Ride will not start until it's full." << endl;
                    cout<<"Do you want to load " << emptySeats << " more passengers to start the ride? (y/n): " << endl;
                    cin>> choice;

                    switch (choice) {
                        case 'y':
                        case 'Y':
                            currentNumRiders = capacity;
                            cout<< emptySeats << " passengers have been successfully loaded and the ride is going to start!" << endl;
                            RideInProgress = true;
                        break;

                        case 'n':
                        case 'N':
                            cout<<"More passengers will not be added and the ride will not start." << endl;
                        break;
                        
                        default:
                            cout<<"Invalid choice. Please try again." << endl;
                        break;
                    }
                    
                    return emptySeats;
                }
            }
            else {
                return -1;
            }
        }

        int stopRide () {
            if (RideInProgress) {
                cout<<"The ride has been stopped." <<endl;
                RideInProgress = false;
            }
            else {
                cout<<"The ride is not moving and is already at stationary." << endl;
            }
        }

        void unloadPassengers () {
            if (!RideInProgress) {
                cout<<"The passengers have been unloaded from the roller coaster." << endl;
                currentNumRiders = 0;
            }
            else {
                cout<<"Passengers cannot be unloaded right now as the ride is in progress." << endl;
            }
        }

        void speedRide () {
            if (RideInProgress) {
                speed = 5 * speed;
                cout<<"The speed has been increased by 5 times, the speed is now " << speed << "m/s." << endl;
            }
            else {
                cout<<"The ride is not moving and therefore cannot be speeded up." << endl;
            }
        }

        void slowDownRide () {
            if (RideInProgress) {
                speed = speed / 2;
                cout<<"The speed has been decreased by 2 times, the speed is now " << speed << "m/s." << endl;
            }
            else {
                cout<<"The ride is not moving and therefore cannot be speeded down." << endl;
            }
        }
};


int main () {
    cout<<"********************"<<endl;
    cout<<"Name: Muhammad Hammad"<<endl;
    cout<<"Roll no: 23K-2005"<<endl;
    cout<<"********************"<<endl;
    
    string name;
    int height, length, capacity, passengersToLoad;
    float speed;

    cout<<"Enter the details of roller coaster: " << endl;
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Height: "; cin>> height;
    cout<<"Length: "; cin>> length;
    cout<<"Speed: "; cin>> speed;
    cout<<"Capacity: "; cin>> capacity;
    cout<<"Passengers to load: "; cin>> passengersToLoad;

    RollerCoaster R1, R2(name, height, length, speed, capacity);
    
    cout<<endl<< "For Default Constructor" << endl;
    R1.displayRideDetails();
    cout<<"For Parameterized Constructor" << endl;
    R2.displayRideDetails();
    R2.loadPassengers(passengersToLoad);
    R2.startRide();
    R2.speedRide();
    R2.slowDownRide();
    R2.stopRide();
    R2.unloadPassengers();
    


    return 0;
}