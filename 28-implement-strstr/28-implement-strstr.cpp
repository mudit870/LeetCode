class Solution {
public:
    
    //KMP Algorithm / Making LPS (Pi) Table
    
    vector<int> createLps(string str){
        int n = str.length();
        int j = 0, i = 0;
        // lps is the array in which lps[i] denotes the length of the longest suffix, 
        // ending at i,  that is also a prefix
        // ex : str = a a b a a b a a a
        //      lps = 0 1 0 1 2 3 4 5 2
        vector<int>lps(n,0);
    
        for(i =1 ;i<n;i++){
            if(str[i]==str[j]){
                lps[i] = j+1;
                j++;
            }
            else{
                
                while(j>0 and str[i]!=str[j]){
                    j = lps[j-1];
                }
                // if there is match then assign lps
                if(str[i]==str[j]){
                    lps[i] = j+1;
                    j++;
                }
                // if j becomes 0, and not a match  then lps[i] = 0
                else lps[i] = 0;
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        // corner cases
        if(m==0)return 0; 
        if(m>n or n==0)return -1 ;
        vector<int> lps = createLps(needle);
        
        int i = 0, j = 0;
       
        int loc = -1;
        while(i<n){
            // if both char are equal, increment i, j 
            if(i<n and j<m and needle[j]==haystack[i]){
                i++;
                j++;
                if(j==m){
                    loc = i - m;
                    break;
                }
            }else{
                // trying to skip checking of the prefix because its suffix matching 
                // with the prefix is already being checked upto i-1
                if(j-1>=0)
                    j = lps[j-1];
                else {
                    j = 0;
                    i++;
                }
            }
        }
        return loc;
    }
};