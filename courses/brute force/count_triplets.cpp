#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a;

bool binSearch(ll r, ll low, ll high) {
    if(high >= low) {
        ll mid = low + (high - low) / 2;
        if(a[mid] == r) return true;
        if(a[mid] > r) return binSearch(r, low, mid - 1);
        if(a[mid] < r) return binSearch(r, mid + 1, high);
    }
    return false;
}

void count(ll& count) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            if(binSearch(-(a[i]+a[j]), 0, a.size()-1)) count++;
        }
    }
}

int main() {
    ll x = 0;
    
    a = {1,2,3,5,6,-4};
    
    count(x);
    
    cout << x << endl;
    

    return 0;
}