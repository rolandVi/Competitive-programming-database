#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    ll M = pow(10, 9) + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for (const auto& edge : roads) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<ll> distances(n, LLONG_MAX);
        distances[0] = 0;
        vector<ll> ways(n, 0);
        ways[0] = 1;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > distances[node]) continue;

            for (const auto& [nei, time] : adj[node]) {
                ll newDist = dist + time;

                if (newDist < distances[nei]) {
                    distances[nei] = newDist;
                    ways[nei] = ways[node];
                    pq.push({newDist, nei});
                } else if (newDist == distances[nei]) {
                    ways[nei] = (ways[nei] + ways[node]) % M;
                }
            }
        }

        return ways[n - 1];
    }
};