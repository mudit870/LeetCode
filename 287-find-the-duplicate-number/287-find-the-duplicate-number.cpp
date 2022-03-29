class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            // as it is in range from 1 to n so we take abs to get right index
            int val=abs(nums[i]);
            // first time at that index value will be positive
            if(nums[val]>0)
                nums[val]=-nums[val];
            // if again come to same index, value will be negative , so return this value
            else{
                return val;
            }
        }
        return -1;
    }
};