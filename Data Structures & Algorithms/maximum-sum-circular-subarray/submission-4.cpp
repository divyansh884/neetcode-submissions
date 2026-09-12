class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int ans=nums[0];
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=i;j<n;j++){
                temp+=nums[j];
                if(i==0 && j==n-1)
                continue;
                ans=min(ans,temp);
                ans=min(ans,sum-temp);
            }
        }
        return max(sum,sum-ans);
    }
};