#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        for (int i : nums) {
            counts[i] = 0;
        }
        int r = 0;
        counts[nums[0]] = 1;

        int sol = 0;
        for (int l = 0; l < n; l++) {
            while (r < n && !good(counts)) {
                r++;
                if (r < n) counts[nums[r]]++;
            }
            if (r == n) break;
            sol += n - r;

            counts[nums[l]]--;
        }

        return sol;
    }
private:
    bool good(unordered_map<int, int>& counts) {
        for (auto& pair : counts) {
            if (pair.second <= 0) return false;
        }
        return true;
    }
};