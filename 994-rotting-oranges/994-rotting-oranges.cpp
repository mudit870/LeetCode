class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int orange=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    orange++;
                if(grid[i][j]==2)
                    que.push({i,j});
            }
        }
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        if(orange==0)return 0;
        int time=0;
        
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int row=que.front().first;
                int col=que.front().second;
                que.pop();
                
                for(auto d:dir){
                    int r=row+d[0];
                    int c=col+d[1];
                    
                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1){
                        que.push({r,c});
                        grid[r][c]=0;
                        orange--;
                        if(orange==0)return time+1;
                    }
                }
            }
            time++;
        }
        return -1;
    }
};