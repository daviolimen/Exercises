/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: camelot
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

const int DY[] = {2, 2, 1, 1, -1, -1, -2, -2};
const int DX[] = {1, -1, 2, -2, 2, -2, 1, -1};

bool visited[30][30];
int n, m, kingPos[2], dist[30][30][30][30];
vector<pair<int, int>> horses;

int kingDist(int y1, int x1, int y2, int x2) {
    return max(abs(y2 - y1), abs(x2 - x1));
}

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m)) return 1;
    return 0;
}

void bfs(pair<int, int> start) {
    dist[start.first][start.second][start.first][start.second] = 0;

    memset(visited, 0, sizeof(visited));
    visited[start.first][start.second] = 1;

    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int ny = y + DY[i];
            int nx = x + DX[i];
            if (notSafe(ny, nx) || visited[ny][nx]) continue;
            dist[start.first][start.second][ny][nx] = dist[start.first][start.second][y][x] + 1;
            visited[ny][nx] = 1;
            q.emplace(ny, nx);
        }
    }
}

int main() {
    memset(dist, 0x01010101, sizeof(dist));
    ifstream cin ("camelot.in");
    ofstream cout ("camelot.out");
    cin >> n >> m;
    char c; int x; cin >> c >> x;
    kingPos[0] = x - 1;
    kingPos[1] = c - 'A';
    while (cin >> c >> x) {
        x--;
        horses.emplace_back(x, c - 'A');
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs({i, j});
        }
    }

    int ans = INT_MAX;

    for (int ty = 0; ty < n; ty++) {
        for (int tx = 0; tx < m; tx++) {
            int soma = 0;
            for (auto [hy, hx] : horses) {
                soma += dist[ty][tx][hy][hx];
            }
            soma += kingDist(ty, tx, kingPos[0], kingPos[1]);
            ans = min(ans, soma);
            int tmp = soma;
            for (auto [hy, hx] : horses) {
                for (int i = kingPos[0] - 4; i <= kingPos[0] + 4; i++) {
                    for (int j = kingPos[1] - 4; j <= kingPos[1] + 4; j++) {
                        if (notSafe(i, j)) continue;
                        soma = tmp;
                        soma -= dist[ty][tx][hy][hx];
                        soma -= kingDist(ty, tx, kingPos[0], kingPos[1]);
                        soma += kingDist(kingPos[0], kingPos[1], i, j);
                        soma += dist[ty][tx][i][j];
                        soma += dist[i][j][hy][hx];
                        ans = min(ans, soma);
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}