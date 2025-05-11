#include <iostream>

void count_pairs(int arr[], int N, int K) {
    int hash_table[10000] = {0}; 
    int pair_count = 0;

    for(int i = 0; i < N; i++) {
        int complement = K - arr[i];
        if(complement >= -1000 && complement <= 1000) {
            pair_count += hash_table[complement + 1000]; 
        }

        hash_table[arr[i] + 1000]++; 
    }
    std::cout << "Number of Pairs with Sum " << K << " is: " << pair_count << std::endl;
}

int main() {
	int arr[] = {1, 5, 7, 1};
    int n = 4, k = 6; 
    count_pairs(arr, n, k);

    return 0;
}

