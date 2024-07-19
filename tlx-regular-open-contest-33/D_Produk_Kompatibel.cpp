// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h> 
// #include <complex>
// #include <queue>
// #include <set>
// #include <unordered_set>
// #include <list>
// #include <chrono>
// #include <random>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <stack>
// #include <iomanip>
// #include <fstream>
 
// using namespace std;
 
// typedef long long ll;
// typedef long double ld;
// typedef pair<int,int> pi;
// typedef pair<ll,ll> pl;
// typedef pair<double,double> pdd;
// typedef vector<ll> vl;
// typedef vector<int> vi;
// typedef vector<vector<int> > vvi;
// typedef vector<vector<ll> > vvl;
// typedef vector<vector<pl> > vvp;
// typedef vector<pl> vpl;
// typedef vector<pi> vpi;
// ll MOD = 998244353;
// double eps = 1e-12;
// #define forn(i,e) for(ll i = 0; i < e; i++)
// #define forsn(i,s,e) for(ll i = s; i < e; i++)
// #define rforn(i,s) for(ll i = s; i >= 0; i--)
// #define rforsn(i,s,e) for(ll i = s; i >= e; i--)
// #define ln "\n"
// #define dbg(x) cout<<#x<<" = "<<x<<ln
// #define mp make_pair
// #define pb push_back
// #define fi first
// #define se second
// #define INF 2e18
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((ll)(x).size())

// void solve(){
//     ll n;
//     cin >> n;
//     ll a[n];
//     for(int i = 0; i < n; i++) cin >> a[i];
    
//     bool komp=0;
//     int k=1, para = 0;
//     while(!komp){
//         int p=1
//         for(auto b:a){
//             b+=1;
//             p=*b;
//             if(p%2 == 0){
//                 para++
//             }    
//         }        
//         k++;

//     }
//     if(para == n){
//         cout << 
//     }
    

// }
// int main()
// {
//  fast_cin();
//  ll t;
//  cin >> t;
//  for(int it=1;it<=t;it++) {
//      solve();
//  }
//  return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

// Fungsi untuk menghitung invers modulo
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) x1 += m0;

    return x1;
}

// Fungsi untuk mencari Z yang kompatibel dengan semua k dari 1 hingga N
long long findCompatibleZ(const vector<int>& A) {
    int N = A.size();
    long long P = 1;

    // Hitung P sebagai hasil kali semua elemen A modulo MOD
    for (int i = 0; i < N; ++i) {
        P = (P * A[i]) % MOD;
    }

    long long Z = 0;

    // Iterasi untuk setiap k dari 1 hingga N
    for (int k = 1; k <= N; ++k) {
        long long a = A[k - 1];
        long long b = (P * modInverse(P - a, k)) % k;
        
        Z = (Z + b * (MOD / k) % MOD) % MOD;
    }

    return Z;
}

int main() {
    // Contoh penggunaan
    vector<int> A = {1, 2, 3, 4, 5};
    long long Z = findCompatibleZ(A);
    cout << "Nilai Z yang kompatibel adalah: " << Z << endl;

    return 0;
}
