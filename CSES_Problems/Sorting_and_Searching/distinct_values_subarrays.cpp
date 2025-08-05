#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    set<int> st;
    long long i = 0, j = 0, cnt = 0;
    while (j < n) {
        while (st.find(v[j]) != st.end()) {
            st.erase(v[i++]);
        }
        cnt += j - i + 1;
        st.insert(v[j++]);
    }

    cout << cnt << "\n";
}