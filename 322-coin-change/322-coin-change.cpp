class Solution {
public:
    long long int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp){
        if(amount==0)
            return 0;
        if(i==0)
            return INT_MAX;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        long long int ans;
        if(coins[i-1]>amount){
            ans=solve(coins,amount,i-1,dp);
        }else{
             ans = min(solve(coins, amount,i-1,dp), 1+solve(coins, amount-coins[i-1],i,dp));
        }
        return dp[i][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,n,dp);
        return (ans==INT_MAX)? -1:ans;
    }
};