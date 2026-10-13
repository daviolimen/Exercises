#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int N, B;
pair<int, int> cows[MAXN];

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    cin >> N >> B;
    for (int i = 0; i < N; i++) cin >> cows[i].first >> cows[i].second;

    int a, b, M = INT_MAX;

    for (int i = 0; i < N; i++) {
        a = cows[i].first + 1;
        for (int j = 0; j < N; j++) {
            b = cows[j].second + 1;
            int q[4] = {0, 0, 0, 0};
            for (int k = 0; k < N; k++) {
                if (cows[k].first > a) {
                    if (cows[k].second > b) {
                        q[0]++;
                    } else {
                        q[3]++;
                    }
                } else {
                    if (cows[k].second > b) {
                        q[1]++;
                    } else {
                        q[2]++;
                    }
                }
            }
            M = min(M, max({q[0], q[1], q[2], q[3]}));
        }
    }

    cout << M << "\n";
}