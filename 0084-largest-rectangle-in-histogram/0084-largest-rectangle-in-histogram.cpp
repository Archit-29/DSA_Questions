class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
         int n=heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){

            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            pse[i]= st.empty()? -1: st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            nse[i]= st.empty()? n : st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;  
            maxi=max(maxi,area);     
        }
        return maxi;
    }
};