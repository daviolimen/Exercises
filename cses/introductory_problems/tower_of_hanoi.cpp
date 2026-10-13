#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int maxn = 17;

bool mark[maxn];
vector<pi> dp[maxn];

vector<pi> solve(int n) {
    if (n == 1) return {{1, 3}};
    
    if (mark[n]) return dp[n];

    mark[n] = true;

    auto aux = solve(n - 1);

    for (auto P : aux) {
        if (P.first == 2) {
            P.first = 3;
        } else if (P.first == 3) {
            P.first = 2;
        }
        if (P.second == 2) {
            P.second = 3;
        } else if (P.second == 3) {
            P.second = 2;
        }
        dp[n].push_back(P);
    }
    dp[n].emplace_back(1, 3);
    for (auto P : aux) {
        if (P.first == 1) {
            P.first = 2;
        } else if (P.first == 2) {
            P.first = 1;
        }
        if (P.second == 1) {
            P.second = 2;
        } else if (P.second == 2) {
            P.second = 1;
        }
        dp[n].push_back(P);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    for (auto P : solve(n)) {
        cout << P.first << " " << P.second << "\n";
    }
}