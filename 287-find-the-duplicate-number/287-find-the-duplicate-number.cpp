class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto e:nums){
            if(st.count(e))
                return e;
            st.insert(e);
        }
        return -1;
    }
};