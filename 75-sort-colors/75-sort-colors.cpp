class Solution {
public:
    void sortColors(vector<int>& nums) {
        int o=0;
        int z=0;
        int t=0;
        for(auto e:nums){
            if(e==0)z++;
            else if(e==1)o++;
            else t++;
        }
        for(int i=0;i<nums.size();i++){
            if(z>0){
                nums[i]=0;
                z--;
            }else if(o>0){
                nums[i]=1;
                o--;
            }else{
                nums[i]=2;
                t--;
            }
        }
    }
};