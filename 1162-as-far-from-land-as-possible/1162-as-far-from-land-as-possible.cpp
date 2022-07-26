class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    que.push({i,j});
                }
            }
        }
        //agar ek bhi 1 nahi hai ya saare 1 hai grid me
        if(que.size()==0 || que.size()==n*m)
            return -1;
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        int time=-1;
        while(!que.empty()){
            int size=que.size();
            time++;
            while(size--){
                int row=que.front().first;
                int col=que.front().second;
                que.pop();
                
                for(auto d:dir){
                    int r=row+d[0];
                    int c=col+d[1];
                    
                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==0){
                        grid[r][c]=1;
                        que.push({r,c});
                    }
                }
            }
        }
        return time;
    }
};