class Solution {
public:
    int hammingWeight(uint32_t n) {
//         Kernighan's algorithm
        int ans=0;
         while(n){
            int rmsb = n & (-n); //rightmost set bit mask
            n -= rmsb;
            ans++;
        }
        return ans;
    }
};