#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pdd;
typedef pair<string,ll> psl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef vector<vector<pl> > vvp;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
typedef vector<psl> vpsl;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

string min_province;

void generateSubsetSums(const vl& arr, vl& subsetSums) {
    ll n = arr.size();
    for (ll i = 0; i < (1 << arr.size()); ++i) {
        ll subsetSum = 0;
        for (ll j = 0; j < n; ++j) {
            if (i & (1 << j)) { // Check if jth bit is set
                subsetSum += arr[j];
            }
        }
        if(subsetSum > 0) {
            subsetSums.push_back(subsetSum);
        }
    }
}

// int findClosestSum(const vector<ll>& x, const vector<ll>& y, ll k) {
//     vector<ll> z = x;
//     z.insert(z.end(), y.begin(), y.end());

//     ll n = z.size();
//     ll maxSum = accumulate(z.begin(), z.end(), 0);
    
//     vector<bool> dp(maxSum + 1, false);
//     dp[0] = true;
    
//     ll closestSum = 0;

//     for (ll num : z) {
//         for (ll j = maxSum; j >= num; j--) {
//             if (dp[j - num]) {
//                 dp[j] = true;
//                 if (abs(j - k) < abs(closestSum - k)) {
//                     closestSum = j;
//                 }
//             }
//         }
//     }

//     return closestSum;
// }

void sortPairs(vector<pair<long long, string>>& ans) {
    sort(ans.begin(), ans.end(), [](const pair<long long, string>& a, const pair<long long, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second; // Sort alphabetically if the values are equal
        }
        return a.first < b.first; // Sort by value
    });
}

void solve(){
    ll p, n, k,min, max; cin >> p >> n >> k;
    ll total[n], sum;
    vector<pair<ll,string>> ans;
    for(ll i = 0; i < p; i++) {
        string province; 
        getline(cin>>ws, province);
        
        vl a;
        for(ll j = 0; j < n; j++) {
            ll x; cin >> x;
            a.pb(x);
        }
        ll mid = n / 2;
        vl fh(a.begin(), a.begin()+mid);
        vl sh(a.begin()+mid, a.end());

        vl fhs, shs;
        generateSubsetSums(fh, fhs);
        generateSubsetSums(sh, shs);
        sort(fhs.begin(), fhs.end());
        sort(shs.begin(), shs.end());

        // int max = 0;
        // for(auto x: fhs) {  
        //     if(x <= k) {
        //         auto it = lower_bound(shs.begin(), shs.end(), k-x);
        //         int p = distance(shs.begin(), it);
        //         cout << p << " idx ini" << endl;    
        //         cout << k-x << endl;
        //         cout << shs[--p] << endl;
        //         if(p == fhs.size() || shs[p] != k-x) {
        //              p--;
        //         }
        //         if(shs[p]+x > max) {
        //             cout << shs[p] << " come on" << endl;
        //             max = shs[p]+x;
        //         }
        //     }
        // }

        // cout << max << " max per province " << province << endl;

        ll closestSum = INF;
        ll bestSum = 0;
        for (ll leftSum : fhs) {
            ll target = k - leftSum;

            //1,2,3,3,4
            //lower(begin(), end(), 3);
            //auto it = pointer 3
            //*it = 3

            auto it = lower_bound(shs.begin(), shs.end(), target);
            
            // potential cases
            // it = at the end (check once)
            // it = at the beginning (check once)
            // it = at somewhere in between end and beginning (check twice)
            // need more analysis
            
            if (it != shs.end()) {
                ll rightSum = *it;
                if (llabs(leftSum + rightSum - k) < llabs(closestSum - k)) {
                    closestSum = leftSum + rightSum;
                    bestSum = leftSum + rightSum;
                }
            }

            if (it != shs.begin()) {
                ll rightSum = *(--it);
                if (llabs(leftSum + rightSum - k) < llabs(closestSum - k)) {
                    closestSum = leftSum + rightSum;
                    bestSum = leftSum + rightSum;
                }
            }
        }
        
        ans.push_back(mp(llabs(k-bestSum), province));
    }

    sortPairs(ans);

    cout << ans[0].second << endl;
}

int main()
{
    fast_cin();
    solve();
 return 0;
}