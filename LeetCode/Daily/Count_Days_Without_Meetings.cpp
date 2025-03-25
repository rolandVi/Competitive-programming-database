#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int end = 0;
        for (auto const& m : meetings) {
            int s = m[0];
            int f = m[1];
            //cout << s << " " << f << "\n";

            if (s > end) {
                days -= f - s + 1;
                end = f;
            } else {
                if (f > end) {
                    days -= f - end;
                    end = f;
                }
            }

            //cout << days << "\n";
        }
        return days;
    }
};