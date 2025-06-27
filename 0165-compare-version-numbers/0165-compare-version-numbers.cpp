class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m=version1.size();
        int n=version2.size();
        int i=0,j=0;

        while(i<m || j<n){
            long a=0;
            long b=0;

            while(i<m && version1[i]!='.'){
                a=a*10+(version1[i]-'0');
                i++;
            }

            while(j<n && version2[j]!='.'){
                b=b*10+(version2[j]-'0');
                j++;
            }
            i++;
            j++;
            if(a>b) return 1;
            else if(a<b) return -1;
        }
        return 0;
    }
};