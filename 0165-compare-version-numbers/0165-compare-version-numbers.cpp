class Solution {
public:

    int compareVersion(string version1, string version2) {

        int i=0;
        int j=0;
        
        while(i<version1.size() || j<version2.size()){
            int a=0;
            int b=0;

            while(i<version1.size() && version1[i]!='.'){
                a=a*10+(version1[i]-'0');
                i++;
            }

            while(j<version2.size() && version2[j]!='.'){
                b=b*10+(version2[j]-'0');
                j++;
            }

            if(a>b) return 1;
            if(a<b) return -1;

            i++;
            j++;
        }

        return 0;
    }
};