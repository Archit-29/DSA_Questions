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

       while(left<=right){
        if(nums1[left]<=nums1[right]){
            left++;
            right--;
        }else{
            swap(nums1[left],nums1[right]);
        }
       }
    }
};