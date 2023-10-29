#include <bits/stdc++.h>
using namespace std;

int N;
pair<string, string> cts[7];
string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a; cin >> a;
        cts[i].first = a;
        cin >> a >> a >> a >> a >> a;
        cts[i].second = a;
    }

    sort(cows, cows + 8);

    do {
        unordered_map<string, int> mp;
        for (int i = 0; i < 8; i++) {
            mp[cows[i]] = i;
        }

        bool lesgo = true;
        for (int i = 0; i < N; i++) {
            if (abs(mp[cts[i].first] - mp[cts[i].second]) > 1) {
                lesgo = false;
                break;
            }
        }
        if (lesgo) break;
    } while (next_permutation(cows, cows + 8));

    for (int i = 0; i < 8; i++) {
        cout << cows[i] << "\n";
    }

}