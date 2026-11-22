class Solution {
public:
    string minWindow(string s, string t) {
       vector<int>mp(256,0);
        int count=0;
        int startInd=-1;
        int minLength=INT_MAX;
        int r=0;
        int l=0;

       for(int i=0;i<t.size();i++) mp[t[i]]++;

       while(r<s.size()){
        if(mp[s[r]]>0) count++;
        mp[s[r]]--;

        while(count==t.size()){

             if(r-l+1 < minLength) {
                    minLength = r-l+1;
                    startInd = l;
                }

            mp[s[l]]++;
            if(mp[s[l]]>0) count--;
            l++;
        }
        r++;
       }
       return (startInd==-1) ? "" : s.substr(startInd,minLength);

    }
};