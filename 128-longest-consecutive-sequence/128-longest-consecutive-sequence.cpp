class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(auto e:nums)mp[e]++;
        int ans=0;
        for(auto e:nums){
            if(mp.find(e-1) != mp.end()){
                continue;
            }else{
                int res=1;
                int temp=e+1;
                while(mp.find(temp)!=mp.end()){
                    res++;
                    temp++;
                }
                ans=max(ans,res);
            }
        }
        return ans;
    }
};