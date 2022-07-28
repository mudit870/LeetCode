class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto e:s)
            mp[e]++;
        for(auto e:t)
            mp[e]--;
        for(auto e:mp)
            if(e.second!=0)return false;
        return true;
    }
};