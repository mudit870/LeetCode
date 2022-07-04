class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int j=0;
        int z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)z++;
            if(z<=k){
                ans=max(ans,i-j+1);
            }else{
                while(z!=k){
                    if(nums[j]==0)
                        z--;
                    j++;
                }
            }
        }
        return ans;
    }
};