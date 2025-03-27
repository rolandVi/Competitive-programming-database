#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dom = -1;
        int ocu = 0;
        for (int i : nums) {
            if (i == dom) ocu++;
            else {
                ocu--;
                if (ocu == -1) {
                    dom = i;
                    ocu = 1;
                }
            }
        }
        ocu = 0;
        for (int i : nums) if (i == dom) ocu++;

        int leftDom = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == dom) leftDom++;
            if (leftDom*2 > i+1 && (ocu - leftDom) * 2 > (n -1 -i)) return i;
        }
        return -1;
    }
};