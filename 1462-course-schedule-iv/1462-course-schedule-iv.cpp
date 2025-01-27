class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& qu) {
        
        if(p.size()==0){
            vector<bool> res(n,false);
            return res;
        }
        vector<vector<int>> g(n);
        queue<int> q;
        
        vector<vector<int>> ir(n,vector<int>(n,0));

        vector<bool> ans;
        for(int i = 0;i < p.size();i++){
            g[p[i][0]].push_back(p[i][1]);
         }
         
        for(int i = 0;i < n;i ++){
            q.push(i);
            while(!q.empty()){
                int f = q.front();
                q.pop();
                for(int nei : g[f]){
                    if(ir[i][nei])
                        continue;
                    ir[i][nei]=1;
                    q.push(nei);
                }
            }
        }
        
        for(int i = 0;i < qu.size();i++){
            ans.push_back(ir[qu[i][0]][qu[i][1]]);
        }
        
        return ans;
    }
   
};
