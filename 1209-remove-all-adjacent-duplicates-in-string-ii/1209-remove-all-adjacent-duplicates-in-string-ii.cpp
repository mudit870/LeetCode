class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        if(n==1)return s;
        
        stack<char> st;
        stack<int> st1;
        st.push(s[0]);
        st1.push(1);
        
        for(int i=1;i<n;i++){
            if(st.size()){
                if(st.top() == s[i]){
                    if(st1.top() + 1 == k){
                        int t = k - 1;
                        assert(st.size() >= t);
                        while(t--){
                            st.pop();
                            st1.pop();
                        }
                    }
                    else{
                        st.push(s[i]);
                        st1.push(st1.top() + 1);
                    }
                }
                else{
                    st.push(s[i]);
                    st1.push(1);
                }
            }
            else{
                st.push(s[i]);
                st1.push(1);
            }
        }
        
        string ans = "";
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};