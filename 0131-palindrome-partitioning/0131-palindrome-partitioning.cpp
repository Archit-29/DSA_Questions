class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        helper(0,s,ds,ans);
        return ans;
    }

    void helper(int index,string s,vector<string>ds,vector<vector<string>>&ans ){
        if(index==s.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(index,i,s)){
                ds.push_back(s.substr(index,i-index+1));
                helper(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(int start,int end, string s){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};