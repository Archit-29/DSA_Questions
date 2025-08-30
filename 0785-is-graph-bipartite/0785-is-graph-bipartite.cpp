class Solution {

private:
    bool dfs(int node,int val, vector<int>&color, vector<vector<int>>&graph){
        color[node]=val;
        for(auto it:graph[node]){
            if(color[it]==-1){
                if(dfs(it,!val,color,graph)==false) return false;
            }
            else if(color[it]==color[node]) return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false) return false;
            }
           
        }
        return true;
    }
};