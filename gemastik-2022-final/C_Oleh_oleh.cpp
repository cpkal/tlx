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
 
 vl a;
vvl adj;
vector<bool> visited;
vl cnt;
// vector<ll> min_in_component;
ll C = 0;


void dfs(ll x, ll v, ll &price) {
    visited[v] = true;
    cnt[C]++; //hitung anggota di component C
    // min_in_component[C] = min(a[v], min_in_component[C]); 
    price+=x;
    for(auto a: adj[v]) {
        if(!visited[a]) {
            dfs(x, a, price);
        }
    }
}

//comparator
bool sortByKey(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.first < b.first;
}


void solve(){
    ll n, m; cin >> n >> m;
    
    a.resize(n+1);
    adj.resize(n+1);
    visited.resize(n+1, false);
    cnt.resize(n+1, 0);
    // min_in_component.resize(n+1, INF);

    vpl node;
    forn(i, n) {
        cin >> a[i];
        node.pb(mp(a[i], i));
    }

    sort(node.begin(), node.end(), sortByKey);

    forn(i, m) {
        ll x, y; cin >> x >> y;
        adj[x-1].pb(y-1);
    }

    ll price = 0;
    for(const auto &p: node) {
        if(!visited[p.second]) {
            dfs(p.first, p.second, price);
        }
    }

    cout << price << endl;

    // ll res = 0;
    // forn(i, C) {
    //     res += (min_in_component[i] * cnt[i]);
    // }
    
    // cout << res << endl;
}
int main()
{
 fast_cin();
 solve();
 return 0;
}