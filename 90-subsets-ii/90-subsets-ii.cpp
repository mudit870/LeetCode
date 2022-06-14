class Solution {
public:
    void solve(int idx, int n, vector<int>& nums, vector<vector<int>>& ans,vector<int>& temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(idx+1,n,nums,ans,temp);
        temp.pop_back();
        solve(idx+1,n,nums, ans, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,nums.size(),nums,ans,temp);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};