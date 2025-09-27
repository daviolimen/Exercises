#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

const int MAXN = 100100;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return b.second < a.second;
    return a.first < b.first;
}

int n, x1, x2;
pair<int, int> ids[MAXN];

int32_t main() {
    cin >> n >> x1 >> x2;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        ids[i] = {a * x1 + b, a * x2 + b};
    }

    sort(ids, ids + n, cmp);

    oset st;
    int idx = 100100, ans = 0;
    for (int i = 0; i < n; i++) {
        st.insert({ids[i].second, idx});
        int ord = st.order_of_key({ids[i].second, idx});
        ans += st.size() - ord - 1;
        idx--;
    }

    cout << ans << "\n";
}