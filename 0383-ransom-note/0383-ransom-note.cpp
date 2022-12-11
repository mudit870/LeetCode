class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(auto e:ransomNote){
            mp[e]++;
        }
        for(auto e: magazine){
            if(mp.find(e)!=mp.end()){
                mp[e]--;
            }
            if(mp[e]==0)
                mp.erase(e);
        }
        return mp.size()==0;
    }
};