class Solution {
public:
    long long dp[101][101][25];
    long long solve(int i,int prev,vector<int> &houses,vector<vector<int>> &cost,int m,int n,int target){
        if(target < 0) return 1e9;
        
        if(i == houses.size()) return target == 0 ? 0 : 1e9;
        
        if(dp[i][target][prev] != -1) return dp[i][target][prev];
        
        long long op1 = 1e9, op2 = 1e9, op3 = 1e9, ans = 1e9;
        
        if(houses[i] != 0){
            if(i == 0){
                op1 = solve(i+1,houses[i],houses,cost,m,n,target-1);
            }else{
                if(houses[i] == prev)
                    op2 = solve(i+1,prev,houses,cost,m,n,target);
                else
                    op3 = solve(i+1,houses[i],houses,cost,m,n,target-1);
            }
            ans = min({op1,op2,op3});
        }else{
            for(int j=0;j<n;j++){
                long long price = cost[i][j];
                if(i == 0){
                    op1 = price + solve(i+1,j+1,houses,cost,m,n,target-1);
                }else{
                    if(j+1 == prev){
                        op2 = price + solve(i+1,prev,houses,cost,m,n,target);
                    }else{
                        op3 = price + solve(i+1,j+1,houses,cost,m,n,target-1);
                    }
                }   
                ans = min({ans,op1,op2,op3});
            }
        }
        return dp[i][target][prev] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof dp);
        long long ans = solve(0,23,houses,cost,m,n,target); // initially the color is different from all availaible color
        return ans >= 1e9 ? -1 : ans;
    }
};
