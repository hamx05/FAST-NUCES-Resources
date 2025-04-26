#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Date {
	private:
		unsigned int dd, mm, yy;
		
	public:
		// Constructors
		Date() { }
		Date(unsigned int d, unsigned int m, unsigned int y) : dd(d), mm(m), yy(y) { }
		
		// Operators
		bool operator <= (const Date &other) {
			return (yy < other.yy) || (yy == other.yy && mm < other.mm) || (yy == other.yy && mm == other.mm && dd <= other.dd);
		}
		
		bool operator >= (const Date &other) {
        	return (yy > other.yy) || (yy == other.yy && mm > other.mm) || (yy == other.yy && mm == other.mm && dd >= other.dd);
    	}
};

class Order {
	public:
		int item_id;
		int quantity;
		string r_code;

		Order(int item, int q, string rc) : item_id(item), quantity(q), r_code(rc) { }
};

class Restaurant {
	private:
		static int coupons_redeemed_count;
		string restaurant_name;
		string location;
		string r_code;
		vector<string> menu_list;
		vector<int> price_list;
		vector<string> valid_coupon_codes_list;
		int bill;
		
	public:
		// Constructors
		Restaurant() { }
		Restaurant(string name, string loc, string code) : restaurant_name(name), location(loc), r_code(code), bill(0) { }
		
		// Member Functions
		void display_menu() {
		    cout << "* " << restaurant_name << " Menu *" << endl;
		    cout << "------------------------" << endl;
		    cout << left << setw(15) << "#  Item Name" << "Price" << endl;
		    cout << "------------------------" << endl;
		    
		    for(int i = 0; i < menu_list.size(); i++) {
		        cout << i+1 << ". " << left << setw(15) << menu_list[i] << price_list[i] << endl;
		    }
		    cout << "------------------------" << endl << endl;
		}
		
		void generate_bill(Order& order) {
			if(order.r_code == r_code) {
				int item_id = order.item_id;
				bill += order.quantity * price_list[item_id-1];
			}
		}
		
		void apply_discount(Order& order) {
			bill -= price_list[order.item_id-1]; // discount for current order
		}
		
		void addItem(string name, int price) {
			menu_list.push_back(name);
			price_list.push_back(price);
		}
		
		string getCode() { return r_code; }
		
		string getName() { return restaurant_name; }
		
		string getItemName(int id) { 
			if(id > 0 && id <= menu_list.size())
				return menu_list[id-1];
			return "#Item Not Found#";
		}
		
		int getBill() { return bill; }
};

class BOGOCoupon {
	private:
		string coupon_code;
		Date valid_from;
		Date valid_until;
		string restaurant_code;
	
	public:
		// Constructors
		BOGOCoupon(string code, Date start, Date end, string r_code) : coupon_code(code), valid_from(start), valid_until(end), restaurant_code(r_code) { }
		
		// Member Functions
		bool is_valid(Date date, string r_code) {
			return ((date >= valid_from && date <= valid_until) && restaurant_code == r_code);
		}
		
		string getCode() { return coupon_code; }
};

class User {
	private:
		string name;
		int age;
		int mobile_number;
		vector<BOGOCoupon> coupons_list;
		vector<BOGOCoupon> redeemed_coupons_list;
		vector<Order> order_list;
		Date order_date;
		
	public:
		// Constructors
		User() { }
		User(string _name, int _age, int number, Date orderDate) : name(_name), age(_age), mobile_number(number), order_date(orderDate) { }
		
		// Member Functions
		void accumulate_coupon(BOGOCoupon& coupon) {
			coupons_list.push_back(coupon);
		}
		
		int has_valid_coupon(Restaurant& restaurant) {
			string r_code = restaurant.getCode();
			for(int i = 0; i < coupons_list.size(); i++) {
				if(coupons_list[i].is_valid(order_date, r_code) && !is_redeemed_before(coupons_list[i]))
					return i;
			}
			return -1;
		}
		
		void redeem_coupon(Restaurant& restaurant, Order& order) {
			int couponIndex = has_valid_coupon(restaurant);

			if(couponIndex != -1) {
				redeemed_coupons_list.push_back(coupons_list[couponIndex]);
				cout << "Successfully Redeemed Coupon: " << coupons_list[couponIndex].getCode() << endl;
				coupons_list.erase(coupons_list.begin() + couponIndex); // remove the used coupon from list
				restaurant.apply_discount(order);
			}
			else {
				cout << "No valid coupons found for restaurant: " << restaurant.getName() << endl;
			}
		}
		
		bool is_redeemed_before(BOGOCoupon& coupon) {
			for(int i = 0; i < redeemed_coupons_list.size(); i++) {
				if(redeemed_coupons_list[i].getCode() == coupon.getCode())
					return true;
			}
			return false;
		}
		
		void place_order(Restaurant& restaurant, Order order) {
			order_list.push_back(order);
			cout << "You ordered: " << restaurant.getItemName(order.item_id) << " x" << order.quantity << endl;
			restaurant.generate_bill(order);
			cout << "Current Bill for " << restaurant.getName() << ": " << restaurant.getBill() << endl;
		}
};

// Static Member Init.
int Restaurant::coupons_redeemed_count = 0;

int main() {
    Date currentDate(20, 2, 2024);

    Restaurant FH("Food Haven", "City Center", "FH");
    FH.addItem("Sushi", 10);
    FH.addItem("Pad Thai", 20);
    FH.addItem("Mango Tango", 30);
    
    Restaurant PB("Pixel Bites", "Cyber Street", "PB");
    PB.addItem("Binary Burger", 40);
    PB.addItem("Quantum Quinoa", 50);
    PB.addItem("Data Donuts", 60);

    BOGOCoupon c1("FH-BOGO-12345", Date(20, 1, 2024), Date(20, 2, 2024), "FH");
    BOGOCoupon c2("PB-BOGO-67890", Date(1, 2, 2024), Date(1, 3, 2024), "PB");

    User user1("Yousuf", 20, 12345, currentDate);
    user1.accumulate_coupon(c1);
    user1.accumulate_coupon(c2);

    bool exit = false;

    while(!exit) {
    	cout << "--- Program Menu ---\n";
        cout << "1. Display Food Haven menu\n";
        cout << "2. Display Pixel Bites menu\n";
        cout << "3. Place an order\n";
        cout << "4. Display Bill\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                FH.display_menu();
                break;

            case 2:
                PB.display_menu();
                break;

            case 3: {
                int restaurantChoice, itemChoice, quantity;
                char couponChoice;
                
                cout << "Choose a restaurant (1-Food Haven OR 2-Pixel Bites): ";
                cin >> restaurantChoice;

                Restaurant& rest = (restaurantChoice == 1) ? FH : PB;
				
				rest.display_menu();
				
                cout << "Choose an item (by number): ";
                cin >> itemChoice;

                cout << "Enter quantity: ";
                cin >> quantity;
				
				Order order(itemChoice, quantity, rest.getCode());
                user1.place_order(rest, order);
                
                if(quantity > 1 && user1.has_valid_coupon(rest) != -1) {
                	cout << "Would you like to use coupon for this order? (Y/N): "; cin >> couponChoice;
					if(tolower(couponChoice) == 'y') {
						user1.redeem_coupon(rest, order);
						cout << "Discounted Bill: " << rest.getBill();
					}
				}
                break;
            }
            
            case 4: {
            	int restaurantChoice;
            	cout << "Choose a restaurant (1-Food Haven OR 2-Pixel Bites): ";
            	cin >> restaurantChoice;
            	Restaurant& rest = (restaurantChoice == 1) ? FH : PB;
            	cout << "Current Bill for " << rest.getName() << ": " << rest.getBill() << endl;
				break;
			}
			
            case 5:
                exit = true;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        cout<< endl;
    }

    return 0;
}
