// A Dynamic Programming based C++ program
// for LPS problem returns the length of
// the longest palindromic subsequence
// in seq
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

// Returns the length of the longest
// palindromic subsequence in seq
int lps(string& s1, string& s2, int n1, int n2)
{
    if (n1 == 0 || n2 == 0) {
        return 0;
    }
    if (dp[n1][n2] != -1) {
        return dp[n1][n2];
    }
    if (s1[n1 - 1] == s2[n2 - 1]) {
        return dp[n1][n2] = 1 + lps(s1, s2, n1 - 1, n2 - 1);
    }
    else {
        return dp[n1][n2] = max(lps(s1, s2, n1 - 1, n2),
                                lps(s1, s2, n1, n2 - 1));
    }
}

// Driver program to test above functions
int main()
{
    int n; cin >> n;
    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) {
        int n = s[i].size();
        dp[n][n];
        memset(dp, -1, sizeof(dp));
        string s2 = s[i];
        reverse(s2.begin(), s2.end());
        cout << lps(s2, s[i], n, n) << endl;
        }
    return 0;
}