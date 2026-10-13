#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define x first
#define y second

int N, X, K;
pair<int, int> v[MAXN];

int dist(int l, int r) {
    return v[r].x - X + v[r].x - v[l].x;
}

long long solve() {
    int first = 0;
    while ((first < N) && (v[first].x < X)) {
        ++first;
    }
    if (first == N) return 0;
    if (v[first].x - X > K) return 0;

    int _first = first;

    long long sum = v[first].y;
    int p = first;

    while ((p - 1 >= 0) && (dist(p - 1, first) <= K)) {
        --p;
        sum += v[p].y;
    }

    long long ans = sum;
    while (first + 1 < N) {
        first++;
        sum += v[first].y;
        if (v[first].x - X > K) break;

        while (p < _first && dist(p, first) > K) {
            sum -= v[p].y;
            p++;
        }
        ans = max(ans, sum);
    }

    return ans;
}

int main() {
    cin >> N >> X >> K;
    for (int i = 0; i < N; i++) cin >> v[i].x >> v[i].y;
    sort(v, v+N);
    long long best = solve();

    for (int i = 0; i < N; i++) v[i].first *= -1;
    reverse(v, v+N);
    X *= -1;

    best = max(best, solve());

    cout << best << "\n";
}