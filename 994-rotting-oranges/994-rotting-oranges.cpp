class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        int count=0;
        queue<int>mq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    count++;
                if(grid[i][j]==2)
                    mq.push(i*m+j);
            }
        }
        if(count==0)
            return 0;
        while(!mq.empty()){
            int size=mq.size();
            while(size-- >0){
                int idx=mq.front();
                mq.pop();
                int r=idx/m;
                int c=idx%m;
                for(auto d:dir){
                    int row=d[0]+r;
                    int col=d[1]+c;
                    if(row<0 || col<0 || row>=n || col>=m || grid[row][col]!=1) continue;
                    grid[row][col]=2;
                    count--;
                    mq.push(row*m+col);
                    if(count==0)
                        return time+1;
                }
            }
            time++;
        }
        return -1;
    }
};