#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll cur = 0;
        ll minN = 0;
        ll maxN = 0;
        for (int i : differences) {
            cur += i;
            minN = min(minN, cur);
            maxN = max(maxN, cur);
        }
        ll dif = lower - minN;
        minN += dif;
        maxN += dif;

        if (maxN > upper) return 0;
        return upper - maxN + 1;
    }
};