class Solution {
public:
    int findMaxPath(vector<vector<int>>& matrix, int i,int j,vector<vector<int>>& dir){
        int n=matrix.size();
        int m=matrix[0].size();
        if(dp[i][j]) return dp[i][j];
        dp[i][j]=1;
        for(auto &d: dir){
            int row=i+d[0];
            int col=j+d[1];
            if(row>=0 && col>=0 && row<n && col<m && matrix[row][col]>matrix[i][j]){
                dp[i][j]=max(dp[i][j], 1+findMaxPath(matrix,row,col,dir));
            }
            
        }
        return dp[i][j];
    }
    
    vector<vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n, vector<int> (m,0));
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,findMaxPath(matrix,i,j,dir));
            }
        }
        return ans;
    }
};