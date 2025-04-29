/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: zerosum
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> op;
vector<vector<int>> ans;

void search(int curr) {
    if (curr == n - 1) {
        vector<int> val, op2;
        val.push_back(1);
        for (int i = 0; i < n - 1; i++) {
            if (op[i] == 0) {
                val.back() = val.back() * 10 + i + 2;
            } else {
                op2.push_back(op[i]);
                val.push_back(i + 2);
            }
        }

        int eval = val[0];
        for (int i = 1; i < val.size(); i++) {
            if (op2[i - 1] == 1) {
                eval += val[i];
            } else {
                eval -= val[i];
            }
        }

        if (eval == 0) {
            ans.push_back(op);
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        op.push_back(i);
        search(curr + 1);
        op.pop_back();
    }
}

int main() {
    ifstream cin ("zerosum.in");
    ofstream cout ("zerosum.out");
    cin >> n;
    search(0);
    sort(ans.begin(), ans.end());
    for (auto X : ans) {
        for (int i = 0; i < n - 1; i++) {
            cout << i + 1;
            if (X[i] == 0) cout << " ";
            else if (X[i] == 1) cout << "+";
            else cout << "-";
        }
        cout << n;
        cout << "\n";
    }
    return 0;
}