#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int sol = 0;
        unordered_set<int> visited;
        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                unordered_set<int> comp;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    visited.insert(cur);
                    comp.insert(cur);
                    for (int nei : adj[cur]) {
                        if (!comp.count(nei)) {
                            q.push(nei);
                        }
                    }
                }

                bool good = true;
                int c = comp.size();
                for (int i : comp) {
                    if (adj[i].size() != c-1) {
                        good = false;
                        break;
                    }
                }
                if (good) sol++;
            }
        }
        return sol;
    }
};