#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Memoization vector to store the maximum weight obtainable for each value of N
vector<long long> memo(1001, -1);

// Recursive function to find the maximum weight obtainable
long long maxGoldWeight(int N) {
    // Base case: If N is less than or equal to 0, return 0
    if (N <= 0) return 0;

    // Check if we have already computed the result for this N
    if (memo[N] != -1) return memo[N];

    // Compute the values for the next exchange steps
    int N2 = N / 2;
    int N3 = N / 3;
    int N4 = N / 4;

    // Compute the maximum weight obtainable by exchanging or keeping the original weight
    long long exchangedWeight = maxGoldWeight(N2) + maxGoldWeight(N3) + maxGoldWeight(N4);
    memo[N] = max(static_cast<long long>(N), exchangedWeight);

    return memo[N];

//     maxGoldWeight(12)
// ├── maxGoldWeight(6)
// │   ├── maxGoldWeight(3)
// │   │   ├── maxGoldWeight(1)
// │   │   ├── maxGoldWeight(1)
// │   │   └── maxGoldWeight(0)  (not needed as it’s zero)
// │   ├── maxGoldWeight(2)
// │   │   ├── maxGoldWeight(1)
// │   │   └── maxGoldWeight(0)  (not needed as it’s zero)
// │   └── maxGoldWeight(1)
// ├── maxGoldWeight(4)
// │   ├── maxGoldWeight(2)
// │   │   ├── maxGoldWeight(1)
// │   │   └── maxGoldWeight(0)  (not needed as it’s zero)
// │   ├── maxGoldWeight(1)
// │   └── maxGoldWeight(0)  (not needed as it’s zero)
// └── maxGoldWeight(3)
//     ├── maxGoldWeight(1)
//     ├── maxGoldWeight(1)
//     └── maxGoldWeight(0)  (not needed as it’s zero)

}

int main() {
    int N;
    cin >> N;

    cout << maxGoldWeight(N) << endl;
    return 0;
}
