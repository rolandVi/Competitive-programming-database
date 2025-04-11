#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int sol = 0;
        for (int i = low; i <= high; i++) {
            sol += (isSimetric(i) ? 1 : 0);
        }
        return sol;
    }
private:
    bool isSimetric(int a) {
        string s = to_string(a);
        int len = s.length();
        if (len % 2 != 0) return false;

        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (i < len / 2) {
                sum += (s[i] - '0');
            } else {
                sum -= (s[i] - '0');
            }
        }
        return sum == 0;
    }
};