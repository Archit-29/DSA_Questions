class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<>>minheap(nums.begin(),nums.end());
       int count=0;

       while(minheap.top()<k){
        int min1=minheap.top();
        minheap.pop();
        int min2=minheap.top();
        minheap.pop();

        minheap.push(2*min1 + min2);
        count++;
       }
       return count;
    }
};