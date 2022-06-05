class Solution {
public:
    void doZeroRow(vector<vector<int>>& matrix, int n){
        for(int i=0;i<matrix[0].size();i++)
            matrix[n][i]=0;
    }
    void doZeroCol(vector<vector<int>>& matrix, int n){
        for(int i=0;i<matrix.size();i++)
            matrix[i][n]=0;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>r;
        vector<int>c;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for(auto e:r){
            doZeroRow(matrix,e);
        }
        for(auto e:c){
            doZeroCol(matrix,e);
        }
    }
};