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

// Function to find the closest sum to target in a sorted vector of sums
int findClosestSum(const vl& sums, ll target) {
    int lo = 0, hi = sums.size() - 1;
    int closest_sum = INT_MAX;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (sums[mid] == target) {
            return sums[mid];
        } else if (sums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        
        // Update closest_sum
        if (abs(sums[mid] - target) < abs(closest_sum - target)) {
            closest_sum = sums[mid];
        }
    }
    
    return closest_sum;
}



void solve(){
    ll p, n, k,min, max; cin >> p >> n >> k;
    ll total[n], sum, selisih[n];
    vpsl ans;
    for(ll i = 0; i < p; i++) {
        string province; 
        getline(cin>>ws, province);
        
        vl a;
        for(ll j = 0; j < n; j++) {
            ll x; cin >> x;
            a.pb(x);
             sum += x;
        }
        total[i] = sum;
        // diluar for / for baru
        for(ll i = 0; i < p; i+=2){
        selisih[i] = total[i] - k;

         if(selisih[i] < selisih[i+1] ){
            
         }
        }
   
    
}

int main()
{
    fast_cin();
    solve();
 return 0;
}