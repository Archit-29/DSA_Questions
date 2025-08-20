class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int r = 0;
        int l = 0;
        int count=0;

        while (r < fruits.size()) {
            mp[fruits[r]]++;
            
            if (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            count = max(count,r-l+1);
            r++;
        }
        return count;
    }
};