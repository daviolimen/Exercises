#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50010;

int N, pai[MAXN], toLeaf[MAXN][2], maxLength[MAXN][2];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    pai[u] = p;
    int negPart = 0;
    bool twoSkibidis = false;
    int mx1[2] = {-1, 0};
    int mx2[2] = {-1, 0};
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);

        if (toLeaf[v][0] + 1 > toLeaf[u][0]) {
            toLeaf[u][0] = toLeaf[v][0] + 1;
            toLeaf[u][1] = toLeaf[v][1];
        } else if (toLeaf[v][0] + 1 == toLeaf[u][0]) {
            toLeaf[u][1] += toLeaf[v][1];
        }

        if (toLeaf[v][0] > mx1[0]) {
            twoSkibidis = false;
            negPart = toLeaf[v][1] * (toLeaf[v][1] - 1);
            mx2[0] = mx1[0];
            mx2[1] = mx1[1];
            mx1[0] = toLeaf[v][0];
            mx1[1] = toLeaf[v][1];
        } else if (toLeaf[v][0] == mx1[0]) {
            twoSkibidis = true;
            negPart += toLeaf[v][1] * (toLeaf[v][1] - 1);
            mx1[1] += toLeaf[v][1];
        } else if (toLeaf[v][0] > mx2[0]) {
            mx2[0] = toLeaf[v][0];
            mx2[1] = toLeaf[v][1];
        } else if (toLeaf[v][0] == mx2[0]) {
            mx2[1] += toLeaf[v][1];
        }
    }

    if (toLeaf[u][0] == 0) {
        toLeaf[u][1] = 1;
        return;
    }
    
    if (twoSkibidis) {
        maxLength[u][0] = 2 * mx1[0] + 2;
        maxLength[u][1] = mx1[1] * (mx1[1] - 1) - negPart;
        maxLength[u][1] /= 2;
    } else if (mx2[0] == -1) {
        maxLength[u][0] = mx1[0] + 1;
        maxLength[u][1] = mx1[1];
    } else {
        maxLength[u][0] = mx1[0] + mx2[0] + 2;
        maxLength[u][1] = mx1[1] * mx2[1];
    }
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    int best1 = -1, best2 = -1;
    for (int i = 1; i <= N; i++) {
        // cout << maxLength[i][0] << " " << maxLength[i][1] << " " << toLeaf[i][0] << " " << toLeaf[i][1] << "\n";
        if (maxLength[i][0] > best1) {
            best1 = maxLength[i][0];
            best2 = maxLength[i][1];
        } else if (maxLength[i][0] == best1) {
            best2 += maxLength[i][1];
        }
    }

    cout << best1 + 1 << "\n" << best2 << "\n";
}