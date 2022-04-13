class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int tc=0,bc=n-1,tr=0,br=n-1,a=1;
        while(tc<=bc && tr<=br){
                for(int j=tc;j<=bc;j++){
                    ans[tr][j]=a;
                    a++;
                }tr++;
                for(int i=tr;i<=br;i++){
                    ans[i][bc]=a;
                    a++;
                }bc--;
                for(int j=bc;j>=tc;j--){
                    ans[br][j]=a;
                    a++;
                }br--;
                for(int i=br;i>=tr;i--){
                    ans[i][tc]=a;
                    a++;
                }tc++;
        }
        return ans;
    }
};