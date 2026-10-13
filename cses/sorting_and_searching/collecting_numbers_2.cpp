#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, m, arr[MAXN], pos[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int ans = 1, last = 0;

    for (int i = 1; i <= n; i++) {
        if (pos[i] < last) ans++;
        last = pos[i];
    }

    while (m--) {
        int a, b; cin >> a >> b;
        
    }
}