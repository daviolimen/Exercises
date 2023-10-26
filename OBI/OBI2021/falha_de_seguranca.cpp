#include <bits/stdc++.h>
using namespace std;

#define MAXN 20000

int n;
string arr[MAXN];
unordered_map<string, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string st; cin >> st;
        arr[i] = st;

        unordered_map<string, bool> temp;

        for (int i = 0; i < (int) st.size(); i++) {
            for (int j = 1; j <= (int) st.size() - i; j++) {
                if (!temp[st.substr(i, j)]) {
                    mp[st.substr(i, j)]++;
                    temp[st.substr(i, j)] = true;
                }
            }
        }
    }

    int ans = -n;

    for (int i = 0; i < n; i++) {
        ans += mp[arr[i]];
    }

    cout << ans << "\n";
}