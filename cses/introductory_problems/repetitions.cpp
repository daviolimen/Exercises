#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string dna;
    cin >> dna;
    char prev = dna[0];
    char curr;
    int curr_seq = 1;
    int max_seq = 1;
    for (int i = 1; i < dna.length(); i++) {
        curr = dna[i];
        if (curr == prev) {
            curr_seq++;
        } else {
            if (curr_seq > max_seq) {
                max_seq = curr_seq;
            }
            curr_seq = 1;
        }
        prev = curr;
    }
    if (curr_seq > max_seq) {
        max_seq = curr_seq;
    }
    cout << max_seq << "\n";
}