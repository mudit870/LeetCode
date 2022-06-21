class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<heights.size()-1;++i){
            int difference = heights[i+1] - heights[i];//-2,5,-1,3,5,-2
             if(difference > 0){ 
                pq.push(difference);//5,3,5
                 if(pq.size() > ladders){
                    bricks = bricks - pq.top();//2,-3
                    pq.pop();//5
                    if(bricks < 0){
                        return i;
                    }
                 }
            }
        }
        return heights.size()-1;
    }
};