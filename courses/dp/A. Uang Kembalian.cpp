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

vector<long long> memo;
 
 ll coin(ll k, ll n, ll c[], ll ans){
    if (k==0){
        return 0;
    }
    if (k < 0) return INF;
    if (memo[k] != -1) return memo[k];
    for (ll i=0; i<n;i++){
        if(c[i]<=k){
            ans = min(ans, coin(k-c[i], n, c, ans)+1);
        }
    }
    memo[k] = (ans == INF) ? -1 : ans;
    return ans;
 }

// bottom-up
 int minCoins(int k, int a[], int n) {
    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0; 

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] <= i && dp[i - a[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    return (dp[k] == INT_MAX) ? -1 : dp[k];
}

void solve(){
    ll n, k; cin >> n;
    ll c[n];
    forn(i, n){
        cin>>c[i];
    }
    cin>>k;
    ll ans=INF;
     memo.assign(k + 1, -1);
    ans=coin(k, n, c, ans);
    cout<<ans;
}
int main()
{
 fast_cin();
 solve();
 return 0;
}