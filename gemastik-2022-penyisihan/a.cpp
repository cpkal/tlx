#include <bits/stdc++.h>
using namespace std;

int main() {
    double a1, b1, a2, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    
    if(a1 / b1 < a2 / b2) {
        cout << "lebih kecil\n";
    } else if(a1 / b1 < a2 / b2) {
         cout << "sama\n";
    } else {
        cout << "lebih besar\n";
    }

    return 0;
}