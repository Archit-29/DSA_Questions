class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        vector<int>ans;

        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            mp[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }

        for(int nums:nums1){
            ans.push_back(mp[nums]);
        }
        return ans;
    }
};