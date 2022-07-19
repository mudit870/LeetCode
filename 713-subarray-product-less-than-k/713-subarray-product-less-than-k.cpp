class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p=1;
        int ans=0;
        int j=0;
        if(k<=1)return 0;
        for(int i=0;i<nums.size();i++){
            p*=nums[i];
            while(p>=k){
                //remove no. from left side
                p/=nums[j];
                j++;
            }
            ans+=i-j+1;
        }
        return ans;
    }
};