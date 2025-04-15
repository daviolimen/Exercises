// A ideia era precomputar os pares bons à esquerda e à direita de cada número, aí pra achar as triplas boas
// basta multiplicar os pares bons à esquerda com os à direita

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int sz;
        vector<long long> bit;
    
        void update(int idx, int delta) {
            for (++idx; idx < sz; idx += (idx & -idx)) {
                bit[idx] += delta;
            }
        }
    
        long long query(int idx) {
            long long res = 0;
            for (++idx; idx > 0; idx -= (idx & -idx)) {
                res += bit[idx];
            }
            return res;
        } 
    
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            sz = n + 5;
            vector<int> pos1(n), pos2(n);
            for (int i = 0; i < n; i++) {
                pos1[nums1[i]] = i;
                pos2[nums2[i]] = i;
            }

            bit.assign(sz, 0);
    
            vector<long long> dp1(n), dp2(n);
    
            for (int i = 0; i < n; i++) {
                dp1[i] = query(pos2[nums1[i]] - 1);
                update(pos2[nums1[i]], 1);
            }

            bit.assign(sz, 0);
    
            for (int i = n - 1; i >= 0; i--) {
                dp2[i] = query(sz - 3) - query(pos2[nums1[i]]);
                update(pos2[nums1[i]], 1);
            }
    
            long long ans = 0;
            for (int i = 0; i < n; i++) ans += dp1[i] * dp2[i];
            return ans;
        }
    };