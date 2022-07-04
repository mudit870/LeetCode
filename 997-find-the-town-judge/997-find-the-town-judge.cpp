class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //town judge should have 0 trust to other
        //town judge should have n-1 trusts on himself
        vector<int>trustBySelfOnOther(n+1,0);
        vector<int>trustByOtherOnSelf(n+1,0);
        for(auto e:trust){
            trustBySelfOnOther[e[0]]++;
            trustByOtherOnSelf[e[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(trustBySelfOnOther[i]==0 && trustByOtherOnSelf[i]==n-1)
                return i;
        }
        return -1;
    }
};