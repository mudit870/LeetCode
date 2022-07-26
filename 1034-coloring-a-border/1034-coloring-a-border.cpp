class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col,int rang,vector<vector<int>>& dir, int n, int m){
        grid[row][col]=-rang;
        int count=0;
        for(auto d:dir){
            int r=row+d[0];
            int c=col+d[1];
            if(r<0 || r>=n || c<0 || c>=m || abs(grid[r][c]) != rang) continue;
            // if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==rang){
                count++;
                if(grid[r][c] != -rang)dfs(grid,r,c,rang,dir,n,m);
            // }
        }
        if(count==4)
            grid[row][col]=rang;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        int rang=grid[row][col];
        dfs(grid,row,col,rang,dir,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-rang)
                    grid[i][j]=color;
            }
        }
        return grid;
    }
};