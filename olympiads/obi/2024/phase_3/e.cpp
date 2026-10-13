#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 100100, MOD = (int) 1e9 + 7;

int N, M, K;
pair<int, int> F[MAXN], R[MAXN];

int aplicar(bool flag, int idx, int x) {
    if (flag) {
        return (((x * R[idx].first) % MOD) + R[idx].second) % MOD;
    }
    return (((x * F[idx].first) % MOD) + F[idx].second) % MOD;
}

int retSeq(const vector<pair<int, int>> &seq, int x) {
    int res = x;
    for (auto P : seq) res = aplicar(P.first, P.second, res);
    return res;
}

int32_t main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> F[i].first;
    for (int i = 0; i < N; i++) cin >> F[i].second;
    for (int i = 0; i < M; i++) cin >> R[i].first;
    for (int i = 0; i < M; i++) cin >> R[i].second;
    int Q; cin >> Q;
    while (Q--) {
        int x; cin >> x;
        int ans = 0;
        vector<vector<pair<int, int>>> ords = {
            {{0, 0}, {0, 0}, {1, 0}, {1, 1}},
            {{0, 0}, {0, 0}, {1, 1}, {1, 0}},
            {{0, 1}, {0, 1}, {1, 0}, {1, 1}},
            {{0, 1}, {0, 1}, {1, 1}, {1, 0}},
            {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
            {{0, 0}, {0, 1}, {1, 1}, {1, 0}},
            {{0, 1}, {0, 0}, {1, 1}, {1, 0}},
            {{0, 1}, {0, 0}, {1, 0}, {1, 1}},
            {{1, 0}},
            {{1, 1}},
            {{0, 0}},
            {{0, 1}},
            {},
            {{0, 0}, {0, 0}},
            {{0, 1}, {0, 1}},
            {{0, 0}, {0, 1}},
            {{0, 1}, {0, 0}},
            {{1, 0}, {1, 1}},
            {{1, 1}, {1, 0}},
            {{0, 0}, {0, 0}, {1, 0}},
            {{0, 0}, {0, 0}, {1, 1}},
            {{0, 1}, {0, 1}, {1, 0}},
            {{0, 1}, {0, 1}, {1, 1}},
            {{0, 1}, {0, 0}, {1, 0}},
            {{0, 1}, {0, 0}, {1, 1}},
            {{0, 0}, {0, 1}, {1, 1}},
            {{0, 0}, {0, 1}, {1, 0}}
        };

        for (auto V : ords) {
            ans = max(ans, retSeq(V, x));
        }

        cout << ans << "\n";
    }
}