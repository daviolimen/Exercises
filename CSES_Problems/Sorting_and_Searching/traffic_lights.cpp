#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int x, n, sems[MAXN], ans[MAXN];
set<int> st;

int main() {
    cin >> x >> n;
    st.insert(0);
    st.insert(x);

    for (int i = 0; i < n; i++) {
        cin >> sems[i];
        st.insert(sems[i]);
    }

    int best = 0, last = 0;

    for (auto el : st) {
        best = max(best, el - last);
        last = el;
    }

    ans[n - 1] = best;

    for (int i = n - 1; i > 0; i--) {
        auto it = st.find(sems[i]);
        int bef = *(--it);
        int aft = *(++(++it));
        best = max(best, aft - bef);
        ans[i - 1] = best;
        st.erase(st.find(sems[i]));
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == (n - 1)];
    }
}