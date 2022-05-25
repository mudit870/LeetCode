class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        if(n<2)
            return 0;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='(')
                    st.pop();
            else 
                st.push(i);
            }
        }
        int ans=0;
        int length=n;
        while(!st.empty()){
            cout<<st.top();
            int currLength=st.top();
            st.pop();
            ans=max(ans,length-currLength-1);
            length=currLength;
        }
        return max(length,ans);
    }
};