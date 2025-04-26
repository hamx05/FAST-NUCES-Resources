#include <iostream>
using namespace std;

int maxArea(int A[], int length) {
    int area = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            area = max(area, min(A[j], A[i]) * (j - i));
        }
    }
    return area;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // taken from the example in lab manual

    int length = sizeof(height) / sizeof(height[0]);
    cout << "The maximum area of water the container can contain is "<< maxArea(height, length) << " square units." << endl;

    return 0;
}
