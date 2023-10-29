#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int N, M, K, order[MAXN];

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> N >> M >> K;

    vector<int> hie(M);

    for (int i = 0; i < M; i++) {
        cin >> hie[i];
    }

    for (int i = 0; i < K; i++) {
        int c, p; cin >> c >> p;
        order[p] = c;
    }

    if (find(hie.begin(), hie.end(), 1) != hie.end()) {
        int curr = 0;
        for (int i = 1; (i <= N) && (curr < M); i++) {
            if (order[i]) continue;
            int idx = find(order + 1, order + N + 1, hie[curr]) - order;
            if (idx == (N + 1)) {
                order[i] = hie[curr];
                curr++;
            } else {
                i = idx;
                curr++;
            }
        }
    } else {
        int curr = M - 1;
        for (int i = N; (i > 0) && (curr >= 0); i--) {
            if (order[i]) continue;
            int idx = find(order + 1, order + N + 1, hie[curr]) - order;
            if (idx == (N + 1)) {
                order[i] = hie[curr];
                curr--;
            } else {
                i = idx;
                curr--;
            }
        }
    }

    int ans = find(order + 1, order + N + 1, 1) - order;

    if (ans == (N + 1)) {
        for (int i = 1; i <= N; i++) {
            if (order[i] == 0) {
                ans = i;
                break;
            }
        }
    }

    cout << ans << "\n";
}