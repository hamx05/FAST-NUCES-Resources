#include <iostream>
using namespace std;

class BankManager;

class BankAccount {
    protected:
        string bankName;
        string accountName;
        int accountNum;
        int balance;
    
    public:
        friend class BankManager;
};

class BankManager {
    public:
        BankAccount account;

        void setBankName (string x) {
            account.bankName = x;
        }

        void setAccountName (string x) {
            account.accountName = x;
        }

        void setAccountNum (int x) {
            account.accountNum = x;
        }

        void setBalance (int x) {
            account.balance = x;
        }

        int getAccountNum () {
            return account.accountNum;
        }

        void withdrawMoney (int moneyToWithdraw) {
            if (moneyToWithdraw<=account.balance) {
                account.balance -= moneyToWithdraw;
                cout<<"You have withdrawn Rs " << moneyToWithdraw << " from your bank account." << endl;
                cout<<"Your balance is now Rs " << account.balance << "." << endl;
            }
        }

        void displayAccountDetails () {
            cout<<"Bank name: " << account.bankName << endl;
            cout<<"Account name: " << account.accountName << endl;
            cout<<"Account number: " << account.accountNum << endl;
            cout<<"Balance: " << account.balance << endl;
        }
};

int main() {
    
    BankManager BM1;

    BM1.setBankName("Meezan Bank");
    BM1.setAccountName("Hammad");
    BM1.setAccountNum(12345);
    BM1.setBalance(50000);
    BM1.displayAccountDetails();
    cout<<endl;
    BM1.withdrawMoney(10000);

    // I have only implemented function for withdrawing money. More functions can be implemented.
    
    return 0;
}