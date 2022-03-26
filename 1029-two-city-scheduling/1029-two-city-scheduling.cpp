class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({costs[i][0]-costs[i][1],i});
        }
        int ans=0;
        int count=1;
        while(!pq.empty()){
            if(count<=n/2){
                ans+=costs[pq.top().second][1];
                pq.pop();
                count++;
            }else{
                ans+=costs[pq.top().second][0];
                pq.pop();
            }
        }
        return ans;
    }
};
