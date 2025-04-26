#include <iostream>
#include <vector>
using namespace std;

class Data {
	protected:
		vector <int> balance;
	public:
		Data () {
			balance = {100,200,300};
		}

		void pop(){
			cout << "Popped: " << balance[0]<< endl;
			balance.erase(balance.begin());
		}

		void pushBack(int x){
			cout << "Pushed Back: " << x << endl;
			balance.push_back(x);
		}
		bool isEmpty(){
			if (balance.size()>=1) {
				cout<<"The vector is not empty." << endl;

			}
			cout<<"Vector is empty now." << endl;
		}

		void displayVector () {
			int size = balance.size();
			for (int i=0; i<size; i++) {
				cout<<"Element " << i+1 << ": " << balance[i] << endl;
			}
		}
};

int main () {
	
	Data d;

	cout<<"Displaying Default Vector (by default have 3 elements)" << endl;
	d.displayVector();
	cout<<endl;
	d.pushBack(500);
	d.pop();
	d.pushBack(1000);
	d.pop();
	d.pop();
	d.pop();
	d.isEmpty();
	d.pop();
	d.isEmpty();
	return 0;
}
