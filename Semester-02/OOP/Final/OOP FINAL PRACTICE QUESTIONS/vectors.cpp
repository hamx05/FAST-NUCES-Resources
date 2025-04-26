#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector <int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.pop_back();


    for (int i=0; i<vec1.size(); i++) {
        cout << vec1[i] << ", ";
    }

    return 0;
}