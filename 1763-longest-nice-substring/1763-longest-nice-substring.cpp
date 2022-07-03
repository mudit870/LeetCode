class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.length()<2)return "";
        unordered_set<char>st;
        for(char ch:s)st.insert(ch);
        for(int i=0;i<s.length();i++){
            if(st.count(tolower(s[i]))==true && st.count(toupper(s[i]))==true)continue;
            string leftSide=longestNiceSubstring(s.substr(0,i));
            string rightSide=longestNiceSubstring(s.substr(i+1));
            
            return leftSide.length()>=rightSide.length()? leftSide : rightSide;
        }
        return s;
    }
};