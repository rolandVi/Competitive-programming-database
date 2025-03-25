#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xs;
        vector<vector<int>> ys;
        for (const auto& rec : rectangles) {
            xs.push_back({rec[0], rec[2]});
            ys.push_back({rec[1], rec[3]});
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        int cuts = 0;
        int endPos = xs[0][1];
        for (const auto& pos : xs) {
            if (pos[0] >= endPos) cuts++;
            endPos = max(endPos, pos[1]);
        }
        if (cuts >= 2) return true;

        cuts = 0;
        endPos = ys[0][1];
        for (const auto& pos : ys) {
            if (pos[0] >= endPos) cuts++;
            endPos = max(endPos, pos[1]);
        }
        if (cuts >= 2) return true;

        return false;
    }
};