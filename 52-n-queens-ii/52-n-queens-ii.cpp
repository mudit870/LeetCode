class Solution {
public:
    bool isSafe(vector<vector<char>> &grid,int n, int m){
        //col
        for(int i=n-1;i>=0;i--){
            if(grid[i][m]=='Q')
                return false;
        }
        //left diag
        for(int i=n,j=m;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q')
                return false;
        }
        //right diag
        for(int i=n,j=m;i>=0 && j<grid.size();i--,j++){
            if(grid[i][j]=='Q')
                return false;
        }
        return true;
    }
    int ans=0;
    void solve(vector<vector<char>> &grid,int i){
        if(i==grid.size()){
            ans++;
            return;
        }
        if(i>grid.size())
            return ;
        int n=grid.size();
        for(int j=0;j<n;j++){
            if(grid[i][j]=='.'){
                if(isSafe(grid,i,j)){
                    grid[i][j]='Q';
                    solve(grid,i+1);
                    grid[i][j]='.';
                }
                
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>>grid(n,vector<char>(n,'.'));
        solve(grid,0);
        return ans;
    }
};