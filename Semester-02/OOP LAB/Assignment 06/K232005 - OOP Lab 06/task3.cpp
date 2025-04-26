#include <iostream>
#include <string>

using namespace std;

class SalonAppointment {
private:
    string customerName;
    double appointmentCost;
    static int totalAppointments;
    static double totalEarnings;

public:
    // Constructor
    SalonAppointment(const string& name, double cost) : customerName(name), appointmentCost(cost) {
        totalAppointments++;
        totalEarnings += cost;
    }

    // Methods
    string getCustomerName() const { return customerName; }

    double getAppointmentCost() const { return appointmentCost; }

    static double calculateAvgCost() {
        if (totalAppointments <= 0) {
            return 0;
        }
        int avgCost = totalEarnings / totalAppointments;
        return avgCost;
    }

    void displayDetails () {
        cout << "Customer's Name: " << getCustomerName() << " - Appointment Cost: Rs " << getAppointmentCost() << endl;
    }
};


int SalonAppointment::totalAppointments = 0;
double SalonAppointment::totalEarnings = 0.0;

int main() {
    SalonAppointment app1("Hammad", 1000);
    SalonAppointment app2("Sami", 1200);
    SalonAppointment app3("Faiq", 1500);
    
    cout << "Appointment Details:" << endl;
    app1.displayDetails();
    app2.displayDetails();
    app3.displayDetails();

    cout << "Average Appointment Cost: Rs " << SalonAppointment::calculateAvgCost() << endl;

    return 0;
}
