class Solution {
public:
    int solve(int i,int j,int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i>=n || j>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a=triangle[i][j]+solve(i+1,j,n,triangle,dp);
        int b=triangle[i][j]+solve(i+1,j+1,n,triangle,dp);
        return dp[i][j]=min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,n,triangle,dp);
    }
};