#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t; cin >> t;
    ll lim = 1e6;
    vector<bool> sieve(lim,true);
    vector<ll> primes;

    for(ll i = 2; i <= sqrt(int(lim)); i++) {
        if(sieve[i]) {
            ll j = i * i;
            while(j <= lim) {
                sieve[j] = false;
                j = j + i;
            }
        }
    }

    for(int i = 2; i <= lim;i++) {
        if(sieve[i]) primes.push_back(i);
    }

    ll k[t];
    for(ll i = 0; i < t; i++) {
        cin >> k[i];
        cout << primes[k[i]-1] << endl;
    }
    
    
    return 0;
}