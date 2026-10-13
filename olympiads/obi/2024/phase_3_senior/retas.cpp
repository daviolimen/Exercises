#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MAXN 100100
#define int long long

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, X1, X2, A[MAXN], B[MAXN];

bool cmp(const array<int, 4> &a, const array<int, 4> &b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int32_t main() {
    cin >> N >> X1 >> X2;
    vector<array<int, 4>> f1;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        array<int, 4> ski = {A[i] * X1 + B[i], A[i] * X2 + B[i], A[i], B[i]};
        f1.push_back(ski);
    }

    sort(f1.begin(), f1.end(), cmp);
    oset aura;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int f2 = f1[i][1];
        //cout << "f1: " << f1[i][0] << ", f2: " << f2 << " " << f1[i][1] << " " << f1[i][2] << "\n";
        ans += aura.size() - aura.order_of_key({f2, N - i - 1});
        aura.insert({f2, N - i - 1});
    }

    cout << ans << "\n";
}