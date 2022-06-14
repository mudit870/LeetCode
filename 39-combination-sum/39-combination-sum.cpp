class Solution {
public:
    void solve(int idx,int n,vector<int>& candidate,int target,vector<vector<int>>& ans,vector<int>&  temp){
        if(idx>=n || target<0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        //pick, we can pick again so not increment idx
        temp.push_back(candidate[idx]);
        solve(idx,n,candidate,target-candidate[idx],ans,temp);
        temp.pop_back();
        solve(idx+1,n,candidate,target,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates.size(),candidates,target,ans,temp);
        return ans;
    }
};