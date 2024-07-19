#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int ops_total = 0;
    bool diff = true;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i] && diff) {
            ops_total++;
            diff = false;
        } else {
            diff = true;
        }
    }
    
    if(ops_total == 0 || ops_total == 1) {
        cout << ops_total << endl;
    } else {
        cout << --ops_total << endl;
    }
    
    return 0;
}