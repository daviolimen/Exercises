/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: skidesign
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("skidesign.in");
    ofstream cout ("skidesign.out");
    int n; cin >> n;
    vector<int> h(n);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        mn = min(mn, h[i]);
        mx = max(mx, h[i]);
    }

    int ans = INT_MAX;
    for (int i = mn; i <= mx; i++) {
        int right = i + 17;
        int cost = 0;
        for (int j = 0; j < n; j++) {
            if (h[j] < i) cost += (i - h[j]) * (i - h[j]);
            else if (h[j] > right) cost += (h[j] - right) * (h[j] - right);
        }
        ans = min(ans, cost);
    }

    cout << ans << "\n";

    return 0;
}