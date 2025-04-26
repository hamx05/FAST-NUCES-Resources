#include <iostream>
using namespace std;

class Bank {
	protected:
		int balanceA=100;
		int balanceB=150;
		int balanceC=200;
	
	public:
		virtual void getBalance () const = 0;	
};

class BankA : public Bank {
	public:
		BankA () {}
		void getBalance () const {
			cout<<"The balance in Bank A is: Rs " << balanceA << endl;
			
		}
};

class BankB : public Bank {
	public:
		BankB () {}
		void getBalance () const {
			cout<<"The balance in Bank B is: Rs " << balanceB << endl;
			
		}
};

class BankC  : public Bank {
	public:
		BankC () {}
		void getBalance () const {
			cout<<"The balance in Bank C is: Rs " << balanceC << endl;
			
		}
};

int main () {
	
	Bank* bA = new BankA;
	Bank* bB = new BankB;
	Bank* bC = new BankC;
	
	bA->getBalance();
	bB->getBalance();
	bC->getBalance();
	return 0;
}
