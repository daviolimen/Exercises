#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
#define MAXS 250

int S, C, graph[MAXS][MAXS], dist[MAXS][MAXS];

void floyd_warshall() {
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            for (int k = 0; k < S; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

int main() {
    cin >> S >> C;
    int a, b, d;

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    for (int i = 0; i < C; i++) {
        cin >> a >> b >> d;
        a--; b--;
        graph[a][b] = d;
        graph[b][a] = d;
    }

    floyd_warshall();

    int min_max_value = INF, curr;
    for (int i = 0; i < S; i++) {
        curr = *max_element(dist[i], dist[i] + S);
        min_max_value = min(min_max_value, curr);
    }

    cout << min_max_value << "\n";
}