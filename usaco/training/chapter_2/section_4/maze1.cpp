/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: maze1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int DY[] = {1, 0, -1, 0};
int DX[] = {0, 1, 0, -1};

int n, m, nodes[120][50], res[2][120][50];
char grid[210][100];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m)) return 1;
    return 0;
}

void bfs(int yi, int xi, int flag) {
    queue<pair<int, int>> q;
    q.emplace(yi, xi);
    vector<vector<int>> dist(n, vector<int>(m, 100000));
    dist[yi][xi] = 0;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            if (!(nodes[y][x] & (1 << i))) continue;
            int ny = y + DY[i], nx = x + DX[i];
            if (notSafe(ny, nx)) continue;
            if (dist[ny][nx] < 100000) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.emplace(ny, nx);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[flag][i][j] = dist[i][j];
        }
    }
}

int main() {
    ifstream cin ("maze1.in");
    ofstream cout ("maze1.out");
    cin >> m >> n;
    for (int i = 0; i < (2 * n + 1); i++) {
        for (int j = 0; j < (2 * m + 1); j++) {
            char c = cin.get();
            if (c == '\n') c = cin.get();
            grid[i][j] = c;
        }
    }

    vector<pair<int, int>> sources;

    for (int i = 1; i < 2 * n + 1; i += 2) {
        for (int j = 1; j < 2 * m + 1; j += 2) {
            for (int k = 0; k < 4; k++) {
                int ni = i + DY[k];
                int nj = j + DX[k];
                if (grid[ni][nj] == ' ') nodes[i / 2][j / 2] |= (1 << k);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0) && (nodes[i][j] & 4)) sources.emplace_back(i, j);
            if ((i == n - 1) && (nodes[i][j] & 1)) sources.emplace_back(i, j);
            if ((j == 0) && (nodes[i][j] & 8)) sources.emplace_back(i, j);
            if ((j == m - 1) && (nodes[i][j] & 2)) sources.emplace_back(i, j);
        }
    }

    bfs(sources[0].first, sources[0].second, 0);
    bfs(sources[1].first, sources[1].second, 1);

    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, min(res[0][i][j], res[1][i][j]));
        }
    }

    cout << (ans + 1) << "\n";
    return 0;
}