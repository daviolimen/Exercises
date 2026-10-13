#include <bits/stdc++.h>
using namespace std;

int vr[] = {1, 1, 1, 0, 0, -1, -1, -1};
int vc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M, X, Y, K, ans = 0;
bool cheios[210][210];

void ff(int a, int b) {
    if (cheios[a][b]) return;
    cheios[a][b] = true;
    ans++;
    int c, d;
    for (int i = 0; i < 8; i++) {
        c = a + vr[i];
        d = b + vc[i];
        if ((c >= 1) && (c <= N) && (d >= 1) && (d <= M)) {
            ff(c, d);
        }
    }
}

int main() {
    cin >> N >> M >> X >> Y >> K;
    int a, b;
    for (int i = 1; i <= K; i++) {
        cin >> a >> b;
        cheios[a][b] = true;
    }
    ff(X, Y);
    cout << ans << "\n";
}