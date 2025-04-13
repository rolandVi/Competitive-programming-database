#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int countGoodNumbers(long long n) {
        ll odd = n / 2;
        ll even = n - odd;
        ll sol = 0;
        ll M = 1000000007;
        sol += pow(5 , even, M);
        sol += pow(4 , odd, M);
        return int (sol % M);
    }
private:
    ll pow(ll a, ll p, ll M) {
        if (p == 0) return 1;
        ll e = pow(a, p / 2, M) % M;
        if (p % 2 == 0) return (e * e) % M;
        else return (e * e * a) % M;
    }
};