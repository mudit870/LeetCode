class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // new column after shift will be j+k % no. of columns
                int col=(j+k)%m;
                // now for row, first the no. of rows added is (j+k)/no. of column
                // new row will be (i+(j+k)/m)%m
                int row=(i+(j+k)/m)%n;
                ans[row][col]=grid[i][j];
            }
        }
        return ans;
    }
};