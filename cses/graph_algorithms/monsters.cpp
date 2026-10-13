#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
const char mov[] = {'D', 'R', 'U', 'L'};

typedef tuple<int, int, bool> ti;

const int MAXN = 1000;

int n, m;
char mat[MAXN][MAXN];
int movs[MAXN][MAXN];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m)) return 1;
    return 0;
}

int main() {
    int yi, xi;
    queue<ti> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'M') q.emplace(i, j, 0);
            if (mat[i][j] == 'A') yi = i, xi = j;
        }
    }

    bool pos = 0;
    pair<int, int> endPos;

    q.emplace(yi, xi, 1);
    while (!q.empty()) {
        auto [y, x, t] = q.front();
        q.pop();

        if ((t == 1) && ((y == (n - 1)) || (y == 0) || (x == (m - 1)) || (x == 0))) {
            pos = true;
            endPos = {y, x};
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (t) {
                if (notSafe(ny, nx) || (mat[ny][nx] == 'H') || (mat[ny][nx] == 'M') || (mat[ny][nx] == '#')) continue;
                movs[ny][nx] = i;
                mat[ny][nx] = 'H';
                q.emplace(ny, nx, 1);
            } else {
                if (notSafe(ny, nx) || (mat[ny][nx] == 'M') || (mat[ny][nx] == '#')) continue;
                mat[ny][nx] = 'M';
                q.emplace(ny, nx, 0);
            }
        }
    }

    if (!pos) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<char> solution;
        while ((endPos.first != yi) || (endPos.second != xi)) {
            int point = movs[endPos.first][endPos.second];
            solution.push_back(mov[point]);
            endPos.first -= dy[point];
            endPos.second -= dx[point];
        }
        int length = (int) solution.size();
        cout << length << "\n";
        for (int i = length - 1; i >= 0; i--) {
            cout << solution[i];
        }
        cout << "\n";
    }
}