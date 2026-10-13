#include <bits/stdc++.h>
using namespace std;

#define MAXN 20010

int n, m, dragon[MAXN], knight[MAXN];

int solve() {
    int i = 1, j = 1, ans = 0;
    while ((j <= n) && (i <= m)) {
        if (knight[i] >= dragon[j]) {
            ans += knight[i];
            i++;
            j++;
        } else {
            i++;
        }
    }
    if (j == (n + 1)) return ans;
    else return -1;
}

int main() {
    cin >> n >> m;
    while ((n != 0) && (m != 0)) {
        for (int i = 1; i <= n; i++) cin >> dragon[i];
        for (int i = 1; i <= m; i++) cin >> knight[i];
        sort(dragon+1, dragon+n+1);
        sort(knight + 1, knight+m+1);
        int ans = solve();
        if (ans == -1) cout << "Loowater is doomed!\n";
        else cout << ans << "\n";
        cin >> n >> m;
    }
}