class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        vector<int>mp(26,0);
        int maxFreq=0;
        int maxLen=0;

        while(r<s.size()){
            mp[s[r]-'A']++;
            maxFreq=max(maxFreq,mp[s[r]-'A']);

            if(r-l+1-maxFreq > k){
                mp[s[l]-'A']--;
                l++;
                maxFreq=0;
                for(int i=0;i<26;i++){
                    maxFreq=max(maxFreq,mp[i]);
                }
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};