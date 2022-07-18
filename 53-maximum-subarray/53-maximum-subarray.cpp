class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<n;i++){
            nums[i]=max(nums[i],nums[i]+nums[i-1]);
            ans=max(ans,nums[i]);
        }
        return ans;
    }
};