#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

struct Pt {
    int x, y;
    Pt (int _x = 0, int _y = 0) : x(_x), y(_y) {}
    Pt operator+(const Pt& a) {return Pt(x + a.x, y + a.y);}
    Pt operator-(const Pt& a) {return Pt(x - a.x, y - a.y);}
    bool operator<(const Pt& a) {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }

    long long dot(const Pt& a) {return 1ll * x * a.x + 1ll * y * a.y;}
    long long cross(const Pt& a) {return 1ll * x * a.y - 1ll * y * a.x;}
};

Pt pts[MAXN];
int n, mark[MAXN];
vector<Pt> conv, upper, lower;

void makeConv() {
    long long it1 = 0, it2 = 0;

    for (int i = 0; i < n; i++) {
        if (mark[i]) continue;

        while ((it1 >= 2) && ((pts[i] - upper[it1 - 2]).cross(upper[it1 - 1] - upper[it1 - 2]) < 0)) {
            upper.pop_back();
            it1--;
        }

        upper.push_back(pts[i]);
        it1++;

        while ((it2 >= 2) && ((pts[i] - lower[it2 - 2]).cross(upper[it2 - 1] - upper[it2 - 2]) > 0)) {
            lower.pop_back();
            it2--;
        }
        lower.push_back(pts[i]);
        it2++;
    }

    for (int i = 0; i < it1 - 1; i++) conv.push_back(upper[i]);
    for (int i = it2 - 1; i > 0; i--) conv.push_back(lower[i]);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    sort(pts, pts + n);

    makeConv();

    cout << conv.size() << "\n";

    for (int i = 0; i < conv.size(); i++) {
        cout << conv[i].x << " " << conv[i].y << "\n";
    }
    
    return 0;
}