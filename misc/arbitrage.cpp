#include <bits/stdc++.h>
using namespace std;

#define MAXN 30

int n, m;
double graph[MAXN][MAXN], dist[MAXN][MAXN];
unordered_map<string, int> currencies;

void floyd_warshall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dist[j][k] = max(dist[j][k], dist[j][i] * dist[i][k]);
            }
        }
    }
}

int main() {
    cin >> n;
    int caso = 1;
    while (n != 0) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = 0;
                dist[i][j] = 0;
            }
        }
        currencies.clear();


        string currency;
        for (int i = 0; i < n; i++) {
            cin >> currency;
            currencies[currency] = i;
        }

        cin >> m;

        string ca, cb;
        double r;
        for (int i = 0; i < m; i++) {
            cin >> ca >> r >> cb;
            graph[currencies[ca]][currencies[cb]] = r;
        }

        floyd_warshall();

        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (dist[i][i] > 1.0001) {
                ans = true;
                break;
            }
        }

        if (ans) cout << "Case " << caso << ": Yes\n";
        else cout << "Case " << caso << ": No\n";
        caso++;
        cin >> n;
    }
}