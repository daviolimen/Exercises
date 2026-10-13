#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, diameter = -1, toLeaf[MAXN], maxLength[MAXN];
vector<int> graph[MAXN];

void dfs(int x, int p) {
    int max1 = -2, max2 = -2;

    for (auto v : graph[x]) {
        if (v == p) continue;
        dfs(v, x);

        if (max1 == -2) {
            max1 = toLeaf[v] + 1;
        } else if (toLeaf[v] + 1 >= max1) {
            max2 = max1;
            max1 = toLeaf[v] + 1;
        } else if (toLeaf[v] + 1 > max2) {
            max2 = toLeaf[v] + 1;
        }
    }

    toLeaf[x] = 0;

    toLeaf[x] = max(toLeaf[x], max1);

    if (max2 == -2) {
        maxLength[x] = toLeaf[x];
    } else {
        maxLength[x] = max1 + max2;
    }
    diameter = max(diameter, max(maxLength[x], toLeaf[x]));
}

int main() {
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << diameter << "\n";
}