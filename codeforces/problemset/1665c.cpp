#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> graph(n + 1, vector<int>());
        for (int i = 2; i <= n; i++) {
            int x; cin >> x;
            graph[x].push_back(i);
        }

        vector<int> groups;
        groups.push_back(1);
        for (int i = 1; i <= n; i++) if (graph[i].size()) groups.push_back(graph[i].size());

        sort(groups.begin(), groups.end(), greater<int>());

        int tam = groups.size();
        int ans = tam;
        multiset<int> st;

        for (int i = 0; i < tam; i++) {
            st.insert(groups[i] - tam + i);
        }

        int ctr = 0;
        while (true) {
            auto it = st.rbegin();
            if (*it > ctr) {
                int value = *it;
                st.erase(st.find(value));
                st.insert(value - 1);
                ctr++;
            } else break;
        }

        cout << ans + ctr << "\n";
    }
}