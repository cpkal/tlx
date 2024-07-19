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
    string s;
    cin >> s;
    for(int i = 0; i < s.length()-1; i+=2) {
        if(string()+s[i]+s[i+1]=="AA"){
            cout<<"BB";
        }   
        else if(string()+s[i]+s[i+1]=="AB"){
            cout<<"BD";
        }
        else if(string()+s[i]+s[i+1]=="AC"){
            cout<<"DD";
        }
        else if(string()+s[i]+s[i+1]=="AD"){
            cout<<"CA";
        }
        else if(string()+s[i]+s[i+1]=="BA"){
            cout<<"CD";
        }
        else if(string()+s[i]+s[i+1]=="BB"){
            cout<<"AA";
        }
        else if(string()+s[i]+s[i+1]=="BC"){
            cout<<"AC";
        }
        else if(string()+s[i]+s[i+1]=="BD"){
            cout<<"BC";
        }
        else if(string()+s[i]+s[i+1]=="CA"){
            cout<<"AB";
        }
        else if(string()+s[i]+s[i+1]=="CB"){
            cout<<"CC";
        }
        else if(string()+s[i]+s[i+1]=="CC"){
            cout<<"DB";
        }
        else if(string()+s[i]+s[i+1]=="CD"){
            cout<<"CB";
        }
        else if(string()+s[i]+s[i+1]=="DA"){
            cout<<"BA";
        }
        else if(string()+s[i]+s[i+1]=="DB"){
            cout<<"DC";
        }
        else if(string()+s[i]+s[i+1]=="DC"){
            cout<<"AD";
        }
        else if(string()+s[i]+s[i+1]=="DD"){
            cout<<"DA";
        }
        else {
            return;
        }
    }
}
int main()
{
 fast_cin();
 solve();
 return 0;
}