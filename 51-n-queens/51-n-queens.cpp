class Solution {
    public:
        bitset<100> col,ld,rd;
        vector<vector<string>> fans;
        void nQueen(int n, int cr, vector<string>&ans){
            if(cr==n){
            fans.push_back(ans); 
            return ;
            }
            for(int c=0;c<n;c++){
                if(!col[c] and !ld[cr-c+n-1] and !rd[cr+c]){
                    col[c] = ld[cr-c+n-1] = rd[cr+c] = 1;
                    ans[cr][c]='Q';
                    nQueen(n,cr+1,ans);
                    ans[cr][c]='.';
                    col[c] = ld[cr-c+n-1] = rd[cr+c] = 0;
                }
            } 
        }
    
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<string>ans(n,string(n,'.'));
            nQueen(n,0,ans);
            return fans;
        }
};