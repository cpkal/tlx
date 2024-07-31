#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

bool isPerfectSquare(int num) {
    int root = sqrt(num);
    return root * root == num;
}

bool isKeren(const vector<int>& subseq) {
    int size = subseq.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (isPerfectSquare(subseq[i] * subseq[j])) {
                return true;
            }
        }
    }
    return false;
}

void generateSubsequences(const vector<int>& A, int k, vector<vector<int>>& subsequences, vector<int>& current, int index) {
    if (current.size() == k) {
        subsequences.push_back(current);
        return;
    }
    if (index >= A.size()) return;

    // Include current element
    current.push_back(A[index]);
    generateSubsequences(A, k, subsequences, current, index + 1);

    // Exclude current element
    current.pop_back();
    generateSubsequences(A, k, subsequences, current, index + 1);
}

bool isAllSubsequencesKeren(const vector<int>& A, int k) {
    vector<vector<int>> subsequences;
    vector<int> current;
    generateSubsequences(A, k, subsequences, current, 0);

    for (const auto& subseq : subsequences) {
        if (!isKeren(subseq)) {
            return false;
        }
    }
    return true;
}

int findMinimumK(const vector<int>& A) {
    int n = A.size();
    if (n < 2) return -1;

    int left = 2;
    int right = n;
    int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isAllSubsequencesKeren(A, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    ll n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    int result = findMinimumK(A);
    cout << result << endl;  // Output: 2
    return 0;
}
