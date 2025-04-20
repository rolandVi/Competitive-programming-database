#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int cur = answers[0];
        int count = 0;
        int sol  = 0;
        for (int i : answers) {
            if (i == cur) count++;
            else {
                int groups = (count + cur) / (cur + 1);
                sol += groups * (cur + 1);
                cur = i;
                count = 1;
            }
        }
        int groups = (count + cur) / (cur + 1);
        sol += groups * (cur + 1);

        return sol;
    }
};