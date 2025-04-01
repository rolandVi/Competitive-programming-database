#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n, -1);
        return rec(0, questions, dp, n);
    }
private:
    long long rec(int i, vector<vector<int>>& questions, vector<ll>& dp, int n) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        ll ans = max(rec(i + 1, questions, dp, n), (ll) questions[i][0] + rec(i + questions[i][1] + 1, questions, dp, n));
        return dp[i] = ans;
    }
};