#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, k, bel[MAXN];
long long prefix[MAXN];
vector<int> graph[MAXN];


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> bel[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + bel[i];
    }

    long long best = 0;

    for (int i = 1; i <= n; i++) {
        best = max(best, prefix[i]);
    }

    cout << best << "\n";
}