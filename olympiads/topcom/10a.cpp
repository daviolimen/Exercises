#include <bits/stdc++.h>
using namespace std;

#define double long double

struct Pt {
    int x, y;
    Pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    Pt operator+(const Pt& other) {return Pt(x + other.x, y + other.y);}
    Pt operator-(const Pt& other) {return Pt(x - other.x, y - other.y);}
    int operator*(const Pt& other) {return x * other.x + y * other.y;}
    int operator/(const Pt& other) {return x * other.y - y * other.x;}
    double dist(const Pt& other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        vector<Pt> pts(n);
        for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

        if (n <= 2) {
            cout << n << "\n";
            continue;
        } else if (n <= 3) {
            if (((pts[1] - pts[0]) / (pts[2] - pts[0])) == 0) cout << "2\n";
            else cout << "3\n";
            continue;
        }

        double ops[100][100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ops[i][j][k] = ((double) ((pts[i] - pts[j]) / (pts[k] - pts[j]))) / (pts[i].dist(pts[j]) * pts[k].dist(pts[j]));
                }
            }
        }

        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if ((i == j) || (i == k) || (j == k)) continue;
                    int ctr = 3;
                    for (int l = 0; l < n; l++) {
                        if ((i == l) || (j == l) || (k == l)) continue;
                        if (abs(ops[j][i][l] - ops[j][k][l]) < 1e-6) ctr++;
                    }
                    ans = max(ans, ctr);
                }
            }
        }

        cout << ans << "\n";
    }
}