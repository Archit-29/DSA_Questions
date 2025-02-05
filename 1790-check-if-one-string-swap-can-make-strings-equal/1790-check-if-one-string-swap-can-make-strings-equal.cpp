class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>ans;
        int count=0;
    
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                ans.push_back(i);
                count++;
            }
        }

        if(count!=2 && count!=0) return false;
        if(count==0) return true;
        int i=ans[0];
        int j=ans[1];
        swap(s2[i],s2[j]);

        return s1==s2;

     
    }
};