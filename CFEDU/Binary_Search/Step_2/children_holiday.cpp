#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define int long long

int m, n, arr[MAXN][3];

bool isPossible(int t, int z, int y, int balloons, int time) {
    int batchTime = (t * z) + y;
    int batches = balloons / z;
    int totalTime = 0;
    bool ok = (balloons % z == 0) ? 1 : 0;

    if (ok) {
        totalTime = batchTime * batches - y;
    } else {
        totalTime = batchTime * batches + (balloons % z) * t;
    }

    return totalTime <= time;
}

bool check(int x) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        int t = arr[i][0], z = arr[i][1], y = arr[i][2], l = 0, r = (int) 1e9;

        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (isPossible(t, z, y, mid, x)) l = mid;
            else r = mid;
        }

        total += l;
    }

    return total >= m;
}

int countMax(int t, int z, int y, int maxTime) {
    int batchTime = (t * z) + y;
    int batches = maxTime / batchTime;
    int remTime = (maxTime % batchTime);
    int totalBalloons = batches * z;
    if (remTime != 0) {
        if (remTime / t >= z) {
            totalBalloons += z;
        } else {
            totalBalloons += (remTime / t);
        }
    }

    return totalBalloons;
}

int32_t main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    int l = -1, r = (int) 1e9;

    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << r << "\n";

    int filled[MAXN];
    memset(filled, 0, sizeof(filled));

    for (int i = 0; i < n; i++) {
        int t = arr[i][0], z = arr[i][1], y = arr[i][2];
        filled[i] = countMax(t, z, y, r);
    }

    int totalBalloons = 0;

    for (int i = 0; i < n; i++) {
        if (totalBalloons + filled[i] <= m) {
            totalBalloons += filled[i];
            cout << filled[i] << " ";
        } else {
            if (totalBalloons == m) {
                cout << 0 << " ";
            } else {
                cout << (m - totalBalloons) << " ";
                totalBalloons = m;
            }
        }
    }

    cout << "\n";
    return 0;
}