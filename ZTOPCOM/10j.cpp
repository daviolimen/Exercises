#include <bits/stdc++.h>
using namespace std;

bool visited[10000];
int dist[10000];
int vals[] = {1000, 100, 10, 1, 1100, 110, 11, 1110, 111, 1111};

vector<int> prox(int u) {
    vector<int> res;
    vector<int> digs1(4);
    for (int i = 0; i < 4; i++) {
        digs1[i] = (u % 10);
        u /= 10;
    }
    reverse(digs1.begin(), digs1.end());
    for (int i = 0; i < 10; i++) {
        int val = vals[i];
        int alr1 = 0, alr2 = 0;
        
        for (int j = 0; j < 4; j++) {
            int cur = val % 10;
            val /= 10;
            int dig1 = (digs1[j] + cur) % 10;
            int dig2 = (digs1[j] + 10 - cur) % 10;
            alr1 = (alr1 * 10) + dig1;
            alr2 = (alr2 * 10) + dig2;
        }
        res.push_back(alr1);
        res.push_back(alr2);
    }
    return res;
}

void dijkstra(int start) {
    visited[start] = 1;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto x : prox(u)) {
            if (visited[x]) continue;
            visited[x] = 1;
            dist[x] = dist[u] + 1;
            q.push(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    dijkstra(0);
    int tt = 1;
    while (true) {
        string A, B; cin >> A >> B;
        if ((A == "0") && (B == "0")) break;
        string nova = "0000";
        for (int i = 0; i < 4; i++) {
            nova[i] = (20 + (int) B[i] - (int) A[i]) % 10;
            nova[i] += '0';
        }
        int fim = stoi(nova);
        if (tt > 1) cout << "\n";
        cout << "Teste " << tt << "\n";
        cout << dist[fim] << "\n";
        tt++;
    }
}