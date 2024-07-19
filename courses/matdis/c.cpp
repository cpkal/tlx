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
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef vector<vector<pl> > vvp;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}



void solve(){
    ll n; cin >> n;
    ll d[n];
    ll oGcd = 0;
    cin >> d[0];
    long long int res = 1;
    for(ll i = 1; i < n; i++) {
        cin >> d[i];
        //lcm = a*...n / gcd(a...n)
        
        //gcd
        if(oGcd == 0) {
            oGcd = gcd(d[0], d[i]);
            // res = d[i-1] / oGcd * d[i];
        } else {
            oGcd = gcd(oGcd, d[i]);
            // cout << res * d[i] << endl;
            // res = res / oGcd * d[i];
        }
    }

    for(ll i = 1; i < n; i++) {
        if(i == 1) {
            res = d[i-1] / oGcd * d[i];
        } else {
            res = res / oGcd * d[i];
        }
    }

    cout << res << endl;
}
int main()
{
 fast_cin();
  solve();
 return 0;
}