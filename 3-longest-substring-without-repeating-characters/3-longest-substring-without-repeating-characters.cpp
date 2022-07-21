class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map<char,int>mp;
        // int ans=INT_MIN;
        // int count=0;
        // for(int i=0;i<s.length();i++){
        //     if(mp.find(s[i])==mp.end()){
        //         mp[s[i]]=i;
        //         count++;
        //     }else{
        //         ans=max(ans,count);
        //         count=count-mp[s[i]];
        //         int j=mp[s[i]];
        //         mp.erase(s[j]);
        //         while(j--){
        //             mp.erase(s[j]);
        //         }
        //         mp[s[i]]=i;
        //     }   
        // }
        // ans=max(ans,count);
        // return ans;
        
        int N = s.size();
        int ans = 0;
        
        int i=0;
        int j=0;
        unordered_map<char,int> mpp;
        
        while(j<=N-1){
            //calcs
            mpp[s[j]]++;
            
            if(mpp.size() == j-i+1){
                //ans
                ans = max(ans, j-i+1);
               
                j++;
            }
            else{
                //map size is less 
                //it can never be map size > window 
                char ch = s[i]; // to be rem
                mpp[ch]--;
                if(mpp[ch] == 0){
                    mpp.erase(ch); // to reduce size;
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }
};