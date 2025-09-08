class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int r=0;
        int l=0;
        int count=0;

        while(r<s.size()){
            mp[s[r]]++;

            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                count += s.size()-r;
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return count;
    }
};