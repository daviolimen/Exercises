/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: sprime
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> ans;

bool isPrime(int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void search(int curr) {
    if (!isPrime(num)) return;
    if (curr == n) {
        ans.push_back(num);
        return;
    }
    num *= 10;
    for (int i = 1; i < 10; i++) {
        num += i;
        search(curr + 1);
        num -= i;
    }
    num /= 10;
}

int main() {
    ifstream cin ("sprime.in");
    ofstream cout ("sprime.out");
    cin >> n;
    search(0);
    for (auto x : ans) cout << x << "\n";
    return 0;
}