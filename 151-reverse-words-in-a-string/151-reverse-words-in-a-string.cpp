class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        s+=" ";//to insert last word easily
        for(int i=0;i<s.length();i++){
            string temp="";
            if(s[i]==' '){
                continue;
            }while(s[i]!=' ' && i<s.length()){
                temp+=s[i];
                i++;
            }
            st.push(temp);
        }
        string ans="";
        while(st.size()>1){ //last string not have space
            ans+=st.top()+" ";
            st.pop();
        }
        ans+=st.top();
        return ans;
    }
};