class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=0;i<n;i++)
        {
        //for getting the lexicographically smallest string
            ans+='a';
        }
        k=k-n;
        int j=n-1;
        while(k!=0 && j>=0)
        {
//            as we have added a now when ever we replace a we need to add an extra 1 as a=1
            k=k+1;
            
            int m=k%26;
            int p=k/26;
//             if element have k>26 than we can add a z in the end replacing it by a
            if(p>=1)
            {
                ans[j]='z';
                k=k-26;
                
            }
//             if j<26 now we cn hust replace it by one char 
            else{
                cout<<m<<" ";
                ans[j]=char(m+97-1);
                k=k-m;
            }
            j--;
            
        }
        
        return ans;
    }
};