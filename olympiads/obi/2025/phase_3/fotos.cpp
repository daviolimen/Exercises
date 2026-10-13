#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100100

int n, arr[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> bet;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            bet.push_back(i - last);
            last = i;
        }
    }
    bet.push_back(n - last);

    int ans = 0;
    for (int i = 0; i < bet.size() - 1; i++) {
        ans += (bet[i]) * (bet[i + 1]);
    }

    cout << ans << "\n";
}