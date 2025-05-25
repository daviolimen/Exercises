/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: ditch
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, graph[201][201];
bool visited[201];

int32_t main() {
    ifstream cin ("ditch.in");
    ofstream cout ("ditch.out");
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = c;
    }

    int ans = 0;
    while (true) {
        vector<int> prev(n + 1), flow(n + 1);
        vector<bool> visited(n + 1);
        flow[1] = INT_MAX;

        while (true) {
            int bestFlow = 0, bestV = -1;
            for (int i = 1; i <= n; i++) {
                if (flow[i] > bestFlow && !visited[i]) {
                    bestFlow = flow[i];
                    bestV = i;
                }
            }

            if (bestV == -1) break;
            if (bestV == n) break;
            visited[bestV] = 1;
            for (int i = 1; i <= n; i++) {
                if (flow[i] < min(bestFlow, graph[bestV][i])) {
                    prev[i] = bestV;
                    flow[i] = min(bestFlow, graph[bestV][i]);
                }
            }
        }

        if (flow[n] == 0) break;

        ans += flow[n];

        int curr = n;
        while (curr > 1) {
            graph[prev[curr]][curr] -= flow[n];
            graph[curr][prev[curr]] += flow[n];
            curr = prev[curr];
        }
    }

    cout << ans << "\n";
    return 0;
}