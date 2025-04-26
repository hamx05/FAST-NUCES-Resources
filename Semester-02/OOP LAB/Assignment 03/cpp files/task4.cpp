#include <iostream>
using namespace std;

class Smartphone {
    private:
        string company;
        string model;
        string displayRes;
        int rom;
        int ram;
        int storage;
    public:
        void setData (string a, string b, string c, int d, int e, int f) {
            company = a;
            model = b;
            displayRes = c;
            rom = d;
            ram = e;
            storage = f;
        }

        string getCompany () { return company; }
        string getModel () { return model; }
        string getDisplayRes () { return displayRes; }
        int getROM () { return rom; }
        int getRAM () { return ram; }
        int getStorage () { return storage; }

        void phoneCall () { }
        void sendMsg () { }
        void connectWifi () { }
        void browseInternet () { }
};

int main () {
    int n;
    string a, b, c;
    int d, e, f;

    cout<<"enter the number of phones: ";
    cin>> n;

    Smartphone phone[n];

    // Taking input from user. I could also pass it directly into setter function
    for (int i=0; i<n; i++) {
        cin.ignore();
        cout<<"\tEnter the specs for phone " << i+1 << endl;
        cout<<"Enter the Company's name: ";
        getline(cin, a);
        cout<<"Enter the Model: ";
        getline(cin, b);
        cout<<"Enter the Display Resolution: ";
        getline(cin, c);
        cout<<"Enter the ROM: ";
        cin>> d;
        cout<<"Enter the RAM: ";
        cin>> e;
        cout<<"Enter the Storage: ";
        cin>> f;
        phone[i].setData(a, b, c, d, e, f);
        cout<<"\n";
    }

    for (int i = 0; i < n; i++) {
        cout << "Phone " << i + 1 << " Details:" << endl;
        cout << "Company: " << phone[i].getCompany() << endl;
        cout << "Model: " << phone[i].getModel() << endl;
        cout << "Display Resolution: " << phone[i].getDisplayRes() << endl;
        cout << "ROM: " << phone[i].getROM() << " GB" << endl;
        cout << "RAM: " << phone[i].getRAM() << " GB" << endl;
        cout << "Storage: " << phone[i].getStorage() << " GB" << endl;
        cout<<"\n";
    }

    return 0;
}