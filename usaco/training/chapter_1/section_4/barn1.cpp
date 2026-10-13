/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: barn1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("barn1.in");
    ofstream cout ("barn1.out");
    int m, s, c; cin >> m >> s >> c;
    vector<bool> stall(s + 1);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < c; i++) {
        int x; cin >> x;
        stall[x] = 1;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    vector<int> arr;

    int cnt = 0;
    for (int i = mn + 1; i <= mx; i++) {
        if (!stall[i]) {
            cnt++;
        } else {
            if (cnt == 0) continue;
            arr.push_back(cnt);
            cnt = 0;
        }
    }

    int ans = mx - mn + 1;
    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < min((int) arr.size(), m - 1); i++) {
        ans -= arr[i];
    }

    cout << ans << "\n";

    return 0;
}