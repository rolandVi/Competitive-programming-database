#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>());
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            dp[i] = {nums[i]};
            for (int j=0; j<i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j].size() + 1 > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                    maxLen = max(maxLen, (int) dp[i].size());
                }
            }
        }

        for (int i=n-1; i>=0; i--) {
            if (dp[i].size() == maxLen) return dp[i];
        }

        return {};
    }
};