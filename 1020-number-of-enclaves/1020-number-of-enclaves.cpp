class Solution {
public:
    void dfs(vector<vector<int>>& grid,int r, int c, vector<vector<int>>& dir,int n,int m){
        grid[r][c]=0;
        for(auto d:dir){
            int row=r+d[0];
            int col=c+d[1];
            if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==1){
                dfs(grid,row,col,dir,n,m);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        dfs(grid,i,j,dir,n,m);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};