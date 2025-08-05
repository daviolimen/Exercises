#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

int query(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int res; cin >> res;
    return res;
}

void solveHalf(const vector<int>& idx) {
    for (int i = 0; i < (int) idx.size(); i += 2) {
        if (i == (int) idx.size() - 1) break;
        int x = query(idx[i], idx[i + 1]);
        int y = query(idx[i + 1], idx[i]);
        if (x > y) ans[idx[i]] = x;
        else ans[idx[i + 1]] = y;
    }
}

int main() {
    cin >> n;
    ans = vector<int>(n + 1);
    vector<int> idx;
    for (int i = 1; i <= n; i++) idx.push_back(i);

    while (true) {
        // for (auto x : idx) cout << x << " ";
        // cout << "\n";
        if (idx.size() == 1) break;
        solveHalf(idx);
        idx.clear();
        for (int i = 1; i <= n; i++) {
            if (ans[i]) continue;
            idx.push_back(i);
        }
    }

    int missing = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) missing -= ans[i];
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) {
            ans[i] = missing;
            break;
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    cout.flush();
}