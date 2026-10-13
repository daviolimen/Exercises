#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

#define MAXN 200001

int n, arr[MAXN], bit[MAXN];

void update(int x) {
    for (; x <= n; x += (x & -x)) {
        bit[x]++;
    }
}

ull query(int k) {
    ull res = 0;
    for (; k > 0; k -= (k & -k)) {
        res += bit[k];
    }
    return res;
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        memset(arr, 0, sizeof(arr));
        memset(bit, 0, sizeof(bit));

        cin >> n;
        vector<int> aux;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            aux.push_back(arr[i]);
        }

        sort(aux.begin(), aux.end());
        unordered_map<int, int> mp;

        for (int i = 0; i < aux.size(); i++) {
            mp[aux[i]] = i + 1;
        }
        ull invs = 0;
        for (int i = n; i > 0; i--) {
            update(mp[arr[i]]);
            invs += query(mp[arr[i]] - 1);
        }

        cout << invs << "\n";
    }
}