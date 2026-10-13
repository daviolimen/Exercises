/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: stall4
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int n, m, graph[402][402];

int main() {
    ifstream cin ("stall4.in");
    ofstream cout ("stall4.out");
    cin >> n >> m;
    for (int i = 1; i <= n; i++) graph[0][i] = 1;
    for (int i = n + 1; i <= n + m; i++) graph[i][401] = 1;
    for (int i = 1; i <= n; i++) {
        int sz; cin >> sz;
        for (int j = 0; j < sz; j++) {
            int x; cin >> x;
            graph[i][n + x] = 1;
        }
    }

    int ans = 0;
    while (true) {
        vector<int> prev(402), flow(402);
        vector<bool> visited(402);
        flow[1] = INT_MAX;

        while (true) {
            int bestFlow = 0, bestNode = -1;

            for (int i = 0; i < 402; i++) {
                if ((flow[i] > bestFlow) && (!visited[i])) {
                    bestFlow = flow[i];
                    bestNode = i;
                }
            }

            if (bestNode == -1) break;
            if (bestNode == 401) break;

            visited[bestNode] = 1;
            for (int i = 0; i < 402; i++) {
                if (flow[i] < min(bestFlow, graph[bestNode][i])) {
                    prev[i] = bestNode;
                    flow[i] = min(bestFlow, graph[bestNode][i]);
                }
            }
        }

        if (flow[401] == 0) break;

        ans += flow[401];

        int curr = 401;

        while (curr) {
            graph[prev[curr]][curr] -= flow[401];
            graph[curr][prev[curr]] += flow[401];
            curr = prev[curr];
        }
    }

    cout << ans << "\n";
    return 0;
}