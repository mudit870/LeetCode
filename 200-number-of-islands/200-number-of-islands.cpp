class Solution {
public:
    void dfs(vector<vector<char>>& grid,int sr,int sc, vector<vector<int>>& dir){
        int n=grid.size();
        int m=grid[0].size();
        grid[sr][sc]='0';
        for(auto d:dir){
            int r=sr+d[0];
            int c=sc+d[1];
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]=='1'){
                dfs(grid,r,c,dir);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,dir);
                    ans++;
                }
            }
        }
        return ans;
    }
};