#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

#define MAXN 100

int n, k, r, roads[MAXN][MAXN];
bool visited[MAXN][MAXN];
pair<int, int> cows[MAXN];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= n)) return true;
    return false;
}

void floodFill(int y, int x) {
    if ((notSafe(y, x)) || (visited[y][x])) return;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        if ((roads[y][x]) & (1 << i)) continue;
        floodFill(y + dy[i], x + dx[i]);
    }
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        y1--; y2--; x1--; x2--;
        if (y2 == y1 - 1) {
            roads[y1][x1] |= (1 << 0);
            roads[y2][x2] |= (1 << 2);
        } else if (x2 == x1 + 1) {
            roads[y1][x1] |= (1 << 1);
            roads[y2][x2] |= (1 << 3);
        } else if (y2 == y1 + 1) {
            roads[y1][x1] |= (1 << 2);
            roads[y2][x2] |= (1 << 0);
        } else if (x2 == x1 - 1) {
            roads[y1][x1] |= (1 << 3);
            roads[y2][x2] |= (1 << 1);
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> cows[i].first >> cows[i].second;
        cows[i].first--;
        cows[i].second--;
    }

    int ans = 0;

    for (int i = 0; i < k; i++) {
        floodFill(cows[i].first, cows[i].second);
        for (int j = 0; j < k; j++) {
            if (!visited[cows[j].first][cows[j].second]) ans++;
        }
        memset(visited, 0, sizeof(visited));
    }

    cout << ans / 2 << "\n";
}