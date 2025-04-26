#include <iostream>
using namespace std;

class Restaurant {
	private:
		string name;
		string address;
		string phNum;
		float rate;
		string* menu;
		int numItems = 0;
	
	public:
		Restaurant () {
			name = "Default name";
			address = "Default address";
			phNum = "Default ph number";
			rate = 0;
		}
		
		Restaurant (string name, string address, string phNum, float rate)
		{
			this->name = name;
			this->address = address;
			this->phNum = phNum;
			this->rate = rate;
		}
		
		void add_menu_item(string item) {
			string *temp = new string[numItems];
			
			for (int i=0; i<numItems; i++) {
				temp[i] = menu[i];
			}
			
			if (numItems!=0) delete[] menu;
			
			numItems++;
			
			menu = new string[numItems];
			
			for (int i=0; i<numItems-1; i++) {
				menu[i] = temp[i];
			}
			menu[numItems-1] = item;
		}
		
		void get_menu() {
			for (int i=0; i<numItems; i++) {
				cout << "Item " << i+1 <<": " << menu[i] << endl;
			}
		}
			
};

class ItalianRestaurant : public Restaurant {
	private:
		string pastaType;
		string pizzaType;
	
	public:
		ItalianRestaurant () {
			pastaType = "Default";
			pizzaType = "Default";
		}
		ItalianRestaurant (string pastaType, string pizzaType) {
			this->pastaType = pastaType;
			this->pizzaType = pizzaType;
		}
		
		void make_pasta(string pasta) {
			add_menu_item(pasta + " Pasta");
		}
		void make_pizza (string pizza) {
			add_menu_item(pizza + " Pizza");
		}
};

class MexicanRestaurant : public Restaurant {
	private:
		int spiceLevel;
		string saslaType;
	public:
		void make_taco(string taco) {
			add_menu_item(taco + " Taco");
		}
		void make_burrito(string burrito) {
			add_menu_item(burrito + " Burrito");
		}
};

int main () {
	
	ItalianRestaurant r1;
	MexicanRestaurant r2;
	Restaurant r3;
	
	cout<<"Menu of Italian Restaurant" << endl;
	r1.make_pasta("Chicken");
	r1.make_pasta("White Sauce");
	r1.get_menu();
	
	cout << endl <<"Menu of Mexican Restaurant" << endl;
	r2.make_burrito("Big");
	r2.make_taco("Small");
	r2.get_menu();
	
	cout << endl <<"Menu of Restaurant" << endl;
	r3.add_menu_item("Burger");
	r3.add_menu_item("Pizza");
	r3.add_menu_item("Sandwich");
	r3.get_menu();
	
	
	return 0;
}
