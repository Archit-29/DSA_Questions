class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;

        while(i<n && s[i]==' '){
            i++;
        }

        int sign=1;
        if(s[i]=='-' || s[i]=='+'){
            sign= s[i]=='-' ? -1 : 1;
            i++;
        }
        long long ans=0;;
        while(i<n && s[i]>='0' && s[i]<='9'){
            ans = ans*10 + (s[i]-'0');
            i++;
            if(sign*ans <= INT_MIN) return INT_MIN;
            if(sign*ans >= INT_MAX) return INT_MAX;
        }

        return sign*ans;
    }
};