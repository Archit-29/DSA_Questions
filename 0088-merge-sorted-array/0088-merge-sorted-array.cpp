class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=0;
       while(m<nums1.size() && k<n){
            nums1[m]=nums2[k];
            m++;
            k++;
       }
       int left=0;
       int right=nums1.size()-1;

    for(int i=0;i<nums1.size();i++){
        for(int j=i+1;j<nums1.size();j++){
            if(nums1[i]>nums1[j]){
                swap(nums1[i],nums1[j]);
            }
        }
    }
    
    }
};