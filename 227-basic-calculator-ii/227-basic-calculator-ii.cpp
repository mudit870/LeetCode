class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int>st;
        char operation='+';
        int currNumber=0;
        for(int i=0;i<n;i++){
            char curr=s[i];
            if(isdigit(curr)){
                 currNumber=(currNumber*10) +(s[i]-'0');
            }
            if(!isdigit(curr) && !iswspace(curr) || i==n-1){
                if(operation=='-'){
                    st.push(-1*currNumber);
                }else if(operation=='+'){
                    st.push(currNumber);
                }else if(operation=='*'){
                    int t=st.top();
                    st.pop();
                    st.push(t*currNumber);
                }else if(operation=='/'){
                    int t=st.top();
                    st.pop();
                    st.push(t/currNumber);
                }
                operation=curr;
                currNumber=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            // cout<<st.top()<<" ";
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};