#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

float get_float() {
    float n;
    for (;;) {
        if (cin >> n) {
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry. Please re-enter: ";
    }
}

class Drone {
    protected:
        float latitude;
        float longitude;
        float altitude;
        float speed;
        bool flightStatus;
    
    public:
        Drone () {
            latitude=500;
            longitude=500;
            altitude=50;
            flightStatus=false;
        }

        Drone (float latitude, float longitude, float altitude, float speed) {
            this->latitude= latitude;
            this->longitude = longitude;
            this->altitude = altitude;
            this->speed = speed;
            flightStatus = true;
        }

        void adjustAltitude () {
            cout<<"Enter new altitude: " << endl;
            float newAltitude;
            newAltitude=get_float();
            altitude = newAltitude;
        }

        void setSpeed () {
            cout<<"Enter new speed: " << endl;
            float newSpeed;
            newSpeed=get_float();
            speed = newSpeed;
        }

        float calculateDistance(float destLatitude, float destLongitude, float destAltitude) {
            return sqrt(pow(destLatitude - latitude, 2) + pow(destLongitude - longitude, 2) + pow(destAltitude - altitude, 2));
        }

        // -------- FlyAble -------- 
        void takeOff () {
            cout<<"The drone has taken off." << endl;
            flightStatus=true;
        }

        void land () {
            if (flightStatus) {
                cout<<"The drone is being landed." << endl;
                flightStatus = false;
            }
            if (!flightStatus) {
                cout<<"The drone is already at ground." << endl;
            }
        }
        
         // -------- FlyAble --------
        virtual void navigateTo () {

        }

        // -------- ScanAble --------
        virtual void scanArea(float radius) {   

        }
};

class ReconDrone : public Drone {
    protected:
        int cameraResolution;
        int maxFlightTime;
    
    public:
        ReconDrone () : Drone () {
            cameraResolution = 0;
            maxFlightTime = 0;
        }

        ReconDrone (float latitude, float longitude, float altitude, float speed, int cameraResolution, int maxFlightTime) 
        : Drone (latitude, longitude, altitude, speed) {
            this->cameraResolution = cameraResolution;
            this->maxFlightTime = maxFlightTime;
        }

        void setCameraResolution () {
            cout<<"Enter new camera resolution: " << endl;
            int newCameraResolution;
            cin>>newCameraResolution;
            cameraResolution = newCameraResolution;

        }

        void setMaxFlightTime () {
            cout<<"Enter new max flight time: " << endl;
            int newMaxFlightTime;
            cin>>newMaxFlightTime;
            maxFlightTime = newMaxFlightTime;
        }

        void navigateTo () {
            float newLatitude,  newLongitude,  newAltitude;
            cout<<"Enter the latitude to navigate the drone: ";
            newLatitude=get_float();

            cout<<"Enter the longitude to navigate the drone: ";
            newLongitude=get_float();

            cout<<"Enter the altitude to navigate the drone: ";
            newAltitude=get_float();

            double distance = calculateDistance(newLatitude, newLongitude, newAltitude);
            double estimatedTime = distance / speed;

            if (flightStatus) {
                cout<<"The drone is currently at position ("<<latitude<<","<<longitude<<") & "<<altitude <<" meters high and is navigated towards ("<<newLatitude<<","<<newLongitude<<") and is projected to reach the height of "<<altitude<<" meters."<<endl;
                cout<<"Estimated time to reach the destination: " << estimatedTime << " minutes." << endl;
            }
            if (!flightStatus) {
                flightStatus=true;
                cout<<"The drone is launched towards position ("<<newLatitude<<","<<newLongitude<<") and is projected to reach the height of "<<newAltitude<<" meters."<<endl;
                cout<<"Estimated time to reach the destination: " << estimatedTime << " minutes." << endl;
            }
            this->latitude=newLatitude;
            this->longitude=newLongitude;
            this->altitude=newAltitude;
        }

        // -------- ScanAble --------
        void scanArea(float radius) {
            bool found=false;
            int totalObjects=5;
            float objectLatitude[totalObjects];
            float objectLongitude[totalObjects];
            float objectAltitude[totalObjects];
            float objectDistanceFromDrone[totalObjects];

            for (int i=0; i<totalObjects; i++) {
                objectLatitude[i] = latitude + (i+1)*20;
                objectLongitude[i] = longitude + (i+1)*20;
                objectAltitude[i] = altitude + (i+1)*20;
                objectDistanceFromDrone[i] = calculateDistance(objectLatitude[i], objectLongitude[i], objectAltitude[i]);

                if (objectDistanceFromDrone[i] <= radius) {
                    found = true;
                    cout<<"Object Detected In Drone's Radius!" << endl;
                    cout<<"Object Distance from Drone: " << objectDistanceFromDrone[i] << " meters." << endl;
                    cout<<"Object Latitude: " << objectLatitude[i] << " meters." << endl;
                    cout<<"Object Longitude: " << objectLongitude[i] << " meters." << endl;
                    cout<<"Object Altitude: " << objectAltitude[i] << " meters." << endl << endl;
                }
            }
             
            if (!found) {
                cout<<"No object detected in the radius!" << endl;
            }
        }
};

int main() {
    
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"Name: Muhammad Hammad" << endl;
    cout<<"Roll No: 23K-2005" << endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;

    ReconDrone rd(100, 100, 30, 50, 1080, 10);
    
    cout<<endl<<"----------- Navigating Recon Drone -----------" << endl;
    rd.navigateTo();

    cout<<endl<<"----------- Scanning Area -----------" << endl;
    rd.scanArea(120);

    return 0;
}