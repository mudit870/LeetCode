class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int ans=0;
        int j=0,i=0;
        for(;i<s.length();i++){
            if(st.count(s[i])==0){
                st.insert(s[i]);
                ans=max(ans,(int)st.size());
            }
            else{
                st.erase(s[j]);
                j++;
                i--;
            }
        }
        return ans;
    }
};