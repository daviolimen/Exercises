/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: prefix
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("prefix.in");
    ofstream cout ("prefix.out");
    set<string> st;
    while (true) {
        string prim; cin >> prim;
        if (prim == ".") break;
        st.insert(prim);
    }
    string s, S = "0";
    while (cin >> s) {
        S += s;
    }
    int N = S.size() - 1;
    vector<bool> dp(N + 100);
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (!dp[i]) continue;
        for (int j = 1; j <= 10; j++) {
            if (i + j > N) break;
            string test = S.substr(i + 1, j);
            if (st.find(test) == st.end()) continue;
            dp[i + j] = 1;
        }
        if (dp[i]) ans = max(ans, i);
    }

    cout << ans << "\n";
    return 0;
}