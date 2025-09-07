class Solution {
public:

    int lcs(int i, int j,string s, string r,vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==r[j]){
            return dp[i][j]= 1+lcs(i-1,j-1,s,r,dp);
        }
        else{
            return dp[i][j] = max(lcs(i-1,j,s,r,dp),lcs(i,j-1,s,r,dp));
        }
    }

    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return lcs(n-1,n-1,s,r,dp);
    }
};