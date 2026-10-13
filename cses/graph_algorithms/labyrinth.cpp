#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
char dir[] = {'D', 'R', 'U', 'L'};

#define MAXN 1000

int n, m;
char grid[MAXN][MAXN], ant[MAXN][MAXN];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int sy, sx;

    deque<pair<int, int>> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sy = i;
                sx = j;
            }
        }
    }

    q.emplace_back(sy, sx);

    int ey = -1, ex = -1;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop_front();

        if ((notSafe(y, x)) || (grid[y][x] == '#')) continue;

        if (grid[y][x] == 'B') {
            ey = y;
            ex = x;
            break;
        }

        grid[y][x] = '#';

        for (int i = 0; i < 4; i++) {
            if ((notSafe(y + dy[i], x + dx[i])) || (grid[y + dy[i]][x + dx[i]] == '#')) continue;
            q.emplace_back(y + dy[i], x + dx[i]);
            ant[y + dy[i]][x + dx[i]] = dir[i];
        }
    }

    if ((ey == -1) && (ex == -1)) {
        cout << "NO\n";
        return 0;
    }

    string rans, ans;

    while (true) {
        if ((ey == sy) && (ex == sx)) break;
        rans.push_back(ant[ey][ex]);
        if (ant[ey][ex] == 'D') ey--;
        else if (ant[ey][ex] == 'R') ex--;
        else if (ant[ey][ex] == 'U') ey++;
        else if (ant[ey][ex] == 'L') ex++;
    }

    for (int i = (int) rans.size() - 1; i >= 0; i--) {
        ans.push_back(rans[i]);
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    cout << ans << "\n";
}