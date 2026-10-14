class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int ans = 1;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) continue;
            mp[nums[i]]++;
            while(mp[ans]){
                ans++;
            }
        }
        return ans;
    }
};