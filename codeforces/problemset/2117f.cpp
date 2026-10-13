#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = (int) 1e9 + 7;

int n;
vector<int> sub;
vector<vector<int>> graph;

int xpow(int x, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        k >>= 1;
    }
    return res;
}

int dfs(int u, int p) {
    sub[u] = 1;
    for (auto v : graph[u]) {
        if (v == p) continue;
        sub[u] += dfs(v, u);
    }
    return sub[u];
}

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n;
        sub = vector<int>(n + 1);
        graph = vector<vector<int>>(n + 1, vector<int>());

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int leaves = 0;
        for (int i = 2; i <= n; i++) {
            if (graph[i].size() == 1) leaves++;
        }

        if (leaves > 2) {
            cout << "0\n";
            continue;
        }

        if (leaves == 1) {
            cout << xpow(2, n) << "\n";
            continue;
        }

        dfs(1, -1);

        int sep = -1;
        for (int i = 2; i <= n; i++) {
            if (graph[i].size() == 3) {
                sep = i;
                break;
            }
        }

        if (graph[1].size() == 2) sep = 1;

        vector<int> nums;
        for (auto x : graph[sep]) nums.push_back(sub[x]);

        sort(nums.begin(), nums.end());

        int X = sub[1] - nums[0] - nums[1] + 1;

        if (nums[0] == nums[1]) {
            cout << xpow(2, X) << "\n";
        } else {
            cout << (xpow(2, X - 1) * ((xpow(2, nums[1] - nums[0] - 1) + xpow(2, nums[1] - nums[0])) % MOD)) % MOD << "\n";
        }
    }
}