#include <bits/stdc++.h>
using namespace std;

int n, d;
vector<int> idx[10];

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    while (true) {
        for (int i = 0; i < 10; i++) idx[i].clear();
        cin >> n >> d;
        if (n == 0) break;
        string num; cin >> num;
        for (int i = 0; i < n; i++) {
            idx[num[i] - '0'].push_back(i);
        }

        int cnt = n - d, curr[10]{0}, minIdx = -1;
        string cons;
        while (cnt--) {
            for (int i = 9; i >= 0; i--) {
                while ((curr[i] < idx[i].size()) && (idx[i][curr[i]] <= minIdx)) curr[i]++;
                if (curr[i] == idx[i].size()) continue;
                if (n - idx[i][curr[i]] <= cnt) continue;
                cons.push_back('0' + i);
                minIdx = idx[i][curr[i]];
                break;
            }
        }

        cout << cons << "\n";
    }
}