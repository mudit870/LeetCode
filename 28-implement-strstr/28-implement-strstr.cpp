class Solution {
public:
    vector<int>lpsFind(string s){
        int n=s.length();
        int j=0,i=1;
        vector<int>lps(n);
        lps[0]=0;
        for(;i<n;i++){
            if(s[j]==s[i]){
                lps[i]=j+1;
                j++;
            }else{ 
                // 0 1 2 3 4 5 6 7
                // a b c a b c a d
                // 0 0 0 1 2 3 4 0 
                while(j>0 && s[i]!=s[j]){
                    j=lps[j-1];
                } 
                if(s[i]==s[j]){
                    lps[i] = j+1;
                    j++;
                }
                else{
                    lps[i]=0;
                }
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m==0) return 0;
        if(m>n || n==0) return -1;
        
        vector<int>lps = lpsFind(needle);
        int i=0,j=0;
        int ans=-1;
        while(i<n){
            if(i<n && j<m && haystack[i]==needle[j]){
                i++;j++;
                if(j==m)return i-m;
            }else{
                if(j-1>=0)
                    j = lps[j-1];
                else {
                    j = 0;
                    i++;
                }
            }
        }
        return ans;
    }
};