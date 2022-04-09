class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(int ele:nums){
            umap[ele]++;
        }
        vector<int>ans;
        priority_queue<pair<int,int>>pq;//sort on the basis of first int
        for(auto ele:umap){
            pq.push({ele.second,ele.first});
        }
        while(ans.size()<k){
            int rem = pq.top().second;
            pq.pop();
            ans.push_back(rem);
        }
        return ans;
    }
};