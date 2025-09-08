class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int r=0;
        int l=0;
        int maxLen=0;
        while(r<s.size()){
            
            if(mp[s[r]]!=-1){
                l=max(l,mp[s[r]]+1);
            }
            mp[s[r]]=r;

            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};