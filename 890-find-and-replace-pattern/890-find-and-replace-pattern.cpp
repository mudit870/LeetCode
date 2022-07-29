class Solution {
public:
    bool solve(string &s1, string &s2) {
    unordered_map<char, int> m1, m2;
    if(s1.size() != s2.size()) {
        return false;
    }
    for(int i=0 ; i<s1.size() ; i++) {
        if( m1[s1[i]] != m2[s2[i]])
            return false;
        m1[s1[i]] = i+1;
        m2[s2[i]] = i+1;
    }
    return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    for(auto &str : words) {
        if(solve(str , pattern))
            ans.push_back(str);
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