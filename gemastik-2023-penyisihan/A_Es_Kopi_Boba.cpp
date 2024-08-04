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
 

void solve(){
    ll n; cin >> n;
    if(n > 1000 && n < 1){
        return;
    }
    ll v[n];
    ll sum = 0;
    ll min = 10e5+1;
    ll max = 0;
    ll imin = n;
    ll imax = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
        if(min > v[i]) {
            min=v[i];
            imin=i;
        }

        if(max < v[i]) {
            max = v[i];
            imax = i;
        }
    }
    ll avg = sum/n;
    ll diff = 0;
    bool ans = true;
    for(int i = 0; i < n; i++) {
        if(v[i] != avg) {
            diff++;
            ans = false;
        }
        if(diff > 2) {
            cout << "TIDAK SESUAI\n";
            return;
        }
    }

    if(ans) {
        cout << "SESUAI\n";
    } else if(diff > 1) {
        cout << (max - min)/2 << " " << imax+1 << " " << imin+1 << endl;
    } 
    
}
int main()
{
 fast_cin();
 solve();
 return 0;
}