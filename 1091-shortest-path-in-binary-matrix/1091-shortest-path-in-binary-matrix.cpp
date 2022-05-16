class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         if(grid.size() == 0 || grid[0].size()==0)
            return 0;
        
        int n=grid.size(), m=grid[0].size();
        queue<int>que;
        
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;
        int pathCount=0;
        
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        que.push(grid[0][0]);
        while(que.size()!=0){
            int size=que.size();
            while(size-- > 0){
                int id=que.front();
                que.pop();
                
                int sr=id/m; 
                int sc=id%m;
                 if(sr==n-1 && sc==m-1)
                        return pathCount+1;
                for(vector<int>&d : dir){
                    int r=sr+d[0];
                    int c=sc+d[1];
                    
                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==0){
                        grid[r][c]=1;
                        que.push(r*m+c);
                    }
                }
            }
            pathCount++;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         if(grid.size()==0 || grid[0].size()==0)
//             return 0;
//         int n=grid.size();
//         int m=grid[0].size();
//         if(grid[0][0]==1 || grid[n-1][m-1]==1)
//             return -1;
//         queue<int>mq;
//         int pathcount=0;
//         mq.push(grid[0][0]);
//         vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
//         while(mq.size()!=0){
//             int size=mq.size();
//             while(size-->0){
//                 int temp=mq.front();
//                 mq.pop();

//                 int sr=temp/m;
//                 int sc=temp%m;
//                 if(sr==n-1 and sc==m-1)
//                     return pathcount+1;

//                 for(auto &d: dir){
//                     int r = sr + d[0];
//                     int c = sc + d[1];

//                     if(r>0 && c>0 && r<n && c<m && grid[r][c]==0){
//                         grid[r][c]=1;//mark visited
//                         mq.push(r*m+c);
//                     }
//                 }
//             }
//             pathcount++;
//         }
//         return -1;
//     }
// };