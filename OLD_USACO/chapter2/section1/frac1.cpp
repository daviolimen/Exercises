/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: frac1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first * b.second) < (b.first * a.second);
}

int main() {
    ifstream cin ("frac1.in");
    ofstream cout ("frac1.out");
    int n; cin >> n;
    set<pair<int, int>, decltype(cmp)*> st(cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            pair<int, int> P = {j, i};
            int g = gcd(i, j);
            P.first /= g;
            P.second /= g;
            st.insert(P);
        }
    }

    for (auto P : st) cout << P.first << "/" << P.second << "\n";
    return 0;
}