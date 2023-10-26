#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int n;
pair<int, int> traps[MAXN];

bool check(int k) {
    for (int i = 0; i < n; i++) {
        if (2 * (k - traps[i].first) >= traps[i].second) {
            return false;
        }
    }
    return true;
}

int binarySearch() {
    int ini = 1, fim = 300, meio, ans;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (check(meio)) {
            ans = meio;
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> traps[i].first >> traps[i].second;
        cout << binarySearch() << "\n";
    }
}