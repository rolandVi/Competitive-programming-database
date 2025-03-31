#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;
        k--;
        vector<int> sums(n-1);
        for (int i = 0; i < n-1; i++) {
            sums[i] = weights[i] + weights[i+1];
        }

        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<>> minpq;

        for (int i : sums) {
            if (maxpq.size() < k) {
                maxpq.push(i);
                minpq.push(i);
            } else {
                if (maxpq.top() > i) {
                    maxpq.pop();
                    maxpq.push(i);
                }
                if (minpq.top() < i) {
                    minpq.pop();
                    minpq.push(i);
                }
            }
        }

        ll sol = 0;
        for (int i=0; i<k; i++) {
            sol += (ll) minpq.top();
            sol -= (ll) maxpq.top();
            minpq.pop();
            maxpq.pop();
        }

        return sol;
    }
};