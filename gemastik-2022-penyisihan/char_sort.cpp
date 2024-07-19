#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) {
            while(i < n && a[i] >= b[i]) i++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}