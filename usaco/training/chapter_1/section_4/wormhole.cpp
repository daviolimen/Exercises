/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: wormhole
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool cmpY(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

const int MAXN = 12;

int n, ans, conn[MAXN];
pair<int, int> pts[MAXN];
vector<int> pos[MAXN];

bool check() {
    for (int i = 0; i < n; i++) {
        bool ok = 1;
        int curr = i;
        int ctr = 20;
        while (ctr--) {
            int idx = -1;
            auto v = pos[pts[curr].second];
            for (int j = 0; j < (int) v.size(); j++) {
                if (v[j] == curr) {
                    idx = j;
                    break;
                }
            }

            if (idx == (int) v.size() - 1) {
                ok = 0;
                break;
            }

            curr = conn[v[idx + 1]];
        }

        if (ok) return 1;
    }
    return 0;
}

void search(int cnt) {
    if (cnt == n) {
        if (check()) ans++;
        return;
    }

    int start = -1;
    for (int i = 0; i < n; i++) {
        if (conn[i] != -1) continue;
        start = i;
        break;
    }

    for (int i = start + 1; i < n; i++) {
        if (conn[i] != -1) continue;
        conn[start] = i;
        conn[i] = start;
        search(cnt + 2);
        conn[start] = -1;
        conn[i] = -1;
    }
}

int main() {
    memset(conn, -1, sizeof(conn));
    ifstream cin ("wormhole.in");
    ofstream cout ("wormhole.out");
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;

    sort(pts, pts + n, cmpY);
    
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(pts[i].second) == mp.end()) mp[pts[i].second] = i;
    }
    
    for (int i = 0; i < n; i++) pts[i].second = mp[pts[i].second];
    // for (int i = 0; i < n; i++) cout << pts[i].first << " " << pts[i].second << "\n";

    for (int i = 0; i < n; i++) pos[pts[i].second].push_back(i);

    search(0);

    cout << ans << "\n";

    return 0;
}