#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int ops_total = 0;

    //bandung
    //jakarta

    bool x = false;
    for(int i = 0; i < n; i++) {
        while(a[i] >= b[i]) {
            i++;
             x = true;
        }
        if(x) {
            ops_total++;
            x = false;
        }
    }

    cout << ops_total << endl;
}

int main() {
    
    // bool diff = true;
    // for(int i = 0; i < n; i++) {
    //     if(a[i] > b[i] && diff) {
    //         ops_total++;
    //         diff = false;
    //     } else {
    //         diff = true;
    //     }
    // }

    solve();
    
    // if(ops_total == 0 || ops_total == 1) {
    //     cout << ops_total << endl;
    // } else {
    //     cout << --ops_total << endl;
    // }
    
    return 0;
}