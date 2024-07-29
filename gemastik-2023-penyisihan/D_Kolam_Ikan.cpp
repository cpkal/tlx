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
ll MAX_N = 100005;
 
 vector<ll> a;
vector<vector<ll>> adj;
vector<bool> visited;
vector<ll> cnt;
ll C = 0;
vector<ll> min_in_component;

void dfs(int v) {
    visited[v] = true;
    // cari minimal vertex di setiap komponen
    cnt[C]++; //hitung anggota di component C
    min_in_component[C] = min(a[v], min_in_component[C]); //cari minimal di component C
  
    for(int u: adj[v]) {
        if(!visited[u]) {
            dfs(u);
        }
    }
}

void solve(){
    ll n, k, b; cin >> n >> k >> b;
    a.resize(n);
    ll minA=INF;
    forn(i, n){
      cin >> a[i];
      minA = min(minA, a[i]);
    }
    
    // vector<vector<ll>> terhubung(n,0);
    
    adj.resize(n);
    visited.resize(n, false);
    min_in_component.resize(n, INF);
    cnt.resize(n, 0);

    ll x, y;
    forn(i, k) {
        cin >> x >> y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1); 
    }

    // 1 2
    // 3 4

    forn(i, n) {
        if(!visited[i]) {
            dfs(i);
            //total komponen
            C++; //pindah index ke ke component C+1
        }
    }

    //4-3 = 3 * 2 = 6
    //2-5 = 2 * 2 = 4
    //6 = 6 * 1 = 6
    //total = 16

    //3-2 = 1 * 2 = 2
    //2-2 = 0 = 0
    //6-2 = 4 * 1 = 4

 
    //2
    //0

    //16 - 4 = 12


    ll res = 0;
    priority_queue<ll> can;
    for(int i = 0; i < C; i++) {
        res += min_in_component[i] * cnt[i];
        can.push((min_in_component[i] - minA) * cnt[i]); //hitung kontribusi 
    }

    while(!can.empty() && b--) {
        res -= can.top();
        can.pop();
    }
    
    cout << res << endl;

}
int main()
{
 fast_cin();
 solve();
 return 0;
}