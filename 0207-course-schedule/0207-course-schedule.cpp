class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        int count=0;
        queue<int>q;

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

         for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();    
            count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return (count==numCourses);
    }
};