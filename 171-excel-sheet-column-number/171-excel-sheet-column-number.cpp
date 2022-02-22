class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(auto e:columnTitle){
            ans=ans*26 + (e-'A'+1);
        }
        return ans;
    }
};