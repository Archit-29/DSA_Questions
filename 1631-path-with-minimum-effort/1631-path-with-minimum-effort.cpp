class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));

        pq.push({heights[0][0], {0, 0}});
        minCost[0][0] = 0;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        while (!pq.empty()) {

            int cost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newcost = abs( heights[row][col]-heights[nrow][ncol]);
                    if (newcost < minCost[nrow][ncol]) {
                        minCost[nrow][ncol] = newcost;
                        pq.push({newcost, {nrow, ncol}});
                    }
                }
            }
        }
        if (minCost[n - 1][m - 1] == INT_MAX)
            return -1;

        return minCost[n - 1][m - 1];
    }
};