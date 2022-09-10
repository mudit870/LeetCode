class Solution {
private:
    int dp[2][1001][1001]; // states - {buy/sell, index, k}
    int solve(int i,int k,bool buy,vector<int> &prices){
        if(i == prices.size() or !k) return 0;
        if(dp[buy][i][k] != -1) return dp[buy][i][k];
        
        int op1 = -1e9, op2 = -1e9;
        
        if(buy){
            op1 = solve(i+1,k,!buy,prices) - prices[i]; // buying
            op2 = solve(i+1,k,buy,prices); // not buying
        }else{
            op1 = solve(i+1,k-1,!buy,prices) + prices[i]; // selling
            op2 = solve(i+1,k,buy,prices); // not selling
        }
        
        return dp[buy][i][k] = max(op1,op2);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        // true -> buying, false -> selling
        return solve(0,k,true,prices);
    }
};