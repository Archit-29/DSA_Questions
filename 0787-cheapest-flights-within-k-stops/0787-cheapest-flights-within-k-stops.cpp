#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int, int>>> q; // {stops, {cost, node}}
        vector<vector<pair<int, int>>> adjList(n);
        
        for (auto& flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> minCost(n, INT_MAX);
        q.push({0, {0, src}}); // {stops, {cost, node}}
        minCost[src] = 0;

        while (!q.empty()) {
            auto [stops, current] = q.front();
            int cost = current.first;
            int node = current.second;
            q.pop();

            if (stops > k) continue; // If stops exceed k, skip processing.

            for (auto [neighbor, price] : adjList[node]) {
                int newCost = cost + price;
                if (newCost < minCost[neighbor]) {
                    minCost[neighbor] = newCost;
                    q.push({stops + 1, {newCost, neighbor}});
                }
            }
        }
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
