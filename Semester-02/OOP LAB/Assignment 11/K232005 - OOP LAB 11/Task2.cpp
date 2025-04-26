#include <iostream>
using namespace std;

class Animals {
	public:
		virtual void cat () const = 0;
		virtual void dog () const = 0;
};

class Cats : public Animals {
	public:
		void cat () const {
			cout<<"Cats meow!" << endl;
		}
		void dog () const {}
};

class Dogs : public Animals {
	public:
		void dog () const {
			cout<<"Dogs bark!" << endl;
		}
		void cat () const {}
};

int main () {
	
	Animals* c = new Cats;
	Animals* d = new Dogs;
	
	c->cat();
	d->dog();
	
	
	return 0;
}
