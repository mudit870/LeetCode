class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>o;
        vector<int>ans;
        for(auto e:nums){
            if(e%2==0)
                ans.push_back(e);
            else
                o.push_back(e);
        }
        for (auto e:o)
            ans.push_back(e);
        return ans;
    }
};