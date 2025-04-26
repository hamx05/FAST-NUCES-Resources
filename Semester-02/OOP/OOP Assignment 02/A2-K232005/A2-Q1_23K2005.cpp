#include <iostream>
#include <vector>
using namespace std;

class  SecurityTool {
    protected:
        string securityLevel;
        int cost;
        int noOfDevices;
    
    public:
        SecurityTool () {}
        SecurityTool (string SL, int C, int NOD) {
            // Security Level
            if (SL == "High" || SL == "Medium" || SL == "Low") {
                securityLevel = SL;
            } else { 
                cout << "Security level cannot be anything other than High, Medium or Low." << endl;
            }
            // Cost
            if (C>0) {
                cost = C;
            } else {
                cout<< "Cost cannot be 0 or less than 0." << endl;
            }
            // Number of devices
            if (NOD>0 && NOD<=10) {
                noOfDevices = NOD;
            } else {
                cout<<"Assignment of number of devices has failed because Firewall Tool can only run on upto 10 devices." << endl;
            }
        }

        void performScan() {
            cout<<"The security scan has been performed successfully." << endl;
        }
};

class FirewallTool : public SecurityTool {
    private:
        vector <int> ports;
        vector <string> protocolList;
        vector <string> trafficAllowed;

    public:

        FirewallTool () {
            protocolList = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
        }

        FirewallTool (string SL, int C, int NOD, int portStart) : SecurityTool (SL, C, NOD) {
            generateList(portStart);
            cout<<"Protocol List has been generated successfully." << endl;
            protocolList = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
        }

        void generateList(int start) {
            int i;
            if (start > 0) {
                int lim = start+23; // 1+23 = 24
                cout<<"Port List has been generated successfully." << endl;
                for (i=start; i<lim; i++) { // 1 < 24
                    start++;
                    ports.push_back(start);
                }
            } else {
                cout<<"Port List cannot initiate from 0." << endl;
            }
        }

        void performScan () {
            int i, j, k, tempPort;
            cout<<"The security scan has been performed successfully." << endl;
            if (securityLevel == "High") {
                cout<<"Traffic is allowed from all the Ports and Protocols." << endl;
                for (i=0; i<ports.size(); i++) {
                    trafficAllowed.push_back(to_string(ports[i]));
                }
                for (j=0; j<protocolList.size(); j++) {
                    trafficAllowed.push_back(protocolList[j]);
                    i++;
                }
                // Displaying Allowed Traffic
                for (i=0; i<trafficAllowed.size()-protocolList.size(); i++) {
                    cout<< "Allowed Traffic " << i+1 << ": Port " << trafficAllowed[i] << endl;
                }
                for (;i<trafficAllowed.size(); i++) {
                    cout<< "Allowed Traffic " << i+1 << ": Protocol " << trafficAllowed[i] << endl;
                }
            }

            else if (securityLevel == "Medium") {
                cout<<"Traffic is allowed from all the Ports (2 excessive) and all Protocols." << endl;
                for (i=0; i<ports.size(); i++) {
                    trafficAllowed.push_back(to_string(ports[i]));
                }
                tempPort = ports[i-1];
                for (k=0; k<2; k++) {
                    tempPort++;
                    trafficAllowed.push_back(to_string(tempPort));
                    i++;
                }
                for (j=0; j<protocolList.size(); j++) {
                    trafficAllowed.push_back(protocolList[j]);
                    i++;
                }
                // Displaying Allowed Traffic
                for (i=0; i<25; i++) {
                    cout<< "Allowed Traffic " << i+1 << ": Port " << trafficAllowed[i] << endl;
                }
                for (i=25;i<31; i++) {
                    cout<< "Allowed Traffic " << i+1 << ": Protocol " << trafficAllowed[i] << endl;
                }
            }
            else if (securityLevel == "Low") {
                cout<<"Traffic is allowed from all the Ports (5 excessive) and all Protocols (2 inclusive: TCP and DNS)" << endl;
                for (i=0; i<ports.size(); i++) {
                    trafficAllowed.push_back(to_string(ports[i]));
                }
                tempPort = ports[i-1];
                for (k=0; k<5; k++) {
                    ++tempPort;
                    trafficAllowed.push_back(to_string(tempPort));
                    i++;
                }
                for (j=0; j<protocolList.size(); j++) {
                    trafficAllowed.push_back(protocolList[j]);
                    i++;
                }
                trafficAllowed.push_back("TCP");
                trafficAllowed.push_back("DNS");
                // Displaying Allowed Traffic
                for (i=0; i<28; i++) {
                    cout<< "Allowed Traffic " << i+1 << ": Port " << trafficAllowed[i] << endl;
                }
                for (i=28;i<36; i++) {
                    cout<< "Allowed Traffic " << i+1 << ": Protocol " << trafficAllowed[i] << endl;
                }
            }
            else {
                cout<<"Invalid security level." << endl;
            }
        }
};

int main() {
    
    cout<<"*************************" << endl;
    cout<<"* Name: Muhammad Hammad *" << endl;
    cout<<"* Roll Number: 23K-2005 *" << endl;
    cout<<"*************************" << endl << endl;

    cout<<"-----------------------------------------------------------------" << endl;
    cout<<"\t\tDisplay For High Level Security" << endl;
    cout<<"-----------------------------------------------------------------" << endl;
    FirewallTool FT1("High", 25000, 5, 2);
    FT1.performScan();

    cout<<"-----------------------------------------------------------------" << endl;
    cout<<"\t\tDisplay For Medium Level Security" << endl;
    cout<<"-----------------------------------------------------------------" << endl;
    FirewallTool FT2("Medium", 50000, 3, 2);
    FT2.performScan();

    cout<<"-----------------------------------------------------------------" << endl;
    cout<<"\t\tDisplay For Low Level Security" << endl;
    cout<<"-----------------------------------------------------------------" << endl;
    FirewallTool FT3("Low", 70000, 2, 2);
    FT3.performScan();

    cout<<"-----------------------------------------------------------------" << endl;
    cout<<"\t\tDisplay Other Mentioned Conditions" << endl;
    cout<<"-----------------------------------------------------------------" << endl;
    FirewallTool FT4("Moderate", -5, 12, 0);

    return 0;
}