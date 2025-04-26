#include <iostream>
using namespace std;

template <class T>
class Maximum {
    protected:
        T first;
        T second;
    public:
        Maximum (T x, T y) {
            first = x;
            second = y;
        }
       
        T compare () {
            if (first>second) {
                cout<<"First value '" << first << "' is greater than second value '" << second <<"'." << endl;
                return first;
            }
           
            else if (first<second) {
                cout<<"Second value '" << second << "' is greater than first value '" << first <<"'." << endl;
                return second;
            }
           
            else {
                cout<<"Both values '" << first << "' and '" << second << "' are equal.";
                return 0;
            }
        }
};

int main() {
   
    Maximum<int> m1(15, 10);
    m1.compare();

    Maximum<float> m2(25.6, 20.3);
    m2.compare();

    Maximum<double> m3(25000, 25000);
    m3.compare();
    return 0;
}