#include <iostream>
using namespace std;

#define pi_square 6.283

class Shape {
	public:
		virtual void calculateArea() = 0;
};

class Rectangle : public Shape {
	protected:
		float length, width, area;
	public:
		void calculateArea() {
			cout<<"Enter the length of the rectangle: ";
			cin>> length;
			
			cout<<"Enter the width of the rectangle: ";
			cin>> width;
			
			area = length * width;
			cout<<"The area of the rectangle is " << area << " square units." << endl << endl;
		}
};

class Circle : public Shape {
	protected:
		float radius, area;
	public:
		void calculateArea() {
			cout<<"Enter the radius of the circle: ";
			cin>> radius;
			
			area = pi_square * radius;
			cout<<"The area of the circle is " << area << " square units." << endl;
		}
};

int main () {
	Shape* r = new Rectangle;
	Shape* c = new Circle;
	
	r->calculateArea();
	c->calculateArea();
	
	return 0;
}
