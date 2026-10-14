class Solution {
public:
    int findMin(vector<int> &nums) {
        int low=0;
        int high=nums.size()-1;
        int n=nums.size();
        int ans=nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=nums[0]){
                low=mid+1;
            }
            else if(nums[mid]<nums[0]){
                high=mid-1;
                ans=nums[mid];
            }
        }
        return ans;
    }
};
