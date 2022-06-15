class Solution {
public:
    static bool comp(string a,string b){
        return a.size()<b.size();
    }
    bool solve(string s1,string s2){
        int i=0,j=0;
        while(i<=s1.length()-1 and j<=s2.length()-1){
            if(s1[i]!=s2[j]) j++;
            else
                i++,j++;
        }
        if(i==s1.length()) return true;
        else
            return false;
    }
    int longestStrChain(vector<string>& w) {
        sort(w.begin(),w.end(),comp);
        int temp=0;
        vector<int>arr(w.size(),1);
        for(int i=0;i<w.size();i++){
            string s=w[i];
            int cnt=1;
            for(int j=i+1;j<w.size();j++){
                if(w[j].size()==s.size()+1){
                    if(solve(s,w[j])==true){
                        // s=w[j];
                        if(arr[j]<arr[i]+1){
                            arr[j]=1+arr[i];
                            cnt=arr[j];
                        }
                    }
                }
            }
            temp=max(temp,cnt);
        }
        return temp;
    }
};