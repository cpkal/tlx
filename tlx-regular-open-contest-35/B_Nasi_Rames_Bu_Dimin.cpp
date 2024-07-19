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
    // n =modal , k= gram poersi, m= harga porsi, a=gram osana ( 2 kali b), b=gram najimi  
    //cari total banyak porsi

    /*
    a = 1000
    b = 300
    k = 250
    
    totalB= b/k
    totalA= totalB*2
    loop terus jika porsi a,b masih melebihi max 
        if totalA<a maka totalb=b-1, totala=b*2
    end
    loop terus jika harga masih mahal
    totalharga= a+b*m
        if totalharga>n maka total a-2, b-1
    end
    */
    int n,m,k,a,b, ans; 
    cin >> n >> m >> k >> a >> b;
    int porsiB,porsiA;

    porsiB = b/k;
    porsiA = porsiB*2;

    while((porsiA*k)>a || (porsiB*k)>b){
        porsiB-=1;
        porsiA=porsiB*2;
    }
    while((porsiA+porsiB)*m > n){
        porsiB-=1;
        porsiA=porsiB*2;
    }

    cout<< porsiA+porsiB <<endl;

    // ans = (n/m);
    // if(ans % 2 == 0){
    //     a;
    // }
    // else{
    //     a;
    // }
    // b = a/2;
    // ans = a+b;
    // int harga;
    // harga = (ans * m);
    // if(harga  < n) cout << ans;
    // else{
    //     ans = ans - 1;
    // }
}
int main()
{
 fast_cin();
 solve();
 return 0;
}