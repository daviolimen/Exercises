#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int N, M;
string spotty[MAXN];
string plain[MAXN];

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> spotty[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> plain[i];
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        unordered_set<char> s;
        for (int j = 1; j <= N; j++) {
            s.insert(spotty[j][i]);
        }
        bool good = true;
        for (int j = 1; j <= N; j++) {
            if (s.find(plain[j][i]) != s.end()) {
                good = false;
                break;
            } 
        }
        if (good) ans++;
    }

    cout << ans << "\n";
}