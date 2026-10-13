#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int n, pos[MAXN], pai[MAXN];
vector<int> pilha, seq, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        seq.push_back(x);
        auto it = upper_bound(pilha.begin(), pilha.end(), x);
        int p = it - pilha.begin();

        if (it == pilha.end()) pilha.push_back(x);
        else *it = x;

        pos[p] = i;
        if (p == 0) pai[i] = -1;
        else pai[i] = pos[p - 1];
    }

    int p = pos[pilha.size() - 1];
    while (p >= 0) {
        ans.push_back(seq[p]);
        p = pai[p];
    }

    reverse(ans.begin(), ans.end());
    cout << (int) ans.size() << "\n";
    for (int i = 0; i < (int) ans.size(); i++) cout << ans[i] << " \n"[i == (int) ans.size() - 1];

}