#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

int n, k, a[MAXN];

bool check(int m) {
    int mex = 0, cnt = 0;
    vector<int> freq(m);
    for (int i = 0; i < n; i++) {
        if (a[i] >= m) continue;
        freq[a[i]]++;
        while (freq[mex]) {
            mex++;
            if (mex == m) break;
        }
        if (mex >= m) {
            cnt++;
            mex = 0;
            freq = vector<int>(m);
        }
    }
    if (cnt >= k) return 1;
    return 0;
}

int search() {
    int l = 0, r = n / k + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        
        cout << search() << "\n";
    }
}