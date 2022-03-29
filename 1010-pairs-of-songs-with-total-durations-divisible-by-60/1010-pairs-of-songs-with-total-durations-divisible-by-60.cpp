class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>hash(60,0);
        int ans=0;
        for(int i=0;i<time.size();i++){
            int t=time[i]%60;
            if(t==0)
                ans+=hash[t];
            else
                ans+= hash[60-t];
            hash[t]++;
        }
        return ans;
    }
};