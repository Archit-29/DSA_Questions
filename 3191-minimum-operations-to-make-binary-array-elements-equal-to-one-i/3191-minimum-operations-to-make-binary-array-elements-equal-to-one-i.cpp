class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;

        if(nums.size() < 3) return -1;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == 0) {
                for (int j = 0; j < 3; j++) {
                    nums[i + j] = !nums[i + j];
                }
                count++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                return -1;
        }

        return count;
    }
};