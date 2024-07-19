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
    int n, keuntungan=0; cin >> n;
    // if(n > 1000000){
    //     break;
    // }
    int a[n];
    bool b=0;
    // int ans = 0;
    // int num;
    // for(int i = 0; i < n; i++){
    //     cin >> num;
    //     if(i > 0 && num > l) ans += num - l;
    //     l = num;
    //     // if(a[i-1]<a[i]){
    //     //     l=i-1;
    //     // }
    //     // if()
    // }

    // cout << ans << endl;

    int l;
    int r = l + 1;

    int globalKeuntungan = 0;

    if(n == 1) {
        cout << 0 << endl;
    } else if(n == 2) {
        if(a[0] > a[1]) cout << 0 << endl;
        if(a[0] < a[1]) cout << a[1] - a[0] << endl;
    }else{
        while(r < n) {
            if(a[l] > a[r]) {
                l = r;
                r = l + 1;
                
            } else {
                if(a[r-1] > a[r]) {
                    globalKeuntungan += a[r-1] - a[l];
                    l = r + 1;
                }
                // if()
                r++;
            }
        }

        cout << globalKeuntungan << endl;
    }


    // for(int i = 0; i < n - 1; i++) {
    //     if(b){
    //         if(a[i] > a[i+1]) {
    //             b=0;
    //             keuntungan+=a[i];
    //         }
            
    //     }else{
    //         if(a[i] < a[i+1]) {
    //             b=1;
    //         }
    //     }
    // }
    // if(keuntungan>0){
    //     cout <<keuntungan;
    // }else{
    //     cout <<0;
    // }
}
int main()
{
 fast_cin();
//  ll t;
//  cin >> t;
//  for(int it=1;it<=t;it++) {
     solve();
//  }
 return 0;
}