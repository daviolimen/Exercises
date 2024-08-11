#include <bits/stdc++.h>
using namespace std;

struct Pt {
    int x, y;
    Pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    Pt operator +(const Pt &b) {return Pt(x + b.x, y + b.y);}
    Pt operator -(const Pt &b) {return Pt(x - b.x, y - b.y);}
    int operator *(const Pt &b) {return x * b.x + y * b.y;}
    int operator /(const Pt &b) {return x * b.y - y * b.x;}
    int dist() {
        return x * x + y * y;
    }
};

Pt p[8];

bool check() {
    if ((p[2] - p[1]) * (p[3] - p[1]) < 0) return false;
    if ((p[2] - p[1]).dist() != (p[3] - p[1]).dist()) return false;
    if ((((p[3] - p[2]) / (p[4] - p[2])) != 0) || (((p[3] - p[2]) / (p[3] - p[5])) != 0)) return false;
    if (((p[3] + p[2]).x != (p[4] + p[5]).x) || ((p[3] + p[2]).y != (p[4] + p[5]).y)) return false;
    if ((p[5] - p[4]).dist() >= (p[3] - p[2]).dist()) return false;
    if ((((p[6] - p[4]) * (p[3] - p[2])) != 0) || (((p[7] - p[5]) * (p[3] - p[2])) != 0)) return false;
    if ((p[6] - p[4]).dist() != (p[7] - p[5]).dist()) return false;
    int dir1 = (p[3] - p[2]) / (p[1] - p[2]);
    int dir2 = (p[3] - p[2]) / (p[6] - p[2]);
    if ((dir1 == 0) && (dir2 == 0)) return false;
    dir1 /= abs(dir1);
    dir2 /= abs(dir2);
    if (dir1 * dir2 >= 0) return false;
    return true;
}

int main() {
    for (int i = 1; i <= 7; i++) cin >> p[i].x >> p[i].y;
    cout << ((check()) ? "S\n" : "N\n");
}