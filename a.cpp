#include <iostream>
#include <vector>
#include <algorithm>

// Function to check if the game can be won with a given initial power X
bool canWinGame(int X, const std::vector<int>& enemies) {
    int current_power = X;
    for (int power : enemies) {
        if (current_power <= power) {
            return false; // The game is lost
        }
        current_power += power;
    }
    return true; // The game can be won
}

// Function to find the minimum initial power X needed to win the game
int find_min_initial_power(std::vector<int>& enemies) {
    std::sort(enemies.begin(), enemies.end());
    int low = 1, high = 1e9, result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canWinGame(mid, enemies)) {
            result = mid;
            high = mid - 1; // Try to find a smaller valid X
        } else {
            low = mid + 1; // Increase X
        }
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> enemies(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> enemies[i];
    }
    
    int result = find_min_initial_power(enemies);
    std::cout << result << std::endl;
    
    return 0;
}
