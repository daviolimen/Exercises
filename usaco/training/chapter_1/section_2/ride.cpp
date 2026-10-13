/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream cout ("ride.out");
    ifstream cin ("ride.in");
    string a, b; cin >> a >> b;
    int x1 = 1, x2 = 1;
    for (auto c : a) {
        x1 *= (c - 'A' + 1);
        x1 %= 47;
    }
    for (auto c : b) {
        x2 *= (c - 'A' + 1);
        x2 %= 47;
    }
    if (x1 == x2) cout << "GO\n";
    else cout << "STAY\n";
    return 0;
}