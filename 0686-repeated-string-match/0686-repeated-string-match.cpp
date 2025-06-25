class Solution {
public:

    void fillLps(vector<int>&lps, string b,int n){
        int i=1;
        int len=0;
        lps[0]=0;

        while(i<n){
            if(b[i]==b[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    i++;
                }
            }
        }
    }

    bool kmp(string a, string b, vector<int>&lps){
        int i=0;
        int j=0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
            if(j==b.size()) return true;
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int count=1;
        string source=a;
        while(source.size()<b.size()){
            source+=a;
            count++;
        }
        int n=b.size();
        vector<int>lps(n);
        fillLps(lps,b,n);
        if(kmp(source,b,lps)) return count;
        source+=a;
        if(kmp(source,b,lps)) return count+1;
        return -1;
    }
};