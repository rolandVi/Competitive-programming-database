#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int numTilings(int n) {
        vector<ll> t(n+1);
        if (n <= 2) return n;
        t[1] = 1;
        t[2] = 2;
        t[3] = 5;
        ll M = 1000000007;
        for (int i=4; i<=n; i++) {
            t[i] = (2* t[i-1] + t[i-3]) % M;
        }

        return t[n];
    }
    int numTilings2(int n) {
        vector<ll> t(n+1);
        if (n <= 2) return n;
        t[0] = 1;
        t[1] = 1;
        t[2] = 2;
        ll M = 1000000007;
        for (int i=3; i<=n; i++) {
            ll sum = 0;
            for (int k=3; k<=i; k++) {
                sum += t[i - k];
            }
            t[i] = (2 * sum + t[i-1] + t[i-2]) % M;
        }

        return t[n];
    }
};