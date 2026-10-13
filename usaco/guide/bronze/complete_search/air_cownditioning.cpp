#include <bits/stdc++.h>
using namespace std;

#define MAXN 21
#define MAXM 11

struct cow {
    int s, t, c;
};

struct airCond {
    int a, b, p, m;
};

int N, M, temps[101], ans = INT_MAX;
airCond acs[MAXM];
cow cows[MAXN];

vector<int> subset;

void solve(int i) {
    if (i == M + 1) {
        memset(temps, 0, sizeof(temps));
        int cost = 0;
        for (auto x : subset) {
            cost += acs[x].m;
            for (int j = acs[x].a; j <= acs[x].b; j++) {
                temps[j] += acs[x].p;
            }
        }

        for (auto c : cows) {
            for (int j = c.s; j <= c.t; j++) {
                if (temps[j] < c.c) {
                    return;
                }
            }
        }
        ans = min(ans, cost);
        return;
    }

    subset.push_back(i);
    solve(i + 1);
    subset.pop_back();
    solve(i + 1);
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> cows[i].s >> cows[i].t >> cows[i].c;
    }
    for (int i = 1; i <= M; i++) {
        cin >> acs[i].a >> acs[i].b >> acs[i].p >> acs[i].m;
    }
    solve(1);
    cout << ans << "\n";
}