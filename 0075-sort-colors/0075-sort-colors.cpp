class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,current=0,high=nums.size()-1;

        while(current<=high){
            if(nums[current]==0){
                swap(nums[current],nums[low]);
                low++;
                current++;
            }
            else if(nums[current]==2){
                swap(nums[current],nums[high]);
                high--;
            }else{
                current++;
            }
        }   
    }
};