class Solution {
public:

    bool isAlphanumeric(char ch){
        if(ch>='A' && ch<='Z') return true;
        if(ch>='a' && ch<='z') return true;
        if(ch>='0' && ch<='9') return true;
        return false;
    }


    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;

        while(l<r){
            
            if(!isAlphanumeric(s[l])){
                l++;
                continue;
            }
            if(!isAlphanumeric(s[r])){
                r--;
                continue;
            }
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }

        return true;
    }
};