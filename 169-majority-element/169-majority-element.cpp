class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        int count=0;
        //if same no. come we will increase the count else decrease
        //as majority element is present so count will be positive
        for(int e:nums){
            if(count==0)
                ans=e;
            if(e==ans)
                count++;
            else
                count--;
        }
        return ans;
    }
};