#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

const int MAXN = 100100;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, X1, X2;
pair<int, int> ids[MAXN];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return b.second < a.second;
    return a.first < b.first;
}

int32_t main() {
    cin >> N >> X1 >> X2;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        ids[i] = {a * X1 + b, a * X2 + b};
    }

    sort(ids, ids + N, cmp);

    oset st;
    int idx = 100100, ans = 0;
    for (int i = 0; i < N; i++) {
        st.insert({ids[i].second, idx});
        int ord = st.order_of_key({ids[i].second, idx});
        ans += st.size() - ord - 1;
        idx--;
    }

    cout << ans << "\n";
}