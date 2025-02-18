class Solution {
public:
    void dfs(int node, int time,
             unordered_map<int, vector<pair<int, int>>>&adjList,
             vector<int>& minTime) {
        if (minTime[node] <= time)
            return;
        minTime[node] = time;

        for (auto& [neighbour, weight] : adjList[node]) {
            dfs(neighbour, time + weight, adjList, minTime);
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v, w});
        }

        vector<int> minTime(n + 1, INT_MAX);
        dfs(k, 0, adjList, minTime);

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (i == k)
                continue;

            if (minTime[i] == INT_MAX)
                return -1;
            maxTime = max(maxTime, minTime[i]);
        }
        return maxTime;
    }
};