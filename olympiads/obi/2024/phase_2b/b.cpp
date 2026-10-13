#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, n; cin >> r >> n;
    vector<pair<int, int>> frutas;
    for (int i = 0; i < n; i++) {
        int tipo, preco; cin >> tipo >> preco;
        frutas.emplace_back(preco, tipo);
    }
    sort(frutas.begin(), frutas.end());
    vector<bool> visited(110, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited[frutas[i].second]) continue;
        r -= frutas[i].first;
        visited[frutas[i].second] = 1;
        if (r < 0) break;
        ans++;
    }
    cout << ans << "\n";
}