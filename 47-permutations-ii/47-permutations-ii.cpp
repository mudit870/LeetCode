class Solution {
public:
//     vector<vector<int>>ans;
//     void permu(vector<int>& nums, int i){
//         if(i==nums.size()){
//             ans.push_back(nums);
//             return;
//         }
        
//     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        // vector<int>res;
        // permu(nums,0);
        set<vector<int>> st;
        vector<int> temp = nums;
        do
        {
            next_permutation(temp.begin(), temp.end());
            st.insert(temp);
        } while (temp != nums);
        vector<vector<int>> ans;
        for (auto it: st)
            ans.push_back(it);
        return ans;
    }
};