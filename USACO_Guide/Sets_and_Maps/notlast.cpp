#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> mp = {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second < b.second) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string name; int quant;
        cin >> name >> quant;
        mp[name] += quant;
    }

    vector<pair<string, int>> v;
    for (auto P : mp) {
        v.push_back(P);
    }

    sort(v.begin(), v.end(), cmp);

    int start = v[0].second;
    string ans;
    bool tie = false;

    for (int i = 0; i < 8; i++) {
        if (v[i].second != start) {
            if (v[i + 1].second == v[i].second) {
                tie = true;
                break;
            } else {
                ans = v[i].first;
                break;
            }
        }

        if (i == 7) {
            tie = true;
            break;
        }
    }

    if (tie) cout << "Tie\n";
    else cout << ans << "\n";
}