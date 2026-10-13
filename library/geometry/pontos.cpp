#include <bits/stdc++.h>
using namespace std;

struct Pt {
    int x, y;
    Pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    Pt operator+(Pt const& a) {
        return Pt(x + a.x, y + a.y);
    }
    Pt operator-(Pt const& a) {
        return Pt(x - a.x, y - a.y);
    }
    long long operator*(Pt const& a) {
        return (1ll * x * a.x) + (1ll * y * a.y);
    }
    long long operator/(Pt const& a) {
        return (1ll * x * a.y) - (1ll * y * a.x);
    }
};