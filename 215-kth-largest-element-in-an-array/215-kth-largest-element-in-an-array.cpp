class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto e:nums){
            pq.push(e);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};