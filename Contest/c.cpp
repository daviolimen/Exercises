#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        
        bool isPos = true;

        map<int, int> mp;
        int equCnt = 0, equIdx = -1;

        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i]) {
                equCnt++;
                equIdx = i;
            }
            if (mp.find(a[i]) == mp.end()) {
                mp[a[i]] = b[i];
                mp[b[i]] = a[i];
            } else {
                if (b[i] != mp[a[i]]) isPos = false;
            }
        }

        if (equCnt > 1) isPos = false;
        if ((equCnt) && (n % 2 == 0)) isPos = false;

        if (!isPos) {
            cout << "-1\n";
            continue;
        }

        vector<pair<int, int>> mvs;
        if (equCnt) {
            if (equIdx != 1 + n / 2) {
                mvs.emplace_back(equIdx, 1 + n / 2);
                swap(a[equIdx], a[1 + n / 2]);
                swap(b[equIdx], b[1 + n / 2]);
            }
        }

        map<int, int> toGo;
        vector<bool> solved(n + 1);

        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i]) continue;
            if (solved[a[i]]) continue;
            if (toGo.find(b[i]) == toGo.end()) {
                solved[a[i]] = 1;
                toGo[a[i]] = n - i + 1;
            } else {
                while (!solved[a[i]]) {
                    if (toGo.find(b[i]) == toGo.end()) {
                        solved[a[i]] = 1;
                        toGo[a[i]] = n - i + 1;
                    } else {
                        solved[a[i]] = 1;
                        if (i == toGo[b[i]]) continue;
                        mvs.emplace_back(i, toGo[b[i]]);
                        swap(a[i], a[toGo[b[i]]]);
                        swap(b[i], b[toGo[b[i]]]);
                    }
                }
            }
        }

        cout << mvs.size() << "\n";
        for (auto X : mvs) cout << X.first << " " << X.second << "\n";
    }
}