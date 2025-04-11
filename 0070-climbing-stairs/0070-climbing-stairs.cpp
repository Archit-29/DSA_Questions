class Solution {
public:

    int helper(int n, unordered_map<int,int>&memo){
        if(n==0 || n==1) return 1;
        if(memo.find(n)==memo.end()){
            memo[n]=helper(n-1,memo)+helper(n-2,memo);
        }
        return memo[n];
    }
    int climbStairs(int n) {
        unordered_map<int,int>memo;
        return helper(n,memo);
    }
};