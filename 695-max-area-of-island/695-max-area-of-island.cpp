class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& dir,int sr, int sc){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>mq;
        mq.push({sr,sc});
        grid[sr][sc]=0;
        int size=0;
        while(!mq.empty()){
            int currRow=mq.front().first;
            int currCol=mq.front().second;
            mq.pop();
            for(auto d:dir){
                int r=currRow+d[0];
                int c=currCol+d[1];
                
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1){
                    grid[r][c]=0;
                    size++;
                    mq.push({r,c});
                }
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
                    int area=bfs(grid,dir,i,j);
                    ans=max(area,ans);
                }
            }
        }
        return ans;
    }
};