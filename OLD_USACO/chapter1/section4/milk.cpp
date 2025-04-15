/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: milk
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("milk.in");
    ofstream cout ("milk.out");
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int ans = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        int mn = min(n, v[i].second);
        ans += mn * v[i].first;
        n -= mn;
    }
    cout << ans << "\n";
    return 0;
}