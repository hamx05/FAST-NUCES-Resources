#include <iostream>

void find_triplet(int arr[], int size) {
	bool found = false;
    for(int i=0; i < size - 2; i++) {
        int hash[2001] = {0};
        for(int j = i + 1; j < size; j++) {
            int complement = -(arr[i] + arr[j]);
            if(complement >= -1000 && complement <= 1000 && hash[complement + 1000] > 0) {
                std::cout << "Triplet found: " << arr[i] << " " << arr[j] << " " << complement << std::endl;
                found = true;
            }
            hash[arr[j] + 1000] = 1; 
        }
    }

    if(!found) {
        std::cout << "Triplet not found" << std::endl;
    }
}

int main() {
    int arr[] = {0, -1, 2, -3, 1};
    int size = 5;
    find_triplet(arr, size);

    return 0;
}

