#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string> > &ingredients,
                                  vector<string> &supplies) {
        unordered_map<string, int> ingrToInt;
        unordered_map<int, string> intToString;
        int r = recipes.size();
        int id = 0;
        for (string s: recipes) {
            if (!ingrToInt.count(s)) {
                ingrToInt[s] = id;
                intToString[id] = s;
                id++;
            }
        }
        for (auto &arr: ingredients) {
            for (string s: arr) {
                if (!ingrToInt.count(s)) {
                    ingrToInt[s] = id;
                    intToString[id] = s;
                    id++;
                }
            }
        }
        int n = id;
        vector<vector<int> > adj(n, vector<int>());
        vector<int> values(n);
        vector<string> sol;
        for (int i = 0; i < r; i++) {
            int recId = ingrToInt[recipes[i]];
            for (string ing: ingredients[i]) {
                int ingRes = ingrToInt[ing];
                adj[ingRes].push_back(recId);
            }
            values[recId] = ingredients[i].size();
        }
        queue<int> q;
        for (string s : supplies) {
            q.push(ingrToInt[s]);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nei : adj[cur]) {
                values[nei]--;
                if (values[nei] == 0) {
                    q.push(nei);
                    sol.push_back(intToString[nei]);
                }
            }
        }

        return sol;
    }
};
