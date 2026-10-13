#include <bits/stdc++.h>
using namespace std;

#define MAXN 201

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n;
        unordered_set<int> graph[MAXN];

        cin >> n;
        for (int i = 0; i < n; i++) {
            int p; cin >> p;
            for (int j = 0; j < p; j++) {
                int a; cin >> a; a--;
                graph[i].insert(a);
                graph[a].insert(i);
            }
        }


        vector<int> color(n, 1e9);
		bool isBipartite;
		int ans = 0;

		for (int s = 0; s < n; s++) {
			if (color[s] != 1e9)
				continue;

			isBipartite = true;
			int colorCount[2] = { 0, 0 };
			queue<int> q;
			q.push(s);
			color[s] = 0;
			colorCount[0]++;

			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
                    int v = *it;
					if (color[v] == 1e9) {
						color[v] = 1 - color[u];
						colorCount[color[v]]++;
						q.push(v);
					} else if (color[v] == color[u]) {
						isBipartite = false;
					}
				}
			}

			if (isBipartite)
				ans += max(colorCount[0], colorCount[1]);
		}

        cout << ans << "\n";
    }
}