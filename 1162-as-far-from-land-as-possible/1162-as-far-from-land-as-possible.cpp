class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>que;
        int one=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    que.push({i,j});
                    one++;
                }else{
                    grid[i][j]=INT_MAX;
                }
            }
        }
        if(que.size()==0 || one==n*m)return -1;
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int row=que.front().first;
                int col=que.front().second;
                que.pop();
                
                for(auto d:dir){
                    int r=row+d[0];
                    int c=col+d[1];
                    
                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==INT_MAX){
                        grid[r][c]=min(grid[r][c],grid[row][col]+1);
                        que.push({r,c});
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,grid[i][j]);
            }
        }
        return ans-1;
    }
};