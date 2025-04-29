#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        int regs[2] = {0, 0};
        if (s[0] == '0') {
            regs[1] = n - 1;
        } else {
            regs[1] = 1;
        }
        ans = max({ans, regs[0], regs[1]});
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '0') {
                    regs[0] += i;
                    regs[1] += n - i - 1;
                } else {
                    swap(regs[0], regs[1]);
                    regs[0] += i;
                    regs[1] = n - i - 1;
                }
            } else {
                if (s[i - 1] == '0') {
                    regs[1]++;
                    regs[0] = 0;
                } else {
                    regs[0] = 1;
                    regs[1] = 0;
                }
            }
            ans = max({ans, regs[0], regs[1]});
        }

        cout << ans << "\n";
    }
}