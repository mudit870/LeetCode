class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        queue<pair<int,int>>que;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    que.push({i,j});
                }
                else{
                    matrix[i][j]=-1;
                }
            }
        }
        while(que.size()!=0){
            int size=que.size();
            while(size--){
                int row=que.front().first;
                int col=que.front().second;
                que.pop();
                for(vector<int>&d : dir){
                    int r=row+d[0];
                    int c=col+d[1];
                    
                    if(r>=0 and c>=0 and r<n and c<m and matrix[r][c]==-1){
                        matrix[r][c]=matrix[row][col]+1;
                        que.push({r,c});
                    }
                }
            }
        }
        return matrix;
    }
};