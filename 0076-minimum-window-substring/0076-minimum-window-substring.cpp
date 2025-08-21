class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mp(128,0);

        for(auto it:t){
            mp[it]++;
        }
        int count=0;
        int startIndex=0;
        int minLength=INT_MAX;
        int l=0,r=0;

        while(r<s.size()){
            
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;

            while(count==t.size()){
                
                if(r-l+1<minLength){
                    startIndex=l;
                    minLength=r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return minLength == INT_MAX ? "" : s.substr(startIndex, minLength);

    }
};