class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int left=0;
        int right=0;
        int count=0;

        while(right<s.size()){
           
            if(mp[s[right]]!=-1){
                left=max(left,mp[s[right]]+1);
            }
            mp[s[right]]=right;
            count=max(count,right-left+1);
            right++;
            
        }

        return count;
    }
};