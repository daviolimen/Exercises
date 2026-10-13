/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: job
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("job.in");
    ofstream cout ("job.out");

    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<int> times1(m1), times2(m2);
    set<pair<int, int>> nextReady1, nextReady2;

    for (auto &x : times1) cin >> x;
    for (auto &x : times2) cin >> x;
    sort(times1.begin(), times1.end());
    sort(times2.begin(), times2.end());

    for (int i = 0; i < m1; i++) {
        nextReady1.insert({times1[i], i});
    }

    for (int i = 0; i < m2; i++) {
        nextReady2.insert({times2[i], i});
    }

    vector<int> jobs;

    for (int i = 0; i < n; i++) {
        auto it = nextReady1.begin();
        nextReady1.erase(it);
        auto P = *it;
        nextReady1.insert({P.first + times1[P.second], P.second});
        jobs.push_back(P.first);
    }

    int ans1 = jobs.back();

    vector<int> adjustedTimes;

    for (int i = 0; i < n; i++) {
        auto it = nextReady2.begin();
        nextReady2.erase(it);
        auto P = *it;
        nextReady2.insert({P.first + times2[P.second], P.second});
        adjustedTimes.push_back(P.first);
    }

    sort(adjustedTimes.begin(), adjustedTimes.end());

    int ans2 = -1;
    for (int i = 0; i < n; i++) {
        ans2 = max(ans2, adjustedTimes[i] + jobs[n - i - 1]);
    }

    cout << ans1 << " " << ans2 << "\n";
    return 0;
}