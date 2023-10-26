#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
bitset<1000001> mark;

int main() {
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    if (sum % 2 == 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n == 3) {
        cout << "1\n3\n2\n1 2\n";
    } else {
        ll setSum = sum / 2, currSum = 0;
        for (int l = 1, r = n; currSum != setSum; ++l, --r) {
            if ((setSum - currSum <= n) && (!mark[setSum - currSum])) {
                mark[setSum - currSum] = 1;
                currSum += setSum - currSum;
            } else {
                currSum += l + r;
                mark[l] = 1;
                mark[r] = 1;
            }
        }
        vector<int> set1, set2;
        for (int i = 1; i <= n; i++) {
            if (mark[i]) set1.push_back(i);
            else set2.push_back(i);
        }
        cout << set1.size() << "\n";
        for (auto x : set1) cout << x << " ";
        cout << "\n";
        cout << set2.size() << "\n";
        for (auto x : set2) cout << x << " ";
        cout << "\n";
    }
}