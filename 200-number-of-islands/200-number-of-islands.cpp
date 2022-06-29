class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r,int c, vector<vector<int>>& dir){
        int n=grid.size();
        int m=grid[0].size();
        grid[r][c]='0';
        for(auto d:dir){
            int sr=r+d[0];
            int sc=c+d[1];
            if(sr>=0 && sc>=0 && sr<n && sc<m && grid[sr][sc]=='1'){
                dfs(grid,sr,sc,dir);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j,dir);
                }
            }
        }
        return ans;
    }
};