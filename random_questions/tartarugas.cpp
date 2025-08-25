#include <bits/stdc++.h>
using namespace std;

string trash;
pair<int, int> r, arr[3];
int ordens[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int tempo() {
    int min = 1e8;
    for (int i = 0; i < 6; i++) {
        auto f = arr[ordens[i][0]];
        int total = abs(r.first - f.first) + abs(r.second - f.second);
        for (int j = 1; j < 3; j++) {
            auto s = arr[ordens[i][j]];
            total += abs(s.first - f.first) + abs(s.second - f.second);
            f = s;
        }
        if (total < min) min = total;
    }
    return min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r.first >> r.second;
    while ((r.first != 0) && (r.second != 0)) {
        for (int i = 0; i < 3; i++) cin >> arr[i].first >> arr[i].second >> trash;
        cout << tempo() << "\n";
        cin >> r.first >> r.second;
    }
}