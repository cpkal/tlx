#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    string ans = "";
    int l = 0;

    //1,2,3 
    for(int i = 0; i < n; i++) {
        cout << abs(a[i+1]-a[i]) << endl;
        if(abs(a[i+1]-a[i]) > 1) {
            if(a[l] == a[i]) {
                ans += to_string(a[i]) + ",";
            } else {
                ans += to_string(a[l]);
                ans += "-";
                ans += to_string(a[i]);
                ans += ",";
            }
    
            l = i+1;
        }
    }
    ans.pop_back();
    cout << ans << endl;

    return 0;
}