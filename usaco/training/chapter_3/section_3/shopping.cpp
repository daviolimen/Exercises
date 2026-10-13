/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: shopping
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool visited[10000];
int s, b, ofer[100][5][2], prods[5][3], preco[100], dist[10000];
vector<pair<int, int>> ops;

int encode(const vector<int> &v) {
    int res = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        res = (res * 6) + v[i];
    }
    return res;
}

vector<int> decode(int x) {
    vector<int> res(5);
    for (int i = 0; i < 5; i++) {
        res[i] = x % 6;
        x /= 6;
    }
    return res;
}

void dijkstra(int start) {
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        auto vU = decode(u);

        if (visited[u]) continue;
        visited[u] = 1;

        for (auto [v, c] : ops) {
            bool ok = 1;
            auto vV = decode(v);
            for (int i = 0; i < 5; i++) {
                if (vV[i] + vU[i] > 5) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            int newNode = u + v;
            if (newNode > 8000) continue;
            if (dist[newNode] > dist[u] + c) {
                dist[newNode] = dist[u] + c;
                pq.emplace(dist[newNode], newNode);
            }
        }
    }
}

int main() {
    ifstream cin ("shopping.in");
    ofstream cout ("shopping.out");
    memset(ofer, -1, sizeof(ofer));
    cin >> s;
    for (int i = 0; i < s; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> ofer[i][j][0] >> ofer[i][j][1];
        }
        cin >> preco[i];
    }
    cin >> b;
    int power = 1, target = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> prods[i][j];
        }
        ops.emplace_back(power, prods[i][2]);
        target += power * prods[i][1];
        power *= 6;
    }
    
    for (int i = 0; i < s; i++) {
        vector<int> v(5);
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < b; k++) {
                if (ofer[i][j][0] == prods[k][0]) v[k] += ofer[i][j][1];
            }
        }
        ops.emplace_back(encode(v), preco[i]);
    }

    dijkstra(0);
    cout << dist[target] << "\n";

    return 0;
}