#include <iostream>
using namespace std;

class BankAccount {
    protected:
        int balance;

    public:

        BankAccount () {
            balance = 0;
            cout<<"Default constructor has been called." << endl;
        }

        BankAccount (int newBalance) {
            balance = newBalance;
            cout<<"Parameterized constructor has been called." << endl;

        }

        BankAccount (BankAccount &obj) {
            balance = obj.balance;
            balance -= 200;
            cout<<"Copy constructor has been called." << endl;
        }

        ~BankAccount() {}

        int getBalance() {
            return balance;
        }
};


int main () {

    BankAccount account1;
    BankAccount account2(2000);
    BankAccount account3(account2);

    cout<<"Balance of Account 1 = Rs " << account1.getBalance() << endl;
    cout<<"Balance of Account 2 = Rs " << account2.getBalance() << endl;
    cout<<"Balance of Account 3 = Rs " << account3.getBalance() << endl;
    cout<<"Balance of Account 2 again = Rs " << account2.getBalance() << endl;

    return 0;
}