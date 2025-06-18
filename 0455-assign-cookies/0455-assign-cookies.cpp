class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());

        int i=0;
        int j=0;
        int content=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]) {
                content++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return content;
    }
};