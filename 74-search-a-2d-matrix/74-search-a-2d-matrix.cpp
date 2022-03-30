class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,k;
        bool flag=false;
        while(i<n){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                flag=true;
                k=i;
                break;
            }else{
                i++;
            }
        }
        if(!flag)
            return false;
        for(int j=0;j<m;j++){
            if(matrix[k][j]==target)
                return true;
        }
        return false;
    }
};