class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=-1;
        int n=nums.size();

        for(int i=0;i<nums.size();i++){
            if(count==0){
                element=nums[i];
                count++;
            }
            else if (nums[i]==element){
                count++;
            }
            else{
                count--;
            }
        }
        
        count=0;
        for(auto it: nums){
            if(it==element) count++;
        }
        if(count > n/2) return element;
        return -1;
    }
};