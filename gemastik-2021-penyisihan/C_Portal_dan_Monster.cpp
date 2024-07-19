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

vector<bool> visited;
vector<vector<int>> adj;

ll dfs(int v, ll musuh[]) {
    visited[v] = true;
    ll sum = musuh[v-1];
    for(int u: adj[v]) {
        if(!visited[u]) {
            sum += dfs(u, musuh);
        }
    }

    return sum;
}

void solve(){
    ll n,k; cin >> n >> k;

    ll musuh[n];
    for(ll i = 0; i < n; i++) cin >> musuh[i];
    adj.resize(n+1);
    visited.resize(n+1, false);

    for(ll i=0; i<k; i++){
        ll a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi listsum;
    for(int i=1;i<=n; i++){
        if(!visited[i]) {
            ll sum = dfs(i, musuh);
            listsum.pb(sum);
        }
    }
    
    sort(listsum.begin(), listsum.end(), greater<ll>());
    ll ans = 0;
    for(int i = 0; i < listsum.size(); i++) {
        ans += listsum[i] * (i + 1);
    }
    cout << ans << endl;
    
}

int main()
{
 fast_cin();
 solve();
 return 0;
}