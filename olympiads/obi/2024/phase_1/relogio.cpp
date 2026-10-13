#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, s, t; cin >> h >> m >> s >> t;
    int horaseg = h * 3600 + m * 60 + s + t;
    h = (horaseg / 3600) % 24;
    m = (horaseg % 3600) / 60;
    s = (horaseg % 60);
    cout << h << "\n" << m << "\n" << s << "\n";
}