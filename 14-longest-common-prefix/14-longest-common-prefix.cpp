class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string prefix=strs[0];
        string ans="";
        int j=0;
        for(char c:prefix){
            for(int i=1;i<strs.size();i++){
                if(j>=strs[i].length() || c!=strs[i][j])
                    return ans;
            }
            ans+=c;
            j++;
        }
        return ans;
    }
};