class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dir, int sr, int sc, int n, int m){
        int size=0;
        grid[sr][sc]=0;
        for(auto d:dir){
            int r=sr+d[0];
            int c=sc+d[1];
            
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1){
                size+=dfs(grid,dir,r,c,n,m);
            }
        }
        return size+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,dir,i,j,n,m);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};