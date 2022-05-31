class Solution {
public:
    void helper(vector<vector<int>>& ret,vector<int> &v,  int targ,  int k, int sum, int now) {
        if(v.size() == k && sum == targ) {
            ret.push_back(v);
            return;
        }

        if(now < 10 && v.size() < k && sum <= targ) {    
            v.push_back(now);
            helper(ret, v,targ, k, sum + now, now+1);
            v.pop_back();
            helper(ret, v, targ, k, sum, now+1);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int targ) {
        vector<vector<int>> ret;
        vector<int> v;
        helper(ret, v, targ, k, 0, 1);
        return ret;
    }
};