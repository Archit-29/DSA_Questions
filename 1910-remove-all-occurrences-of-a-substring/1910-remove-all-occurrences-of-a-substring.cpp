class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x=s;
        int m=part.size();
        int j=0;

        for(int i=0;i<s.size();i++){
            x[j]=s[i];
            j++;
            if(j>=m && x.substr(j-m,m)==part){
                j-=m;
            }
        }
        return x.substr(0,j);
      
    }
};