class Solution {
public:
    vector<int>ans;
    Solution(vector<int>& w) {
        ans.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            ans.push_back(ans.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int randomNum=rand()%(ans.back());
        return upper_bound(ans.begin(),ans.end(),randomNum)-ans.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */