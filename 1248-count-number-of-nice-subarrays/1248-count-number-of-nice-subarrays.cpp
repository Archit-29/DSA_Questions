class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int r = 0;
        int l = 0;
        int sum = 0;
        int count=0;

        while (r < nums.size()) {

            if (nums[r] % 2 == 1) {
                sum++;
            }
            while (sum > k) {
                if (nums[l] % 2 == 1) {
                    sum--;
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
};