#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, pai[MAXN];

int main() {
    cin >> n;
    pai[1] = 1;
    int p;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        pai[i] = p;
    }

    vector<int> ans;

    int i = n;
    ans.push_back(n);
    while (pai[i] != i) {
        ans.push_back(pai[i]);
        i = pai[i];
    }

    reverse(ans.begin(), ans.end());

    for (auto x : ans) cout << x << " ";
    cout << "\n";
}