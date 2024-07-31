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

ll const MAX = 1e7 + 5;
vector<ll> sieve(MAX, 0);
vector<ll> primes;

void precom() {
    for(int i = 2; i * i <= MAX; i++) {
        if(sieve[i] == 1) continue;
        for(int j = i * i; j <= MAX; j+=i) {
            sieve[j] = 1;
        }
    }
    
    for(int i = 2; i <= MAX; i++) {
        if(sieve[i] == 0) {
            primes.push_back(i);
        }
    }
}

int main() {
    precom();
    ll n; cin >> n;
    vector<ll> A(n + 5);
    for(int i = 0; i < n; i++) cin >> A[i];
    map<ll, ll> mp;
    ll res = 0;
    for(int i = 0; i < n; i++) {
        for(auto prime: primes) {
            while(A[i] % (prime * prime) == 0) A[i] /= (prime*prime);
            if(prime * prime > A[i]) break;
        }
        //2,3,5

        //2,2,3,5

        if(mp[A[i]] == 0) {
            mp[A[i]]++;
            res++;
        }
    }
    
    res++;
    
    if(res > n) {
        cout << -1 << endl;
    } else {
        
        cout << res << endl;
    }
    
    return 0;
}