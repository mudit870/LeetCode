class Solution {
public:
    void solve(int idx, int n,int target,vector<int>& candidate,vector<vector<int>>& ans, vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=n || target<0) return;
        temp.push_back(candidate[idx]);
        solve(idx+1,n,target-candidate[idx],candidate,ans,temp);
        temp.pop_back();
        while(idx+1<n && candidate[idx]==candidate[idx+1])
            idx++;
        solve(idx+1,n,target,candidate,ans,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates.size(),target, candidates,ans,temp);
        return ans;
    }
};        
