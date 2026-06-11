class Solution {
public:
    void sortColors(vector<int>& nums) {
        int curr=0;
        int low=0;
        int high = nums.size()-1;

        while(curr<=high){
            if(nums[curr]==0){
                swap(nums[curr],nums[low]);
                curr++;
                low++;
            }
            else if(nums[curr]==2){
                swap(nums[curr],nums[high]);
                high--;
            }
            else{
                curr++;
            }
        }
    }
};