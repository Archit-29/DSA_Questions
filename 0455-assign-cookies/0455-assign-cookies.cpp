class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int ans=0;
        int left=0;
        int right=0;

        while(left<g.size() && right<s.size()){
            if(g[left]<=s[right]){
                ans++;
                left++;
                right++;
            }else{
                left++;
            }
            
        }
        return ans;
    }
};