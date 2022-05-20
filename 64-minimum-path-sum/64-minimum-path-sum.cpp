class Solution {
public:
    int findPath(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i<0 || j<0)
            return INT_MAX;
        if(i==0 && j==0)
            return grid[0][0];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]= grid[i][j] + min(findPath(i-1,j,grid,dp),findPath(i,j-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return findPath(n-1,m-1,grid,dp);
    }
};