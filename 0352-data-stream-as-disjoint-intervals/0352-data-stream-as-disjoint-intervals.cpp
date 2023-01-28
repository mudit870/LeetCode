class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        s.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> v;
        int curr=-1;
        int t=-1;
        for(auto x:s)
        {
            if(curr==-1)
            {
                t=x;
                curr=x;
            }
            else if(curr+1==x)
                curr++;
            else
            {
                v.push_back({t,curr});
                t=x;
                curr=x;
            }
        }
        v.push_back({t,curr});
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */