#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010

int n, arr[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<array<int, 2>> dist(n);
    int pos = -1, val = 1e9;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            pos = i;
            val = arr[i];
        }
        dist[i][0] = (i - pos) + val;
    }
    pos = -1, val = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] != -1) {
            pos = i;
            val = arr[i];
        }
        dist[i][1] = (pos - i) + val;
    }

    for (int i = 0; i < n; i++) cout << min(dist[i][0], dist[i][1]) << " ";
    cout << "\n";
}