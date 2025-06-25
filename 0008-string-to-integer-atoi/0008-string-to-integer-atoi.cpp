class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        long long ans=0;;
        int sign=1;;

        while(i<n && s[i]==' '){
            i++;
        }

        if(i<n && (s[i]=='-'||s[i]=='+')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }

        while(i<n && s[i]>='0' && s[i]<='9'){
            int d= s[i]-'0';
            ans=ans*10+d;

            if(sign*ans<=INT_MIN) return INT_MIN;
            if(sign*ans>=INT_MAX) return INT_MAX;

            i++;
        }
        return sign*ans;
    }
};