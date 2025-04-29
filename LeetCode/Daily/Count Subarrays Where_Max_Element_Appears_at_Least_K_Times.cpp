#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElem = 0;
        for (int i : nums) {
            maxElem = max(maxElem, i);
        }

        int n = nums.size();
        ll sol = 0;
        int count = nums[0] == maxElem ? 1 : 0;
        int r = 0;
        for (int l=0; l<n; l++) {
            while (r < n-1 && count < k) {
                r++;
                if (nums[r] == maxElem) count++;
            }
            if (count < k) break;
            sol += n - r;
            count -= (nums[l] == maxElem) ? 1 : 0;
        }
        return sol;
    }
};