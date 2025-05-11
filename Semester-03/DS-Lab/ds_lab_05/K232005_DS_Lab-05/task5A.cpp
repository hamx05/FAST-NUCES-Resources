#include <iostream>
using namespace std;

void print(int n, int gap) {

    if (n > 30) {
        return;
    }

    cout << n << " ";
    gap++;
    n = n + gap;
    return print(n, gap);


}

int main () {

    static int gap = 1;
    print(1, gap);

    return 0;
}