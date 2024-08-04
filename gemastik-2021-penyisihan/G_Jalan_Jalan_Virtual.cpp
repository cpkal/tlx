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

void solve() {
    int n; cin >> n;
    
    
    for(int i = 0; i < n; i++) {
        int x = 0, y = 0;
        int arah = 1;
        int deretLangkah = 1;
        int m; cin >> m;

        while(m > 0) {
            int langkah = min(m, deretLangkah);

            if(arah == 1) {
                x += langkah;
            } else if(arah == 2) {
                y += langkah;
            } else if(arah == 3) {
                x -= langkah;
            } else if(arah == 0) {
                y -= langkah;
            }
            
            m -= langkah;
            arah += 1;
            arah %= 4;
            deretLangkah++;
        }

        cout << x << " " << y << endl;
    }
}
 
// void jalan(ll &x, ll &y, ll j, ll &a){
//     if(a==0) x=+j;
//     if(a==1) y+=j;
//     if(a==2) x-=j;
//     if(a==3) y-=j;
// }

// void solve(){
//  ll n;
//  cin >> n;
//  for(ll i = 0; i < n; i++){
//     ll x = 0,y = 0,m,l,a;
//     cin >> m;
//     l=m;
//     a=0;

//     for(ll j=1;j<=m;j++){
//         // cout << j << endl;
       

//         if(j>=l){
//             jalan(x,y,l,a);
//             break;
//         }else{
//             jalan(x,y,j,a);
//             l=l-j;
//         }
//         a++;
//         a %= 4;
//     }
//     cout << x << " "<< y <<ln;
//  }
 
// }
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