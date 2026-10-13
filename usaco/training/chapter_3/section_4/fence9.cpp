/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: fence9
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("fence9.in");
    ofstream cout ("fence9.out");
    int n, m, p; cin >> n >> m >> p;
    int crossProd = m * p;
    int onLinePts = gcd(n, m) + gcd(abs(p - n), m) + gcd(p, 0);
    cout << (crossProd - onLinePts + 2) / 2 << "\n";
    return 0;
}