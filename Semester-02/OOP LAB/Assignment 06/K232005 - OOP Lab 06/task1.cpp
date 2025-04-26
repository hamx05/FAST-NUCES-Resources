#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;

public:
    // Constructor
    BankAccount(int accID, double newBalance, int* transactions, int numTrans) : accountId(accID), balance(newBalance), numTransactions(numTrans) {
        transactionHistory = new int[numTrans];
        memcpy(transactionHistory, transactions, numTrans * sizeof(int));
    }

    // Copy Constructor
    BankAccount(const BankAccount& obj) : accountId(obj.accountId), balance(obj.balance), numTransactions(obj.numTransactions) {
        transactionHistory = new int[numTransactions];
        memcpy(transactionHistory, obj.transactionHistory, numTransactions * sizeof(int));
    }

    // Destructor
    ~BankAccount() {
        delete[] transactionHistory;
    }

    // Methods
    void display() const {
        cout << "Account ID: " << accountId << endl;
        cout << "Balance: Rs " << balance << endl;
        cout << "Transaction History: ";
        for (int i = 0; i < numTransactions; ++i) {
            cout << transactionHistory[i] << " ";
        }
        cout << endl;
    }

    void updateTransactionHistory(int* newTransactions, int newNumTransactions) {
        delete[] transactionHistory; 
        numTransactions = newNumTransactions;
        transactionHistory = new int[numTransactions];
        memcpy(transactionHistory, newTransactions, numTransactions * sizeof(int));
    }
};

int main() {
  
    int initialTransactions[] = {450, 600, 700};

    BankAccount ogAccount(35, 1500, initialTransactions, 2);
    BankAccount cpAccount = ogAccount;

    cout << "\tDetails of Original Account:" << endl;
    ogAccount.display();
    cout << endl << "\tDetails of Copied Account:" << endl;
    cpAccount.display();
    
    int newTransactions[] = {250, 150};
    ogAccount.updateTransactionHistory(newTransactions, 3);

    cout << endl << "\tUpdated Details of Original Account:" << endl;
    ogAccount.display();
    

    return 0;
}

