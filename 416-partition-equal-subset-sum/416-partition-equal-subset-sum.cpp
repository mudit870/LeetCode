class Solution {
public:
    bool solve(vector<int>& nums, int target,int idx,vector<vector<int>>& dp){
        if(target==0)return true;
        if(idx>=nums.size())return false;
        if(dp[idx][target]!=-1)return dp[idx][target];
        bool consider=false;
        if(nums[idx]<=target){
            consider=solve(nums,target-nums[idx],idx+1,dp);
        }
        bool notConsider=solve(nums,target,idx+1,dp);
        return dp[idx][target]=consider || notConsider;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto e:nums){
            sum+=e;
        }
        int target=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        if(sum%2!=0)return false;
        return solve(nums,target,0,dp);
    }
};