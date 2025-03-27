class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
        int dominant=0,count=0,n=nums.size();

        for(int i=0;i<n;i++){
           mp[nums[i]]++;
        }

        for( auto&[num,c] : mp){
            if(c>n/2){
                dominant=num;
                count=c;
                break;
            }
        }

        int leftCount=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==dominant) leftCount++;
            int leftSize=i+1;
            int rightSize= n-leftSize;
            int rightCount=count-leftCount;

            if(leftCount>leftSize/2 && rightCount>rightSize/2) return i;
        }
        return -1;
    }
};