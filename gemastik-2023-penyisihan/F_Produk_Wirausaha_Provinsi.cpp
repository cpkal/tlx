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
    int n = arr.size();
    for (int i = 0; i < (1 << arr.size()); ++i) {
        int subsetSum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) { // Check if jth bit is set
                subsetSum += arr[j];
            }
        }
        subsetSums.push_back(subsetSum);
    }
}

void solve(){
    ll p, n, k,min, max; cin >> p >> n >> k;
    ll total[n], sum;
    vpsl ans;
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

        int x = INF;
        
        for(auto f: fhs) {
            ll loc = lower_bound(shs.begin(), shs.end(), k - f) - shs.begin();
            if(loc == shs.size()) loc--;
            
            vector<ll> el = {loc, loc-1, loc+1};
            for(auto d: el) {
                if(d >= 0 && d < shs.size() && llabs(k - shs[d]+f) <= x && (shs[d]+f) != 0) {
                    if(llabs(k - (shs[d]+f)) == x) {
                        if(province < min_province) min_province = province;
                    } else {
                        min_province = province;
                    }
                    x = llabs(k - (shs[d]+f));
                }
            }
        }

        // ans.pb(mp(province, x)); 
    }
    cout << min_province << endl;
}

int main()
{
    fast_cin();
    solve();
 return 0;
}