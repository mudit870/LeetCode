class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=max(nums[i],nums[i]+sum);
            ans=max(ans,sum);
        }
        return ans;
    }
};
// sum=-2
// nums=1+-3=-2
//     -2>-3