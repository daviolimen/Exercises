#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;

const int MAXN = 100000;

int n, m, car[MAXN], mec[MAXN];

int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> car[i];
    for (int i = 0; i < m; i++) cin >> mec[i];
    sort(car, car + n);
    sort(mec, mec + m);
    int cost = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 0; i < m; i++) {
        pq.emplace(mec[i], mec[i]);
    }
    for (int i = n - m - 1; i >= 0; i--) {
        cost += pq.top().first * car[i];
        int fator = pq.top().second, numCar = pq.top().first / pq.top().second;
        pq.pop();
        pq.emplace(fator * (numCar + 1), fator);
    }
    cout << cost << "\n";
}