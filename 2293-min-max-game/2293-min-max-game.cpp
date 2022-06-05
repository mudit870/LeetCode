class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector<int>arr(nums.size()/2,0);
        for(int i=0;i<arr.size();i++){
            if(i%2==0){
                arr[i]=min(nums[2*i],nums[2*i+1]);
            }else{
                arr[i]=max(nums[2*i],nums[2*i+1]);
            }
        }
        return minMaxGame(arr);
    }
};