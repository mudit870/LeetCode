class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k) return "0";
        stack<char> st;
        st.push(num[0]);
        for(int i=1; i<n; i++){
            //You need to find the integer which is smaller than or equal to that value to 
			//the left of element like 14591 for 1 which is at index 4 ---> 1(index=0) is equal to 1(index=4)
            while(!st.empty() && k>0 && st.top() > num[i]){
                st.pop(); k--;
            }
            //what if we meet with 0 when stack is empty that means there's no sense to add 0 at the beginning.
            if(st.empty() && num[i]=='0') continue;
            st.push(num[i]);
        }
        // after loop k is still greater than 0.
        while(!st.empty() && k>0){
            st.pop(); k--;
        }
        
        if(st.empty()) return "0";
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};