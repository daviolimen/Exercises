#include <bits/stdc++.h>
using namespace std;

vector<int> getFactors(int x) {
    vector<int> res;
    for (int i = 2; i <= x; i++) {
        while (x % i == 0) {
            res.push_back(i);
            x /= i;
        }
    }
    return res;
}

vector<int> getDivs(int x) {
    vector<int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int dp[1000001];

int solve(int x, int k) {
    if (dp[x] != -2) return dp[x];
    if (x == 1) return 0;
    auto V = getDivs(x);
    int best = INT_MAX;
    for (int i = 1; i < V.size(); i++) {
        if (V[i] > k) break;
        int S = solve(x / V[i], k);
        if (S == -1) continue;
        best = min(best, 1 + S);
    }

    if (best == INT_MAX) return dp[x] = -1;
    return dp[x] = best;
}

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int x, y, k; cin >> x >> y >> k;
        int mdc = gcd(x, y);
        x /= mdc;
        y /= mdc;
        
        for (int i = 0; i <= max(x, y); i++) dp[i] = -2;

        int s1 = solve(x, k), s2 = solve(y, k);

        if ((s1 == -1) || (s2 == -1)) {
            cout << "-1\n";
            continue;
        }

        cout << s1 + s2 << "\n";
    }
}