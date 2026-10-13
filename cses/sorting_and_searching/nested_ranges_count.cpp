#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

struct itv {
    int x, y, idx;
};

bool cmpX(const itv &a, const itv &b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int n, sec[MAXN], bit[MAXN], ans[2][MAXN];
itv arr[MAXN];

void update(int k) {
    for (; k <= n; k += (k & -k)) bit[k]++;
}

int soma(int k) {
    int res = 0;
    for (; k > 0; k -= (k & -k)) res += bit[k];
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        arr[i].idx = i;
        cin >> arr[i].x >> arr[i].y;
        sec[i] = arr[i].y;
    }
    sort(arr + 1, arr + n + 1, cmpX);

    int counter = 1;
    sort(sec + 1, sec + n + 1);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        if (mp.find(sec[i]) == mp.end()) {
            mp[sec[i]] = counter++;
        }
    }
    for (int i = 1; i <= n; i++) arr[i].y = mp[arr[i].y];

    for (int i = 1; i <= n; i++) {
        ans[1][arr[i].idx] = soma(n) - soma(arr[i].y - 1);
        update(arr[i].y);
    }

    memset(bit, 0, sizeof(bit));

    for (int i = n; i > 0; i--) {
        ans[0][arr[i].idx] = soma(arr[i].y);
        update(arr[i].y);
    }

    for (int i = 1; i <= n; i++) cout << ans[0][i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << ans[1][i] << " \n"[i == n];
}