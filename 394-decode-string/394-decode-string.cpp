class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }else{
                string ans="";
                while(st.top()!='['){
                    //a b c
                    //ans- c,bc,abc
                    ans=st.top()+ans;
                    st.pop();
                }
                //pop the top char i.e. '['
                st.pop();
                string num="";
                while(!st.empty() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int k=stoi(num);//no. of times to print ans string
                
                while(k--){
                    // /we have to push the string so formed in stack
                    for(auto e:ans)st.push(e);
                }
            }
        }
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};