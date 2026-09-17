class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int ans=0;

        while(r<s.size()){
            if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
            
        }
        return ans;
    }
};