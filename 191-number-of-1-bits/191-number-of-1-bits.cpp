class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n>0){
        //1&1 is 1 so count will increment by 1, 
        //if last digit of n is 0 then 0&1 will be 0 and thus count is incremented by 0 i.e. remain same
            ans+=(n&1);
            n>>=1;  //right shift is used, 1 digit will be removed from n
        }
        return ans;
    }
};