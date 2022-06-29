class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        return true;
    }
    void make_island(int i,int j,int n,int m,vector<vector<char>>& grid){
        if(!isValid(i,j,n,m) || grid[i][j]!='1'){
            return;
        }
        grid[i][j] = '0';
        make_island(i-1,j,n,m,grid);
        make_island(i+1,j,n,m,grid);
        make_island(i,j-1,n,m,grid);
        make_island(i,j+1,n,m,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    make_island(i,j,n,m,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};