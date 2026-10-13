/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: humble
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int k, n;
long long prec[101][32];

int main() {
    ifstream cin ("humble.in");
    ofstream cout ("humble.out");
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        prec[i][0] = 1;
        cin >> prec[i][1];
        for (int j = 2; j < 32; j++) {
            prec[i][j] = prec[i][j - 1] * prec[i][1];
            if (prec[i][j] > INT_MAX) break;
        }
    }

    set<long long> st;
    st.insert(1);
    for (int i = 0; i < k; i++) {
        vector<long long> toAdd;
        for (int j = 1; j < 32; j++) {
            if (prec[i][j] > INT_MAX) break;
            for (auto x : st) {
                long long tmp = x * prec[i][j];
                if (tmp > INT_MAX) break;
                if (st.size() > 100010) {
                    auto rbg = st.rbegin();
                    if (tmp >= *rbg) break;
                    st.erase(*rbg);
                }
                toAdd.push_back(x * prec[i][j]);
            }
        }
        
        for (auto x : toAdd) st.insert(x);
    }

    auto it = st.begin();
    advance(it, n);
    cout << *it << "\n";
    return 0;
}