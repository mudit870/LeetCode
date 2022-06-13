class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
                    continue;//to remove same 1d array
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]+nums[i]>0)
                    k--;
                else if(nums[j]+nums[k]+nums[i]<0)
                    j++;
                else{
                    vector<int>res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[k]);
                    ans.push_back(res);
                    while(j<k and nums[j]==res[1])j++;
                    while(j<k and nums[k]==res[2])k--;
                }
            }
        }
        return ans;
    }
};
