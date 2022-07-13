class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=0;
        if(nums.size()==1)return nums[0];
        // [3,3,7,7,10,11,11]
        //  0,1,2,3,4, 5, 6
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int temp=nums[mid];
            cout<<temp<<" ";
            if(mid==0 || mid==nums.size()-1)return nums[mid];
            else if(nums[mid-1]!=temp && nums[mid+1]!=temp){
                ans=nums[mid];
                break;
            }else if(nums[mid-1]==temp){
                if(mid%2!=0){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }else{
                if((nums.size()-mid)%2==0){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
        }
        return ans;
    }
};