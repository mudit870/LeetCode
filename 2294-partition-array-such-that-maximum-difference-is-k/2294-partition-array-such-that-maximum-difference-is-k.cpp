class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int j=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-j>k){
                count++;
                j=nums[i];
            }
        }
        return count+1;
    }
};