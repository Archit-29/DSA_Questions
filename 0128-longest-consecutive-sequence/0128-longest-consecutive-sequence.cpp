class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int elem = it + 1;
                while (st.find(elem) != st.end()) {
                    count++;
                    elem++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};