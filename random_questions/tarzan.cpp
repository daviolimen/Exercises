#include <bits/stdc++.h>
using namespace std;

#define SQR(a) ((a) * (a))

int N, D;
pair<int, int> arvores[1010];
bool visited[1010];

void solve() {
    int d = SQR(D), a;
    visited[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        a = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (visited[i]) continue;
            int dist = SQR(arvores[a].first - arvores[i].first) + SQR(arvores[a].second - arvores[i].second);
            if (dist <= d) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    cin >> N >> D;
    int X, Y;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        arvores[i].first = X;
        arvores[i].second = Y;
    }
    solve();
    bool ans = true;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            ans = false;
        } 
    }
    if (ans) cout << "S\n";
    else cout << "N\n";
}