#include <bits/stdc++.h>
using namespace std;

int n;
string seq;

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char c; cin >> c; seq.push_back(c);
    }

    int ans;

    for (int s = 1; s <= n; s++) {
        set<string> st;
        bool ok = true;

        for (int i = 0; i < n - s + 1; i++) {
            string curr = seq.substr(i, s);
            if (st.find(curr) != st.end()) {
                ok = false;
                break;
            }

            st.insert(curr);
        }

        if (ok) {
            ans = s;
            break;
        }
    }

    cout << ans << "\n";
}