class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;// imp.
        if(nums.size()==1)
            return nums[0];
        //even and odd indexes should be same as index start from 0
        //if even index and it's next index same, move low to mid+1 
        while(low<=high){
            int mid=low+(high-low)/2;
            cout<<mid<<" "<<low<<" "<<high<<" "<<endl;
            if(mid%2==0 && nums[mid]==nums[mid+1]){
            //search right side
                low=mid+1;
            }else if(mid%2!=0 && nums[mid]==nums[mid-1]){
                // search right side
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};