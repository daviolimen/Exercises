#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, m, arr[MAXN];
unordered_map<int, int> mp;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    int last = 0, ctr = 1;

    for (int i = 1; i <= n; i++) {
        if (mp[i] > last) {
            last = mp[i];
        } else {
            ctr++;
            last = mp[i];
        }
    }

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        if (arr[a] > arr[b]) ctr--;
        else ctr++;
        swap(mp[arr[a]], mp[arr[b]]);
        swap(arr[a], arr[b]);
        cout << ctr << "\n";
    }
}