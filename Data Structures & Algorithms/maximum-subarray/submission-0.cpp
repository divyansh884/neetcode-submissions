class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0,n=nums.size();
        int sum=0;
        int ans=nums[0];
        for(int j=0;j<n;j++){
            while(sum<0){
                sum-=nums[i];
                i++;
            }
            sum+=nums[j];
            ans=max(ans,sum);
        }
        return  ans;
    }
};
