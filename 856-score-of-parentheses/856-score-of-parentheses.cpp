class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(0);
            else{
                int count=0;
                while(st.top()!=0){
                    count=count+st.top();
                    st.pop();
                }
                st.pop();
                if(count==0)
                    count=1;
                else
                    count=count*2;
                st.push(count);
            }
        }
        int ans=0;
        while(st.size()!=0){
            ans=ans+st.top();
            st.pop();
        }
        return ans;
    }
};

