class Solution {
public:
    int countOrders(int n) {
        // https://www.youtube.com/watch?v=GVWIUk5eID8
        long res=1,mod=1000000007;
        for(int i=1;i<=n;i++){
            res*=i;
            res%=mod;
            res*=(2*i-1);
            res%=mod;
        }
        return res%mod;
    }
};