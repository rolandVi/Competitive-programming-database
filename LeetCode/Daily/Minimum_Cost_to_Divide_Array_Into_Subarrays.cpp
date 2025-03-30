#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        vector<int> prefixNums(n);
        for (int i = 0; i < n; i++) {
            prefixNums[i] = nums[i];
            if (i > 0) prefixNums[i] += prefixNums[i - 1];
        }

        vector<int> prefixCost(n);
        for (int i = 0; i < n; i++) {
            prefixCost[i] = cost[i];
            if (i > 0) prefixCost[i] += prefixCost[i - 1];
        }

        auto costRange = [&](int l, int r) {
            return prefixCost[r] - (l == 0 ? 0 : prefixCost[l - 1]);
        };

        vector<ll> dp(n+1, LLONG_MAX / 10);
        dp[0] = 0;
        vector<int> subarrayNum(n+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) { // new subarray [j, i]
                dp[i+1] = min(dp[i+1], dp[j] + (ll) prefixNums[i] * costRange(j, i) + (ll) k * costRange(j, n-1));
            }
        }

        return dp[n];
    }
};