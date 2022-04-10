class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        stack<int> st;
        int helper1, helper2;
        
        for(auto it:ops)
        {
            if(it=="C")
            {
                st.pop();
            }
            
            else if(it=="D")
            {
                st.push(2*st.top());
            }
            
            else if(it=="+")
            {
                helper1=st.top();
                st.pop();
                helper2=st.top();
                st.push(helper1);
                st.push(helper1+helper2);
            }
            else
            {
                st.push(stoi(it));
            }
        }
        
        int ans=0;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};