#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = (int) 1e9 + 7;

int32_t main() {
    int n, m; cin >> n >> m;
    vector<string> nomes(n);
    for (int i = 0; i < n; i++) cin >> nomes[i];

    vector<int> cnt(m);
    set<char> st;
    for (int i = 0; i < m; i++) {
        st.clear();
        for (int j = 0; j < n; j++) {
            if (st.find(nomes[j][i]) == st.end()) {
                st.insert(nomes[j][i]);
                cnt[i]++;
            }
        }
    }

    int ans = 1;

    for (int i = 0; i < m; i++) ans = (ans * cnt[i]) % MOD;

    cout << ans << "\n";
}