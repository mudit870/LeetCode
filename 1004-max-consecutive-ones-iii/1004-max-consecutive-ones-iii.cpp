class Solution {
public:
    int longestOnes(vector<int>& nums, int zz) {
        int ans=0;
        int j=0,k=0;
        int z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)z++;
            if(z<=zz){
                k=i;
                ans=max(ans,k-j+1);
            }else{
                while(z!=zz){
                    if(nums[j]==0)
                        z--;
                    j++;
                }
            }
        }
        return ans;
    }
};