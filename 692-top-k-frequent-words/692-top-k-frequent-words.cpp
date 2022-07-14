class Solution {
    class comparator{
        public:
        bool operator()(pair<int,string>& a,pair<int,string>& b){
            if(a.first == b.first) {
                return a.second < b.second;
            }
            else {
                return a.first > b.first;
            }
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>umap;
        //make min heap, as we have to find top k frequent words
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator>pq;
        for(auto ele : words)
            umap[ele]++;
        for(auto ele : umap){
            pq.push({ele.second,ele.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};