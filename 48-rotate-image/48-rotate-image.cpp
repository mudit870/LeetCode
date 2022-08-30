class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose of matrix
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // change left and right end column and move towards center
        for(int i=0;i<matrix.size();i++){
            int j=0,k=matrix[0].size()-1;
            while(j<k){
                swap(matrix[i][j],matrix[i][k]);
                j++;
                k--;
            }
        }
    }
};