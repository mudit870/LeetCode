class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto &word : words){ // word=abc
            bool flag = true;
            unordered_map<char,int> mp1, mp2;
            for(int i=0;i<word.size();i++){
                if(mp1.count(word[i]) and mp1[word[i]] != pattern[i])//a,b,c
                    {flag = false; break;}
                if(mp2.count(pattern[i]) and mp2[pattern[i]] != word[i])
                    {flag = false; break;}
                mp1[word[i]] = pattern[i]; // a-a,b-b
                mp2[pattern[i]] = word[i]; //a-a,b-b
            }
            if(flag) ans.push_back(word);
        }
        return ans;
    }
};





































// class Solution {
// public:
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//         unordered_map<char,set<int>>mp;
//         for(int i=0;i<pattern.length();i++){
//             mp[pattern[i]].insert(i);
//         }
//         //a-0
//         //b-1,2
//         //c-3
//         vector<string>ans;
//         for(auto s:words){//ccc
//             set<char>check;
//             int flag=0;
//             for(auto e:mp){
//                 set<char>ss;
//                 for(auto it:e.second){ //0
//                 check.insert(s[it]);
//                     if(!check.count(s[it])){
//                         ss.insert(s[it]);
//                     }else{
//                         flag=1;
//                     }
//                 }
//                 if(ss.size()!=1)flag=1;
//             }
//             if(flag==0)ans.push_back(s);
//         }
//         return ans;
//     }
// };