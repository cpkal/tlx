#include <bits/stdc++.h>
using namespace std;

int main() {
    double a1, b1, a2, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    
    if((double)(a1 / a2) < (double)(b1 / b2)) {
        cout << "lebih kecil\n";
    } else if((double)(a1 / a2) == (double)(b1 / b2)) {
         cout << "sama\n";
    } else {
        cout << "lebih besar\n";
    }

    return 0;
}

// #include <bits/stdc++.h>
// #define dd long double
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     dd A,B,C,D,perbandingan1,perbandingan2;;
//     cin >> A>>B;
//     perbandingan1 = A / B;
//     cout<<"\n";
//     cin >> C>>D;
//     perbandingan2 = C / D;
//     if(perbandingan1 == perbandingan2){
//         cout<<"sama \n";
//     }
//     else if(perbandingan1 < perbandingan2){
//         cout<<"lebih kecil \n";
//     }
//     else if(perbandingan1 > perbandingan2){
//         cout<<"lebih besar \n";
//     }
// }