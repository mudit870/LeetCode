class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size(),0);
        vector<int>right(height.size(),0);
        
        for(int i=1;i<height.size();i++){ //0 0 1 1 2
            left[i]=max(left[i-1],height[i-1]);
        }
        for(int i=height.size()-2;i>=0;i--){
            right[i]=max(right[i+1],height[i+1]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            int val=min(left[i],right[i])-height[i];
            if(val>0)
                ans+=val;
        }
        return ans;
    }
};