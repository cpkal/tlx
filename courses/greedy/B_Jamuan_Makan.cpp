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

bool comp(pair <ll, ll>& a, pair<ll, ll>& b) {
    return a.second < b.second;
}

void solve(){
    ll n;
    cin >> n;
    vpl a;
    for(int i=0; i<n; i++){
        ll x, y; cin >> x >> y;
        y += x;
        a.pb(mp(x, y));
    }

    sort(a.begin(), a.end(), comp);
    ll ans = 0;
    ll last_end = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].first >= last_end) {
            ans++;
            last_end = a[i].second;
        }
    }
    cout << ans << endl;

    // int ans=n;
    // for(int i=1; i<n; i++){
    //     if(a[i].first==a[i-1].first){
    //         if(a[i].second>a[i-1].second){
    //             a[i].first=-1;
    //         }else{
    //             a[i-1].first=-1;
    //         }
    //         ans--;
    //     }
        
    //     if(a[i-1].first !=-1 && a[i].first !=-1 && (a[i-1].first+a[i-1].second) > a[i].first) ans--;
    // }
    // cout << ans << endl;
}
int main()
{
    fast_cin();
    solve();
 return 0;
}