class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string ds;
        if(digits==" ") return {};
        vector<string> mp = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl", 
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        helper(0,digits,mp,ds,ans);
        return ans;
    }

    void helper(int index,string digits,vector<string>&mp,string& ds,vector<string>&ans){

        if(index==digits.size()){
            ans.push_back(ds);
            return;
        }
        string letters= mp[digits[index]-'0'];

        for(char letter : letters){
            ds.push_back(letter);
            helper(index+1,digits,mp,ds,ans);
            ds.pop_back();
        }
    }
};