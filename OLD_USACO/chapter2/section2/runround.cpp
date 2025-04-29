/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: runround
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool testNum(int n) {
    if (n == 0) return 0;
    unordered_set<int> st;
    vector<int> digs;
    while (n > 0) {
        if (n % 10 == 0) return 0;
        digs.push_back(n % 10);
        if (st.find(n % 10) != st.end()) return 0;
        st.insert(n % 10);
        n /= 10;
    }
    reverse(digs.begin(), digs.end());
    int d = (int) digs.size(), mask = 0, i = 0;
    while (true) {
        if (mask == ((1 << d) - 1)) {
            if (i == 0) return 1;
        }
        if (mask & (1 << i)) {
            return 0;
        }
        mask |= (1 << i);
        i = (i + digs[i]) % d;
    }
}

int main() {
    ifstream cin ("runround.in");
    ofstream cout ("runround.out");
    int m; cin >> m;
    for (int i = m + 1;; i++) {
        if (testNum(i)) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}