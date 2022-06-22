class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<int>st;
    vector<int>res;
    int i=0;
    int next(int price) {
        res.push_back(price);
        
        while(!st.empty() and res[st.top()] <= price){
            st.pop();
        }
        
        int ans;
        if(st.empty()) ans= i+1;
        else
            ans= res.size()-st.top()-1;
        
        st.push(i);
        i++;
            
        return ans;    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */