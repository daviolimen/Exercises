/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> applyRotation1(int n, const vector<vector<char>> &grid) {
    vector<vector<char>> res(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = grid[n - j - 1][i];
        }
    }
    return res;
}

vector<vector<char>> applyRotation2(int n, const vector<vector<char>> &grid) {
    return applyRotation1(n, applyRotation1(n, grid));
}

vector<vector<char>> applyRotation3(int n, const vector<vector<char>> &grid) {
    return applyRotation1(n, applyRotation1(n, applyRotation1(n, grid)));
}

vector<vector<char>> applyRotation(int x, int n, const vector<vector<char>> &grid) {
    if (x == 1) return applyRotation1(n, grid);
    else if (x == 2) return applyRotation2(n, grid);
    return applyRotation3(n, grid);
}

vector<vector<char>> applyReflection(int n, const vector<vector<char>> &grid) {
    vector<vector<char>> res(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = grid[i][n - j - 1];
        }
    }
    return res;
}

bool equal(const vector<vector<char>> &v1, const vector<vector<char>> &v2) {
    for (int i = 0; i < (int) v1.size(); i++) {
        for (int j = 0; j < (int) v1.size(); j++) {
            if (v1[i][j] != v2[i][j]) return 0;
        }
    }
    return 1;
}

int main() {
    ifstream cin ("transform.in");
    ofstream cout ("transform.out");
    int n;
    cin >> n;
    
    vector<vector<char>> bef(n, vector<char>(n)), aft(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bef[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aft[i][j];
        }
    }

    if (equal(applyRotation(1, n, bef), aft)) {
        cout << "1\n";
        return 0;
    }
    
    if (equal(applyRotation(2, n, bef), aft)) {
        cout << "2\n";
        return 0;
    }

    if (equal(applyRotation(3, n, bef), aft)) {
        cout << "3\n";
        return 0;
    }

    if (equal(applyReflection(n, bef), aft)) {
        cout << "4\n";
        return 0;
    }

    bool ok = 0;
    for (int i = 1; i <= 3; i++) {
        if (equal(applyReflection(n, applyRotation(i, n, bef)), aft)) ok = 1;
    }

    if (ok) {
        cout << "5\n";
        return 0;
    }

    if (equal(bef, aft)) {
        cout << "6\n";
        return 0;
    }

    cout << "7\n";
    return 0;
    
}