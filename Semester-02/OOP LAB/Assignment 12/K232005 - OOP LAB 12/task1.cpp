#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair {
    protected:
        T1 first;
        T2 second;
    public:
        Pair (T1 x, T2 y) {
            first = x;
            second = y;
        }
       
        void display() {
            cout<<"Pair 1 Value: " << first << endl;
            cout<<"Pair 2 Value: " << second << endl;
        }
};

int main() {
    
    cout<< endl <<"Combination #01 [String & Double]" << endl;
    Pair<string, double> p1("this is pair 1", 10.10);
    p1.display();

    cout<< endl <<"Combination #02 [Int & Int]" << endl;
    Pair<int, int> p2(10, 12);
    p2.display();

    cout<< endl <<"Combination #03 [Float & Float]" << endl;
    Pair<float, float> p3(10.102, 12.122);
    p3.display();

    cout<< endl <<"Combination #04 [Int & Float]" << endl;
    Pair<int, float> p4(25, 35.555);
    p4.display();
    return 0;


}