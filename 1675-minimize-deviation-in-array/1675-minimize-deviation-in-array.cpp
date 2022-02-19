class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
         priority_queue<int>pq;
        int minnum=INT_MAX, ans=INT_MAX;
        
        for(int n:nums){
            if(n&1) n=n*2; //if n is odd multiply it by 2
            pq.push(n);
            minnum=min(minnum,n);
        }
        
        while(!(pq.top()&1)){ //while the top element is even
            int now=pq.top();
            pq.pop();
            ans=min(ans,now-minnum); // update the ans if current max deviation is less than previous ones
            minnum=min(minnum,now/2); //update the minimum number if now/2 is smaller
            pq.push(now/2);
        }
        ans=min(ans,pq.top()-minnum);
        return ans;
    }
};