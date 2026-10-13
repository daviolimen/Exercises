#include <bits/stdc++.h>
using namespace std;

#define MAXN 501

int N, M;
string spotty[MAXN], plain[MAXN];

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
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                unordered_set<string> s;
                for (int l = 1; l <= N; l++) {
                    string a = "";
                    a.push_back(spotty[l][i]);
                    a.push_back(spotty[l][j]);
                    a.push_back(spotty[l][k]);
                    s.insert(a);
                }
                bool test = true;
                for (int l = 1; l <= N; l++) {
                    string a = "";
                    a.push_back(plain[l][i]);
                    a.push_back(plain[l][j]);
                    a.push_back(plain[l][k]);
                    if (s.find(a) != s.end()) {
                        test = false;
                        break;
                    }
                }
                if (test) ans++;
            }
        }
    }
    cout << ans << "\n";
}