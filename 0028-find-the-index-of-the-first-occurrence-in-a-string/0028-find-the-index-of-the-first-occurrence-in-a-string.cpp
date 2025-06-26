class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=haystack.size()-needle.size();
        for(int i=0;i<=len;i++){
            int j=0;
            while(j<needle.size() && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==needle.size()){
                return i;
            }
        }
        return -1;
    }
};