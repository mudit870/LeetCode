class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int>v(n,1);
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1]){
                v[i]=v[i-1]+1;
            }
        }
        int ans=v[n-1];
        for(int i=n-2;i>=0;i--){
            if(r[i]>r[i+1]){
                v[i]=max(v[i],v[i+1]+1);
            }
            ans+=v[i];
        }
        return ans;
    }
};



            // 5,3,2,1,4,5,1
        //     3,3,2,1,2,3,1