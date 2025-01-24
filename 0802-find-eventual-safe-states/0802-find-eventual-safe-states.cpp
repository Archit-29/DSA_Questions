class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<vector<int>> R(V);
        queue<int> q;
        vector<int> indegree(V),safeNodes;


        for(int i=0;i<V;i++){
            for(auto it : graph[i]){
                R[it].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node= q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto it: R[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
        return  safeNodes;
    }
};