class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        int i=0;
        string ans;

        int len= min(strs[0].size(),strs[n-1].size());

        while(i<len){
                if(strs[0][i]!=strs[n-1][i]){
                    return ans;
                }
                ans+=strs[0][i];
                i++;
        }
        return ans;
    }
};