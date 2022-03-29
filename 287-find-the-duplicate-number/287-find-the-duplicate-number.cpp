class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int j=1;
        sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size();i++){
         if(nums[i]==nums[j])
             return nums[i];
         else
             j++;
     }   
        return -1;
    }
};