#include <bits/stdc++.h>
using namespace std;

#define MAXN 50010
#define MAXM 100010

struct edge {
    int a, b, c;
};

bool cmpLess(pair<edge, int> &a, pair<edge, int> &b) {
    return a.first.c < b.first.c;
}

bool cmpGreat(pair<edge, int> &a, pair<edge, int> &b) {
    return a.first.c > b.first.c;
}

int n, m, pai[MAXN], peso[MAXN];
long long s;
pair<edge, int> edgeList[MAXM];

void init() {
    for (int i = 0; i < MAXN; i++) pai[i] = i;
}

int find(int x) {
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] < peso[y]) pai[x] = y;
    else if (peso[y] < peso[x]) pai[y] = x;
    else {
        pai[y] = x;
        peso[x]++;
    }
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    init();
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        cin >> edgeList[i].first.a >> edgeList[i].first.b >> edgeList[i].first.c;
        edgeList[i].second = i + 1;
    }

    sort(edgeList, edgeList + m, cmpGreat);

    unordered_set<int> used;

    for (int i = 0; i < m; i++) {
        if (find(edgeList[i].first.a) != find(edgeList[i].first.b)) {
            join(edgeList[i].first.a, edgeList[i].first.b);
            used.insert(edgeList[i].second);
        }
    }

    sort(edgeList, edgeList + m, cmpLess);
    vector<int> ans;

    for (int i = 0; i < m; i++) {
        if ((used.find(edgeList[i].second) == used.end()) && (s - edgeList[i].first.c >= 0)) {
            s -= edgeList[i].first.c;
            ans.push_back(edgeList[i].second);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}