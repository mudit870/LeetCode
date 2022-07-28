class Solution {
public:
//first we will mark any 1(only one island) of the islands as visited by making dfs call, now traverse the indexes that marked as visited, if we get other 1(other island) which is not visited yet, we will return the number of flips(connecting two island from visited 1 to non visited 1)
    
    //mark 1 whole island as visited and then search for unvisited island, side by side count flips
    
    void dfs(vector<vector<int>>& grid,int i,int j,queue<pair<int,int>>& que,vector<vector<int>>& dir,vector<vector<bool>>& vis,int n, int m){
        vis[i][j]=true;
        que.push({i,j});
        
        for(auto d:dir){
            int r=i+d[0];
            int c=j+d[1];
            
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && vis[r][c]==false){
                dfs(grid,r,c,que,dir,vis,n,m);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>>que;
        int flag=1;
        for(int i=0;i<n && flag==1;i++){
            for(int j=0;j<m && flag==1;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,que,dir,vis,n,m);
                    flag=0;//we convert 1 island as visited
                }
            }
        }
        
        int noOfFlips=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int row=que.front().first;
                int col=que.front().second;
                que.pop();
                
                for(auto d:dir){
                    int r=row+d[0];
                    int c=col+d[1];
                    
                    if(r>=0 && c>=0 && r<n && c<m && vis[r][c]==false){
                        if(grid[r][c]==1)return noOfFlips;
                        que.push({r,c});
                        vis[r][c]=true;
                    }
                }
            }
            //at 1 time flip all the connected cell of the cells present on queue
            noOfFlips++;
        }
        return -1;
    }
};


