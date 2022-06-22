class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>arr(26,0);
        for(auto e:s){
            arr[e-'a']++;
        }
        for(auto e:t){
            arr[e-'a']--;
        }
        for(auto e:arr)
            if(e>0 || e<0)
                return false;
        return true;
    }
};